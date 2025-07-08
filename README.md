# ADC-Based Robot (Analog to Digital Conversion)

This robot utilizes various sensors to detect obstacles, black lines, and cliffs (caves), while also enabling dynamic speed control using a potentiometer. The ATmega16 microcontroller's built-in Analog-to-Digital Converter (ADC) is used to interpret real-world analog input values for intelligent robot behavior.

---

## 🚀 Working Principle

This robot is designed to:
- **Avoid obstacles** using a front-facing IR sensor.
- **Detect cliff edges (caves)** using a top-facing sensor.
- **Follow or detect a black line** using two downward-facing IR sensors.
- **Control motor speed dynamically** via a user-adjustable trimpot (potentiometer).

---

## 🔌 Sensor & Motor Connections

| Component                     | Pin on ATmega16 | Port | Direction       |
|------------------------------|-----------------|------|-----------------|
| Top Sensor (Cliff Detection) | PD3             | D    | Input           |
| Front Sensor (Obstacle)      | PD2             | D    | Input           |
| Left Line Sensor             | PD1             | D    | Input           |
| Right Line Sensor            | PD0             | D    | Input           |
| Potentiometer (Speed Input)  | PA0 (ADC0)      | A    | Analog Input    |
| Buzzer Output 1              | PC0             | C    | Output          |
| Buzzer Output 2              | PC1             | C    | Output          |
| Right Motor Output 1         | PB0             | B    | Output          |
| Right Motor Output 2         | PB1             | B    | Output          |
| Left Motor Output 1          | PB2             | B    | Output          |
| Left Motor Output 2          | PB3             | B    | Output          |

---

## 🎛️ Speed Control with ADC

The robot uses a **trimpot (potentiometer)** to allow the user to control motor speed. This analog voltage is read by the ADC module of ATmega16.

### 🔍 How ADC Works in ATmega16

The Analog-to-Digital Conversion (ADC) process involves:
1. **Sampling** – Captures the analog input at a moment in time.
2. **Quantization** – Approximates the sampled signal into discrete steps.
3. **Encoding** – Converts the quantized value into a digital binary format.

### ⚙️ ATmega16 ADC Features

- **Resolution:** 10-bit (values from 0 to 1023)
- **Voltage Range:** 0V to Vcc
- **8 Analog Channels (ADC0–ADC7)** – but processes only **one at a time**
- **Key Registers:**
  - `ADMUX` – Multiplexer for selecting input channel
  - `ADCSRA` – Control and Status register
  - `ADCH` / `ADCL` – 10-bit ADC Data registers

> For speed control, the robot reads the voltage from the trimpot on **ADC0 (PA0)** and adjusts PWM signals to control motor speed.

---

## 🛠️ Components Used

- **ATmega16 Microcontroller**
- **L293D Motor Driver IC**
- **IR Sensors** – 4 units (Top, Front, Left, Right)
- **Trimpot (Potentiometer)** – 1 unit
- **12V DC Motors** – 2 units
- **Robot Chassis**
- **Buzzer**
- **Power Supply (Battery pack)**

---

