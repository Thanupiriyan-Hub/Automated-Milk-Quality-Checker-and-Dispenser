# Automated Milk Quality Checker and Dispenser

This repository contains the code and documentation for the **Automated Milk Quality Checker and Dispenser** project. The project is designed to evaluate the quality of milk using sensors and dispense it based on predefined conditions.

---

## Features
- **Milk Quality Testing:**
  - pH level detection using a pH sensor.
  - Gas concentration detection for freshness evaluation.
  - Temperature measurement using DS18B20 sensors.
- **Automated Dispensing System:**
  - Servo motor control for lid management.
  - Solenoid valves for milk flow control.
- **User Interaction:**
  - 16x2 I2C LCD for displaying instructions and test results.
  - Keypad for user input.
- **Color Detection:**
  - TCS3200 color sensor for detecting milk quality visually.
- **Buzzer Alert:**
  - Alerts for specific conditions.

---

## Hardware Components
1. **Arduino Mega 2560**
2. **pH Sensor** (Analog input on pin A1)
3. **Gas Sensor** (Analog input on pin A0)
4. **DS18B20 Temperature Sensor** (OneWire protocol on pin 45)
5. **TCS3200 Color Sensor**
6. **Servo Motor** (Lid control on pin 47)
7. **Solenoid Valves** (Relay control on pins 35, 37, and 39)
8. **Level Sensors** (Pins 33 and 34)
9. **16x2 I2C LCD Display** (I2C address: 0x27)
10. **4x4 Keypad**
11. **Buzzer** (Pin 2)

---

## Software Setup
### Libraries Required
Make sure the following Arduino libraries are installed:
1. `OneWire`
2. `DallasTemperature`
3. `Adafruit_GFX`
4. `Wire`
5. `LiquidCrystal_I2C`
6. `Keypad`

### Installation
1. Clone this repository:
   ```bash
   git clone <repository_url>
   ```
2. Open the code in the Arduino IDE.
3. Install the required libraries via the Library Manager in the Arduino IDE.
4. Upload the code to the Arduino Mega 2560.

---

## How to Use
1. Pour milk into the container as instructed on the LCD.
2. Press the **A** button on the keypad to start testing.
3. The system will evaluate the milk quality based on:
   - pH level
   - Gas concentration
   - Temperature
4. The test results will be displayed on the LCD.
5. If the milk passes the quality check, it will be dispensed. Otherwise, the system will alert the user with the buzzer.

---

## Code Overview
### Key Functions
- **Testing:** The `Testing()` function handles the entire milk quality evaluation process.
- **Sensor Reading:** Functions like `readpH()` fetch sensor data for analysis.
- **User Interaction:** LCD and keypad integration allows smooth user interaction.

### Pin Assignments
| Component         | Pin Number |
|-------------------|------------|
| pH Sensor         | A1         |
| Gas Sensor        | A0         |
| DS18B20 Sensor    | 45         |
| Servo Motor       | 47         |
| Solenoid Half IN  | 35         |
| Solenoid Half OUT | 37         |
| Solenoid Customer | 39         |
| Level Sensor      | 33         |
| Cup Level Sensor  | 34         |
| Buzzer            | 2          |
| Keypad Rows       | 10, 9, 8, 7|
| Keypad Columns    | 6, 5, 4, 3 |
| LCD I2C Address   | 0x27       |

---

## Contributors
- **Thanupiriyan**
- **Bharkkavasharama.K**

---

## License
This project is licensed under the [MIT License](LICENSE).

---

## Future Enhancements
- Add real-time cloud integration for remote monitoring.
- Implement machine learning for advanced milk quality predictions.
- Expand the system to handle multiple liquid types.

---
