# Automated Hand Sanitizer Dispenser
## Project Overview
This project is a **university group project** completed by a team of 4 members within a 1-week timeframe as part of the **Sensors and Metrology course**.  

The objective was to design and implement a simple **Automated Hand Sanitizer**.

> A touchless hand sanitizer dispenser system using ultrasonic sensing and servo actuation
<img width="390" height="644" alt="image" src="https://github.com/user-attachments/assets/f87ec34e-63df-465e-8bbf-c18343c9a276" />

<img width="392" height="641" alt="image" src="https://github.com/user-attachments/assets/a4b9c975-8fe5-4a8d-a431-198e032d98f3" />


##  Features

- **Touchless Operation**: Detects hands within 20cm range using ultrasonic sensing
- **Cooldown System**: 1.5-second lockout prevents multiple unintended activations
- **Reliable Actuation**: High-torque servo motor ensures consistent pump pressing
- **Real-time Monitoring**: Serial output displays distance readings for debugging
- **Custom Housing**: Fully wooden enclosure designed to accommodate all components
- **Low Power**: Operates on standard 5V USB power supply




##  Hardware Components

| Component | Model | Specifications | Purpose |
|-----------|-------|----------------|---------|
| **Microcontroller** | Arduino Uno | ATmega328P, 16MHz | Main control unit |
| **Distance Sensor** | HC-SR04 | Range: 2-400cm, Accuracy: ±1cm | Hand detection |
| **Servo Motor** | MG996R | Torque: 11 kg·cm @ 6V, 180° rotation | Pump actuation |
| **Housing** | Custom Wood Frame | - | Structural support |
| **Power Supply** | USB 5V | - | System power |




## Component Justification and Mechanical Design

**HC-SR04 Ultrasonic Sensor**
- Detection range (2-400cm) perfectly suited for hand-distance sensing
- High resolution (~3mm) enables precise triggering
- Cost-effective and widely available
- Fast response time for real-time user interaction

**MG996R Servo Motor**
- Sufficient torque (11 kg·cm) to reliably press sanitizer pump mechanisms
- Metal gears provide improved durability and positional accuracy
- Standard PWM control simplifies Arduino integration
- 180° rotation range accommodates various pump designs

**Housing Construction:**
- **Material**: Wood panels (front, sides, top)
- **Features**:
  - Front panel cutouts for sensor visibility
  - Servo mounting bracket above pump
  - Cable management routing

**Assembly Considerations:**
- Servo horn must be centered before lever arm attachment
- Wiring secured to prevent disconnection during servo motion
- Bottle positioned for reliable pump head contact
<img width="453" height="660" alt="image" src="https://github.com/user-attachments/assets/9e48ff08-6c45-4eee-94f4-f9e0a525ae8c" />

<img width="372" height="641" alt="image" src="https://github.com/user-attachments/assets/34f17535-2250-4129-a19f-978d218d0768" />







## Circuit Connections

| Component | Arduino Pin |
|-----------|-------------|
| HC-SR04 TRIG | Pin 9 |
| HC-SR04 ECHO | Pin 10 |
| MG996R Signal | Pin 6 (PWM) |
| Power (5V) | 5V Rail |
| Ground | GND |

<img width="1200" height="755" alt="image" src="https://github.com/user-attachments/assets/000bbe62-f206-4245-962a-815e77c97949" />
<img width="981" height="515" alt="image" src="https://github.com/user-attachments/assets/8abf2386-1678-45fc-bda2-1aa5597b1cb1" />




## Sensor Characteristics

**HC-SR04 Performance Metrics:**
- **Sensitivity**: 0.3 cm minimum detectable change
- **Resolution**: ~3 mm
- **Accuracy**: ±1 cm under typical indoor conditions
- **Detection Range**: 2-400 cm (configured for 0-20 cm)

**MG996R Servo Specifications:**
- **Rotation Range**: 180° (0° rest, 90° press)
- **Speed**: ~0.17-0.19 seconds per 60°
- **Operating Voltage**: 4.8-6V
- **Torque**: 9.4 kg·cm @ 4.8V, 11 kg·cm @ 6V
- **Control**: Standard PWM (1-2ms pulse width)




## Code Architecture

The firmware utilizes the **NewPing library** for enhanced ultrasonic sensing performance:

- **Distance Measurement**: `sonar.ping_cm()` provides direct centimeter readings
- **Hand Detection**: Threshold set at 20cm for optimal user experience
- **Lockout Timer**: `millis()`-based cooldown prevents rapid repeated activations
- **Servo Control**: Precise positioning using `Servo.h` library



**Servo Actuation Logic:**
1. Distance measurement via `sonar.ping_cm()`
2. Hand detection check (0-20 cm threshold)
3. Cooldown verification (1500ms minimum interval)
4. Servo movement: 0° → 90° → hold 400ms → return to 0°
5. Timer update to prevent immediate re-triggering



## Performance Observations

- Consistent hand detection within 5-20cm range
- Reliable servo actuation without stalling or missed activations
- No unintended double-dispensing due to lockout timer implementation
- Stable operation over extended testing periods



https://github.com/user-attachments/assets/d84366d6-7bc3-4767-b86e-53b60194b5db



## System Performance Metrics

| Metric | Value | Notes |
|--------|-------|-------|
| Detection Accuracy | ±1 cm | Within specified range |
| Response Time | <100 ms | From detection to servo start |
| Dispensing Duration | 400 ms | Optimized for pump mechanism |
| Cooldown Period | 1500 ms | Prevents accidental re-triggering |
| Detection Range | 5-20 cm | Practical hand placement zone |


## Notes
**Course:** Sensors and Metrology  
**Semester:** 3
