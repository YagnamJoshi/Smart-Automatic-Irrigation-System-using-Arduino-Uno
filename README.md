# Smart Automatic Irrigation System using Arduino Uno

## Overview

This project is a smart irrigation system built using an Arduino Uno. It continuously monitors soil moisture levels and automatically activates a water pump whenever the soil becomes too dry. A 1.3-inch SH1106 OLED display provides real-time information such as moisture percentage, raw sensor values, and pump status.

The system helps automate plant watering, reduce water wastage, and maintain optimal soil moisture with minimal human intervention.

---

## Features

* Automatic plant watering based on soil moisture
* Real-time soil moisture monitoring
* OLED display for system status
* Relay-controlled water pump
* Moisture percentage calculation
* Adjustable moisture thresholds
* Low-cost and beginner-friendly project

---

## Components Used

| Component                    | Quantity    |
| ---------------------------- | ----------- |
| Arduino Uno                  | 1           |
| Soil Moisture Sensor         | 1           |
| 1-Channel Relay Module       | 1           |
| Water Pump                   | 1           |
| 1.3" SH1106 I2C OLED Display | 1           |
| External Battery for Pump    | 1           |
| Jumper Wires                 | As Required |
| Breadboard (Optional)        | 1           |

---

## Circuit Connections

### OLED Display (SH1106)

| OLED Pin | Arduino Uno |
| -------- | ----------- |
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

### Soil Moisture Sensor

| Sensor Pin | Arduino Uno |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| AO         | A0          |

### Relay Module

| Relay Pin | Arduino Uno |
| --------- | ----------- |
| VCC       | 5V          |
| GND       | GND         |
| IN        | D7          |

### Pump Circuit

Battery (+) → Relay COM

Relay NO → Pump (+)

Pump (-) → Battery (-)

---

## Working Principle

1. The soil moisture sensor continuously reads soil moisture values.
2. The Arduino converts sensor readings into moisture percentages.
3. When moisture falls below a predefined threshold, the relay activates the water pump.
4. The pump waters the plant until the moisture level reaches the desired range.
5. The OLED display shows:

   * Moisture Percentage
   * Raw Sensor Value
   * Pump Status (ON/OFF)

---

## Libraries Required

Install the following libraries using the Arduino Library Manager:

* Adafruit GFX Library
* Adafruit SH110X Library
* Wire (built-in)

---

## Future Improvements

* Mobile app integration using ESP8266/ESP32
* Blynk dashboard support
* Water tank level monitoring
* Weather-based irrigation scheduling
* Data logging and analytics
* Solar-powered operation

---

## Applications

* Home gardening
* Smart agriculture
* Indoor plant care
* Greenhouses
* Educational IoT projects

---

## Author

Developed as an Arduino-based IoT and automation project for smart plant watering and irrigation management.
