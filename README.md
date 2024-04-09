# SkyPulseUAV

![LinkedIn](https://img.shields.io/badge/LinkedIn-blue?style=flat&logo=linkedin&logoColor=white)
![Youtube](https://img.shields.io/badge/YouTube-red?style=flat&logo=youtube&logoColor=white)
![Twitter](https://img.shields.io/badge/Twitter-blueviolet?style=flat&logo=twitter&logoColor=white)
![GitHub License](https://img.shields.io/badge/license-MIT-blue.svg)
[![Starts of SkyPulse UVA](https://img.shields.io/github/stars/Tony-Btian/SkyPulseUAV.svg?style=social&label=Star)](https://github.com/Tony-Btian/SkyPulseUAV)
[![Forks of SkyPulse UVA](https://img.shields.io/github/forks/Tony-Btian/SkyPulseUAV.svg?style=social&label=Fork)](https://github.com/Tony-Btian/SkyPulseUAV)

> SkyPulseUAV: Pioneering UAV Technology for Critical Missions


## Welcome to the SkyPulseUAV Project

SkyPulseUAV is a groundbreaking real-time embedded system project, specifically designed to enhance the capabilities of unmanned aerial vehicles (UAVs) in critical scenarios such as fire detection, earthquake rescue, and terrain exploration. Our mission is to empower UAVs with unparalleled stability and precision, making them indispensable tools in emergency response and environmental analysis.


### Project Contributors

| Name | Role |
| ---- | ---- |
| Binhan Tian |  |
| Jianliang Wu |  |
| Jiaxing Wang |  |
| Zhiyan Tong |  |
| Shilin Zhang |  |


### Project Highlights
- **Versatile Application Spectrum**: Optimized for high-stakes missions like fire detection, earthquake relief efforts, and comprehensive terrain surveys.
- **Real-Time Decision Making**: Features real-time data processing for immediate and accurate responses in dynamic environments.
- **Advanced Stability and Control**: Employs sophisticated algorithms to maintain UAV balance and manoeuvrability, even in adverse conditions.
- **Seamless Hardware Integration**: Designed for compatibility with diverse UAV platforms, enhancing their utility in various field applications.
- **Open Source Community Driven**: SkyPulseUAV thrives on collaborative innovation, inviting contributions from developers, engineers, and UAV enthusiasts worldwide.


### Be Part of the Change
We call on the global community to join us in advancing UAV technology for critical missions. Your expertise and insights are invaluable in evolving SkyPulseUAV to meet the challenges of today and tomorrow.


### Connect and Collaborate
Stay updated with our progress, engage in discussions, and explore collaboration opportunities by following our repository and joining our community.

Let's transform the landscape of emergency response and environmental analysis together with SkyPulseUAV!

# Project Development Planning
### Global
- [ ] Build up the Github warehouse & README
- [ ] Complete the basic environment development for the project by install the Rasbian OS for Raspberry Pi
- [ ] Design the Hardware and Software
- [ ] Buy electrical components for the project

### Binhan Tian
- [ ] 

### Jianliang Wu
- [ ]

# Guide
### System Deployment
#### 
[Code Document](https://shilinzhang1.github.io/)

##2. Sensors & Actuators
### 2.1 Sensors
The list of used sensors is shown in Table 2.1.
Table 2.1 Sensors Bill of Materials (BOM)
| Item | Component Name	| Part Number	| Description | Quantity | Supplier	| Notes | 
| 1	| Barometer | BMP180 | Atmospheric pressure and temperature sensor | 1 (pcs) | Chip Supplier | Altitude positioning | 
| 2 | IMU Module | MPU6050 | 3-axis gyroscope + 3-axis accelerometer | 1 (pcs) | Module Supplier | Attitude control | 
| 3	| Compass	| GY-271 | Three-axis magnetic field sensor	| 1 (pcs)	| Chip Supplier	| Heading determination | 
| 4	| Infrared Sensor	| IR-SEN | Short-range obstacle detection	| 1 (pcs)	| Sensor Supplier	| Collision avoidance | 
| 5	| Ultrasonic Sensor	| US-SEN	| Distance measurement | 1 (pcs)	| Sensor Supplier	| Accurate height control | 
| 6	| Camera	| CAM123 | Video and still image capture | 1 (pcs) | Electronics Supplier	| Visual navigation | 
Datasheet link:
The subsequent section provides a comprehensive description of the sensor.


## SkyPulseUAV Communication Protocol Overview
### Introduction
This part provides a detailed overview of the communication protocol implemented in the SkyPulseUAV, an embedded system designed for unmanned aerial vehicle (UAV) control. The protocol governs the interaction between the ground control station and the UAV's onboard control system, ensuring precise maneuvering and real-time telemetry.

### Protocol Structure
The communication protocol for the SkyPulseUAV is structured to provide a robust and error-resistant framework:
- Prefix: A byte sequence signaling the beginning of a message.
- Data: The core message containing commands or telemetry information.
- Checksum: A redundancy check value for validating the integrity of the data.

### Packet Format
Data packets sent to and from the SkyPulseUAV follow this format:
- Prefix: [0x01], designating the start of a control packet.
- Data: A variable-length section carrying the command instructions or telemetry data.
- Checksum: A byte calculated to verify data consistency.

### Command Structure
The UAV responds to a set of predefined commands, each with a unique structure:
- Command ID: A byte that uniquely identifies the type of command being sent.
- Parameters: Sequences of bytes representing command arguments or settings.

### Communication Sequence
The sequence of communication over the SkyPulseUAV protocol is as follows:
- Connection Initiation: Ground control initiates the session by sending a request to the UAV's IP and port.
- Handshake: The UAV acknowledges the ground control's request, confirming a secure link.
- Data Exchange: Ground control dispatches structured packets containing control commands, while the UAV sends back telemetry data.
- Acknowledgment and Validation: Each packet received is acknowledged, and its integrity is verified through the checksum.
- Error Correction: Packets failing the integrity check trigger a retransmission request.
- Session Closure: The session can be safely terminated by a specific command sequence, after which the UAV disengages communication.

### Error Handling
The SkyPulseUAV protocol incorporates error handling protocols to address issues such as signal interference, packet loss, and data corruption. Automatic retransmission and robust security measures are in place to ensure reliable operation.

### Conclusion
The communication protocol is a cornerstone of the SkyPulseUAV's operational integrity, facilitating a secure and reliable interface for UAV control and telemetry feedback. This protocol is instrumental in maintaining the UAV's performance and safety standards in various flight conditions.


## License
MIT License Copyright (c) 2024 Binhan Tian
