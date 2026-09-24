#include <Arduino.h>
#include <WiFi.h>
#include "State.h"
#include "config.h"
#include "Peripherals.h"
#include "Network.h"
#include "Telemetry.h"
#include "model.h"
#include "edge_ai.h"
#include "optimization.h"
#include "rpc.h"
#include "attributes.h"


void setup()
{
// initiize serial monitor
    Serial.begin(115200);
    dht.begin();  // initialise sesnor
    // coig periphera
    //
    configTime(0,0,"pool.ntp.org", "time.nist.gov");
    pinMode(BTN_PLUGIN,INPUT_PULLUP);
    pinMode(BTN_PLUGOUT,INPUT_PULLUP);
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(LED_GREEN,OUTPUT);
    pinMode(LED_RED,OUTPUT);
    pinMode(LED_YELLOW,OUTPUT);

    //connect board to wii
    connectWiFi();
     // Configure MQTT server
    mqtt.setServer(MQTT_SERVER, MQTT_PORT);//MQTT SERVER D O THINGS ANDD PORT NUMBER
    //set call back function upon receving data from the cloud
    mqtt.setCallback(mqttCallback);
    mqtt.setBufferSize(512);
    connectMQTT();//TOKEB,DEVICE ID
}

unsigned long now;
unsigned long last_print;

void loop()
{
    //listenn to incoming request
    mqtt.loop();
    //print vals every 5 sec
    now = millis();
    if((now - last_print) > 5000)
    {
        last_print = now;
         //READ DATA FROM SENSOR
         sample_sensor();
         //PUBLISH THE DATA
         runEdgeAIInference();
         //design load based on predictions
         if (manualOverrideActive == 0)
         {
           runOptimization();
         }
         //publish the data 
         publishTelemetry();

         
    }
    plug_status();
    updateLeds();    
}

