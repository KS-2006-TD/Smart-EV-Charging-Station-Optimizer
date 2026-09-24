# Smart EV Charging Station Optimizer

## Edge AI Based Smart EV Charging Station Optimizer

A multi-bay EV charging station simulation developed using **ESP32, Embedded C/C++, Visual Studio Code, PlatformIO, Wokwi, MQTT, and ThingsBoard**.

This project was developed as part of my **IoT Internship at Emertxe** and focuses on the simulation, monitoring, communication, and control of multiple EV charging bays using an ESP32-based IoT system.

---

## 📌 Project Overview

The project simulates a smart EV charging station consisting of **three independent charging bays — BAY1, BAY2, and BAY3**.

Each charging bay is implemented as an independent **ESP32-based PlatformIO project** and simulated using **Wokwi**.

The simulated charging parameters are sent from the ESP32 to **ThingsBoard using MQTT**, where the data is displayed through a centralized dashboard for monitoring and control.

### System Flow

```text
          ┌──────────────────────┐
          │        BAY 1         │
          │ ESP32 + Sensors      │
          │ Relay + Indicators   │
          └──────────┬───────────┘
                     │
                     │ MQTT
                     ▼
              ┌───────────────┐
              │               │
              │  ThingsBoard  │
              │   Dashboard   │
              │               │
              └───────────────┘
                     ▲
                     │ MQTT
          ┌──────────┴───────────┐
          │        BAY 2         │
          │ ESP32 + Sensors      │
          │ Relay + Indicators   │
          └──────────────────────┘

          ┌──────────────────────┐
          │        BAY 3         │
          │ ESP32 + Sensors      │
          │ Relay + Indicators   │
          └──────────┬───────────┘
                     │
                     └──── MQTT ────► ThingsBoard
```
🛠️ Technologies and Tools Used
Development Environment
Visual Studio Code
PlatformIO

Visual Studio Code with the PlatformIO extension was used for ESP32 project development, Embedded C/C++ programming, project management, compilation, and firmware development.

Simulation
Wokwi Simulator

The ESP32 hardware and charging-bay circuits were simulated using Wokwi.

The Wokwi simulations were developed and tested through the Visual Studio Code + PlatformIO workflow.

Embedded System
ESP32
Embedded C/C++
IoT Communication
MQTT
JSON-based telemetry
Cloud Monitoring
ThingsBoard
🏗️ System Architecture

The project follows an Edge – Communication – Cloud architecture.

1. Edge Layer

The ESP32 acts as the controller for each charging bay.

It is responsible for:

Reading simulated sensor values
Processing charging parameters
Calculating power and energy
Managing charging-bay status
Controlling the relay
Sending telemetry data
2. Communication Layer

MQTT is used as the communication protocol between the ESP32 charging bays and ThingsBoard.

The charging bays publish telemetry data in JSON format.

3. Cloud Layer

ThingsBoard is used for:

Real-time monitoring
Telemetry visualization
Historical data visualization
Charging-bay status monitoring
Relay control
Centralized charging-station monitoring
⚡ Charging Bay Simulations

The project contains three independent charging-bay simulations.

BAY1

The first charging-bay simulation includes:

Simulated voltage input
Simulated current input
DHT22 temperature monitoring
Relay control
Status LEDs
Push-button interaction
MQTT telemetry
ThingsBoard integration
BAY2

A separate ESP32-based charging-bay simulation implementing the same smart charging-bay concept.

BAY3

A separate ESP32-based charging-bay simulation implementing the same smart charging-bay concept.

Each bay is maintained as an independent PlatformIO project.

🔌 Wokwi Simulation

The charging-bay hardware was developed as a virtual simulation using Wokwi.

The simulations include components such as:

ESP32
Potentiometers for simulated voltage and current
DHT22 temperature sensor
Relay module
Push buttons
Status LEDs

Wokwi was used to test the ESP32 firmware and circuit behavior without requiring physical EV charging hardware.

Each bay contains its corresponding Wokwi configuration.

💻 Visual Studio Code + PlatformIO

The project was developed using Visual Studio Code with the PlatformIO extension.

PlatformIO was used for:

ESP32 project creation and management
Embedded C/C++ development
Library management
Project compilation
Firmware development
Project configuration
Wokwi simulation workflow

Each charging bay contains its own platformio.ini configuration.

📊 Sensors and Charging Parameters

The simulated charging bays monitor parameters such as:

Voltage
Current
Power
Energy
Temperature
Bay status
Power Calculation

