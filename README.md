# IoT-Based-Automatic-Irrigation-Control-System-Using-ESP8266-with-Soil-Moisture-Feedback
An IoT-based automatic irrigation system using ESP8266 monitors soil moisture and controls watering automatically. When the soil is dry, the system opens a servo-controlled valve and sends a Telegram alert. Once the soil becomes sufficiently moist, the valve closes automatically, reducing water wastage.

## About the Project

This project is a closed-loop automatic irrigation control system developed using an ESP8266. The system continuously monitors soil moisture and uses the measured value as feedback to control the watering process. Based on the soil condition, the ESP8266 controls a servo motor that operates the water valve. IoT connectivity is also used to send the system status to the user through Telegram.

## Main Features

* Closed-loop control based on soil moisture feedback
* Automatic watering when the soil becomes dry
* Automatic stopping when the required moisture level is reached
* Servo motor-based water valve control
* Buzzer indication
* Telegram notifications through Wi-Fi
* Real-time soil moisture monitoring

## Components Used

* ESP8266
* Soil Moisture Sensor
* Servo Motor
* Water Valve
* Buzzer
* Jumper Wires
* Power Supply

## How the System Works

The soil moisture sensor continuously measures the moisture level of the soil and sends the feedback to the ESP8266. The controller compares the sensor reading with predefined moisture thresholds. If the soil is dry, the ESP8266 opens the valve through the servo motor and watering starts. As watering increases the soil moisture, the sensor continues to provide feedback. When the soil reaches the required moisture level, the controller closes the valve.

## Output

The system provides:

* Automatic opening and closing of the water valve
* Buzzer indication during system operation
* Soil moisture and valve status through the Serial Monitor
* Telegram notifications when watering starts and stops

## Logic

```text
        Reference / Desired
        Soil Moisture Level
                │
                ▼
        ┌───────────────┐
        │   ESP8266     │
        │   Controller  │
        └───────┬───────┘
                │ Control Signal
                ▼
        ┌───────────────┐
        │ Servo Motor + │
        │  Water Valve  │
        └───────┬───────┘
                │
                ▼
             Watering
                │
                ▼
             Soil
                │
                ▼
       Soil Moisture Sensor
                │
                │ Feedback
                └──────────────► ESP8266
```

The sensor feedback allows the controller to continuously respond to changes in soil moisture. This makes the system a closed-loop control system.

## System Block Diagram

```text
                         ┌─────────────────┐
                         │ Desired Moisture│
                         │     Level       │
                         └────────┬────────┘
                                  │
                                  ▼
                         ┌─────────────────┐
                         │    ESP8266      │
                         │    Controller   │
                         └────────┬────────┘
                                  │
                                  ▼
                         ┌─────────────────┐
                         │  Servo Motor    │
                         │  + Water Valve  │
                         └────────┬────────┘
                                  │
                                  ▼
                         ┌─────────────────┐
                         │      Soil       │
                         │    / Plant      │
                         └────────┬────────┘
                                  │
                                  ▼
                         ┌─────────────────┐
                         │ Soil Moisture   │
                         │     Sensor      │
                         └────────┬────────┘
                                  │
                                  │ Feedback
                                  └──────────────► ESP8266
```

The Wi-Fi and Telegram section works as a monitoring and notification part of the system and does not form the main control loop.

## Pin / Interface Overview

| Component            | ESP8266 Pin |
| -------------------- | ----------- |
| Soil Moisture Sensor | A0          |
| Buzzer               | D1          |
| Servo Motor          | D3          |

## Project Workflow

1. The ESP8266 starts and connects to Wi-Fi.
2. The soil moisture sensor measures the current soil condition.
3. The sensor value is sent to the ESP8266 as feedback.
4. The controller compares the measured value with the defined thresholds.
5. If the soil is dry, the servo opens the water valve.
6. Watering increases the soil moisture.
7. The sensor continuously measures the changed moisture level.
8. When the soil reaches the required moisture level, the servo closes the valve.
9. Telegram notifications are sent to inform the user about the watering status.

## Project Status

**Completed Prototype**

The closed-loop irrigation control, soil moisture feedback, servo valve operation, buzzer indication, and Telegram notification features have been implemented and tested on the prototype.

## Future Improvements

* Improve moisture sensor calibration
* Add a water-level sensor
* Control multiple irrigation zones
* Add a web or mobile monitoring dashboard
* Store and visualize soil moisture data
* Improve the physical enclosure and power system

## Project Purpose

The main purpose of this project is to demonstrate a practical closed-loop control system using soil moisture as feedback. The system automatically adjusts the watering process according to the actual condition of the soil, reducing the need for manual control and helping to avoid unnecessary watering.

## Disclaimer

This project is developed as an academic prototype for learning and demonstration purposes. Sensor readings and moisture thresholds may vary depending on the soil, sensor, plant, and environment. Proper electrical and water-safety precautions should be followed during implementation.

## Author

Developed as an academic control system project using ESP8266, soil moisture feedback, servo motor control, and IoT-based Telegram communication.
