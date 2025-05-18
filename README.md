# Smart Home Automation Using ATmega32

A comprehensive embedded system project for automating home lighting, fan speed control, and fire detection using the ATmega32 microcontroller.

---

## Project Overview

This project implements a smart home automation system that monitors environmental conditions to intelligently control lighting and fan speed, and detect fire hazards. The system integrates multiple sensors and actuators controlled by an ATmega32 MCU, with real-time feedback on a 16x2 LCD.

---

## Features

* **Automatic Lighting Control** using an LDR sensor with three LEDs indicating light intensity levels:

  * Intensity < 15%: All 3 LEDs ON (Red, Green, Blue)
  * 16%–50%: Red and Green LEDs ON
  * 51%–70%: Only Red LED ON
  * > 70%: All LEDs OFF

* **Automatic Fan Speed Control** based on temperature from an LM35 sensor, controlled via PWM:

  * ≥ 40°C: Fan at 100% speed
  * 35°C–39°C: Fan at 75% speed
  * 30°C–34°C: Fan at 50% speed
  * 25°C–29°C: Fan at 25% speed
  * < 25°C: Fan OFF

* **Fire Detection & Alert** via flame sensor:

  * Displays "Critical alert!" on LCD
  * Activates buzzer alarm
  * System remains in alert until fire is cleared

* **LCD Display** provides real-time updates:

  * First row: Fan status (ON/OFF)
  * Second row: Temperature and Light intensity (%)

---

## Hardware Components

| Component                 | Connection                                         |
| ------------------------- | -------------------------------------------------- |
| Microcontroller           | ATmega32 @ 16 MHz                                  |
| Light Sensor (LDR)        | ADC Channel 0 (PA0)                                |
| Temperature Sensor (LM35) | ADC Channel 1 (PA1)                                |
| LCD (16x2)                | RS: PD0, Enable: PD1, Data: PORTC (8-bit mode)     |
| Flame Sensor              | PD2                                                |
| Buzzer                    | PD3                                                |
| Motor (Fan)               | H-Bridge IN1: PB0, IN2: PB1, Enable (PWM OC0): PB3 |
| LEDs                      | Red: PB5, Green: PB6, Blue: PB7                    |

---

## Software Architecture

* **ADC Driver**: Configured with 2.56V internal reference, prescaler F\_CPU/128.
* **PWM Driver**: Timer0 PWM for fan speed control, non-inverting mode.
* **GPIO Driver**: Controls direction and state of pins for LEDs, buzzer, sensors.
* **LCD Driver**: 8-bit mode interface to LCD for displaying system status.
* **Sensor Drivers**: Individual modules for LDR, LM35, flame sensor.
* **Actuator Drivers**: Control of LEDs, buzzer, and DC motor with PWM speed adjustment.

---

## How to Build & Upload

This project uses **PlatformIO** for building and uploading the firmware.

1. Clone the repo:

   ```bash
   git clone https://github.com/OmarAshraf118/SmartHomeAutomation.git
   cd SmartHomeAutomation
   ```
2. Build the firmware:

   ```bash
   pio run
   ```
3. Upload to ATmega32 (via your programmer):

   ```bash
   pio run --target upload
   ```


---

## Acknowledgments

Thanks to the Edges For Training Team for the project guidance and materials.

---

## License

This project is open source under the MIT License.

