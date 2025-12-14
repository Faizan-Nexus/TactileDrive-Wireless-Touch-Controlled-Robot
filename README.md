TactileDrive: Wireless Touch-Controlled Robot 

TactileDrive is a wireless robotics project that eliminates complex joysticks and mobile apps. Instead, it uses a custom-built physical interface with Piezo touch sensors to navigate a 4WD robot car via Bluetooth.

Table of Contents

Overview

Features

Hardware Required

Circuit & Wiring

Installation

Team

License

 Overview

This project establishes a low-latency Master-Slave Bluetooth connection between two Arduino units.

The Remote: Reads digital signals from four touch sensors.

The Robot: Receives character commands and drives DC motors accordingly.

Developed by students at Sukkur IBA University under the supervision of Dr. Ghulam Abbas Lashari.

 Features

Zero-App Control: No smartphone required; runs on independent hardware.

Low Latency: Optimized baud rates and loop delays for instant reaction.

Intuitive Mapping: Natural directional mapping (Front, Back, Left, Right).

Robust Connectivity: Auto-pairing HC-05 modules.

Hardware Required

Component

Quantity

Description

Arduino Uno

2

One for Remote, One for Robot

HC-05 Bluetooth

2

Configured as Master and Slave

Piezo/Touch Sensors

4

Digital input modules

L298N Motor Driver

1

Dual H-Bridge for motor control

DC Gear Motors

4

For 4WD Chassis

Battery Pack

1

Li-Ion (2S or 3S) for power

Chassis & Wheels

1

Robot body

Circuit & Wiring

1. Remote (Transmitter)

Bluetooth (HC-05 Master): TX $\to$ Pin 10, RX $\to$ Pin 11

Sensors: * Forward $\to$ Pin 2

Backward $\to$ Pin 3

Left $\to$ Pin 4

Right $\to$ Pin 5

2. Robot (Receiver)

Bluetooth (HC-05 Slave): TX $\to$ Pin 10, RX $\to$ Pin 11

L298N Driver:

ENA/ENB $\to$ Pins 6 & 9 (PWM)

IN1/IN2/IN3/IN4 $\to$ Pins 2, 3, 4, 5

Installation

Clone the Repo:

git clone ([https://github.com/your-username/tactile-drive.git](https://github.com/Faizan-Nexus/TactileDrive-Wireless-Touch-Controlled-Robot/edit/main/README.md))


Flash the Remote:

Open Master.ino in Arduino IDE.

Upload to the Arduino connected to the sensors.

Flash the Robot:

Open Slave.ino in Arduino IDE.

Upload to the Arduino connected to the motors.

Pairing:

Ensure your HC-05 modules are configured (Master bound to Slave address) using AT commands before running the main code.

Team

Faizan

Zohiab

Zaghum

Abdul Rehman

Supervisor: Dr. Ghulam Abbas Lashari

Sukkur IBA University - Computer Systems Engineering

📄 License

This project is licensed under the MIT License - see the LICENSE file for details.
