
# YAZ – Smart Diabetes Management Device
<p align="center">
<img width="200" height="200" alt="Premiumes schwarzes YAZ-Gerät mit Display" src="https://github.com/user-attachments/assets/a40e0eb4-8dca-4ea4-aa85-678d0bc0bcee" />
  <img width="180" height="200" alt="1740067317500" src="https://github.com/user-attachments/assets/12346eea-e90f-4f7e-a683-303e242187d3" />
</p>
## Overview

YAZ is a smart diabetes management companion designed to help people with diabetes monitor their insulin pens, keep track of their injections, and maintain better control over their daily routine.

The device combines embedded systems, sensor technology, and mobile application development to provide an intuitive and practical solution for everyday diabetes management.

## Key Features

- **Injection Tracking:** Automatically tracks the number of injections taken and the remaining injections for each pen.
- **Temperature Monitoring:** Monitors insulin pen storage temperature and provides an alert when the temperature exceeds a defined threshold (30°C).
- **Injection History:** Displays the time elapsed since the last recorded injection.
- **Smart Pen Detection:** Uses integrated sensors to detect pen removal and insertion.
- **Mobile Application:** Connects to the device via Bluetooth Low Energy (BLE) to provide notifications and additional information.
- **Real-Time Display:** Features a round display showing temperature, battery status, injection statistics, and device information.

## Hardware & Technologies

- ESP32 microcontroller
- Embedded C/C++
- Bluetooth Low Energy (BLE)
- Hall-effect sensors
- Contact sensors
- Temperature sensing
- Round display interface
- 3D-printed enclosure

## Software Development

The firmware handles sensor data acquisition, pen detection, injection tracking, temperature monitoring, and communication with the mobile application.

A dedicated mobile application provides a user-friendly interface for accessing device information and receiving notifications.

## Project Scope

YAZ was developed as an integrated hardware and software project, covering:

- Electronic hardware design and integration
- Embedded firmware development
- Sensor integration and data processing
- Bluetooth communication
- Mobile application development
- 3D enclosure design and prototyping
- User interface design

## Project Status

Functional prototype developed. Hardware, embedded firmware, and mobile application integrated.

## Disclaimer

YAZ is a diabetes management companion prototype. It does not administer insulin, determine insulin dosages, or replace professional medical advice or existing medical devices.