Power is calculated using:

Power = Voltage × Current

The relay is used to represent the charging ON/OFF state.

LED indicators provide a visual indication of the charging-bay status.

📡 MQTT Communication

MQTT is used to transfer telemetry from the ESP32 charging bays to ThingsBoard.

The ESP32 publishes telemetry data in JSON format.

Example Telemetry
{
  "bayId": "BAY_01",
  "voltage": 228.4,
  "current": 14.2,
  "power": 3243.3,
  "temperature": 34.5,
  "bayStatus": "CHARGING"
}

This allows charging-bay information to be transmitted and monitored through the ThingsBoard platform.

☁️ ThingsBoard Dashboard

A centralized ThingsBoard dashboard was created for monitoring the simulated charging station.

The dashboard provides information such as:

Voltage
Current
Power
Energy
Bay status
Charging information
Predicted values
Load decision information
Relay control

The dashboard provides a centralized view of the multi-bay charging station.

🤖 Edge AI and Optimization Concepts

The project also explores Edge AI and optimization concepts for smart EV charging.

The system concept supports charging-management decisions such as:

ALLOW
THROTTLE
DEFER

The Edge AI concept focuses on performing prediction close to the data source, while ThingsBoard provides centralized monitoring, visualization, and analytics.

Note: The repository distinguishes between the implemented ESP32/IoT simulation components and the broader Edge AI/optimization concepts explored as part of the project.

📸 Project Screenshots

Screenshots of the project are provided in the repository under:

docs/images/
Wokwi ESP32 Simulation

Visual Studio Code + PlatformIO

ThingsBoard Dashboard

Multi-Bay Charging Station

📁 Repository Structure
Smart-EV-Charging-Station-Optimizer/
│
├── BAY1/
│   └── esp32_blink/
│       ├── include/
│       ├── lib/
│       ├── src/
│       ├── test/
│       ├── platformio.ini
│       └── wokwi.toml
│
├── BAY2/
│   └── esp32_blink/
│       ├── include/
│       ├── lib/
│       ├── src/
│       ├── test/
│       ├── platformio.ini
│       └── wokwi.toml
│
├── BAY3/
│   └── esp32_blink/
│       ├── include/
│       ├── lib/
│       ├── src/
│       ├── test/
│       ├── platformio.ini
│       └── wokwi.toml
│
├── docs/
│   └── images/
│       ├── wokwi-simulation.png
│       ├── vscode-platformio.png
│       ├── thingsboard-dashboard.png
│       └── multi-bay-system.png
│
├── .gitignore
└── README.md
▶️ How to Run

Each charging bay can be opened and run independently as a PlatformIO project.

BAY1
BAY1/esp32_blink
BAY2
BAY2/esp32_blink
BAY3
BAY3/esp32_blink
Steps
Open the required bay project in Visual Studio Code.
Make sure the PlatformIO extension is installed.
Open the project.
Configure your own credentials locally.
Build and run the project.
Run the corresponding Wokwi simulation.
Monitor the telemetry and charging information through ThingsBoard.
🎥 Project Demo
YouTube Demo

The complete project demonstration is available on YouTube:

🔗 Smart EV Charging Station Optimizer – Project Demo

The video demonstrates the ESP32 charging-bay simulations, Wokwi simulation, ThingsBoard dashboard, charging parameters, and system control.

📚 Learning Outcomes

Through this internship project, I gained practical exposure to:

ESP32 programming
Embedded C/C++
Visual Studio Code
PlatformIO
Wokwi simulation
MQTT communication
ThingsBoard
IoT telemetry
Sensor interfacing
Relay control
Multi-bay system design
Edge AI concepts
Load monitoring
Charging optimization concepts
🔐 Security

Sensitive credentials are not included in this repository.

The following should be configured locally when running the project:

Wi-Fi credentials
ThingsBoard device access token
Other required configuration values

Never commit real passwords, API keys, access tokens, or other sensitive credentials to GitHub.

🚀 Future Scope

Possible future improvements include:

Deployment on physical hardware
Integration with real EV charging hardware
Improved Edge AI models
Advanced load balancing
Automated charging scheduling
Historical energy analytics
Larger multi-station deployment
🎓 Internship Project

This project was developed during my IoT Internship at Emertxe.

Project Title

Edge AI Based Smart EV Charging Station Optimizer

Internship Area

IoT | Embedded Systems | ESP32 | MQTT | ThingsBoard | Edge AI Concepts

👨‍💻 Author

Kiran Sai Panguluri
