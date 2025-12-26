# ESP32-DS18B20-OLED-Thermometer
An ESP32-based digital thermometer using the DS18B20 temperature sensor and SSD1306 OLED display, featuring real-time temperature measurement via OneWire and I2C protocols.

# ESP32 Digital Thermometer with OLED Display

## Overview
This project implements a digital thermometer using an ESP32 microcontroller and a DS18B20 digital temperature sensor. The measured temperature is displayed in real time on a 0.96" SSD1306 OLED display via I2C communication.

The project demonstrates reliable sensor interfacing, digital communication protocols, and clean embedded system design.

---

## Hardware Components
- ESP32 Development Board
- DS18B20 Digital Temperature Sensor (3-pin)
- SSD1306 OLED Display (0.96", I2C)
- 4.7kΩ Pull-up Resistor (for DS18B20 data line)
- Breadboard
- Jumper Wires

---

## Wiring Connections

### DS18B20
- VCC → 3.3V (ESP32)
- GND → GND
- DATA → GPIO 4
- 4.7kΩ resistor between DATA and VCC

### OLED SSD1306 (I2C)
- VCC → 3.3V
- GND → GND
- SCK (SCL) → GPIO 22
- SDA → GPIO 21

---

## Software Libraries
The following Arduino libraries are required:
- OneWire
- DallasTemperature
- Adafruit GFX Library
- Adafruit SSD1306

Install them via *Arduino IDE → Library Manager*.

---

## How It Works
1. The DS18B20 sensor measures ambient temperature using the OneWire protocol.
2. The ESP32 reads and processes the temperature data.
3. The temperature value is displayed on the OLED screen in Celsius.
4. The system updates continuously in real time.

Small temperature fluctuations (e.g., ±0.1°C) are expected and normal due to sensor resolution and environmental noise.

---

## Demo
A short demonstration video showing real-time temperature measurement:

▶ media/demo_temperature_oled.mp4

---

## Circuit Diagram
The full circuit schematic is available below:

![Circuit Diagram](diagrams/circuit_diagram.png)

---

## Applications
- Digital thermometer
- Environmental monitoring
- IoT sensor nodes
- Embedded systems learning project

---

## License
This project is released under the MIT License.
