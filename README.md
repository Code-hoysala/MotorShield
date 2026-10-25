# MotorShield

`MotorShield` is a lightweight, modern, and non-blocking Arduino library designed for the popular **L293D Motor Driver Shield**. It provides an intuitive, clean API to control DC motors with precise PWM speed regulation and independent directional control, avoiding the heavy bloat of legacy libraries.

## Features
- **Clean API:** Simple object-oriented interface tailored for DC motors (M1, M2, M3, M4).
- **PWM Speed Control:** Smooth 8-bit speed adjustment (0–255) using hardware PWM pins.
- **Zero Memory Overhead:** Built with static allocation (`malloc`-free), making it ideal for resource-constrained microcontrollers like the Arduino Uno and Mega.

---

## Hardware Requirements
- **Arduino Board:** Arduino Uno, Mega, or compatible.
- **L293D Motor Shield:** Stacked directly onto the Arduino board.
- **Power Supply:** External power connected to the shield's external power terminal for motor actuation.

---

## Quick Start Example

```cpp
#include <MotorShield.h>

// Initialize DC Motor on Port 1 of the shield
DCMotor motor1(MOTOR_1);

void setup() {
    motor1.begin();
    motor1.setSpeed(200); // Set motor speed (0 to 255)
}

void loop() {
    // Move Forward
    motor1.run(FORWARD);
    delay(2000);

    // Stop (Release)
    motor1.run(RELEASE);
    delay(1000);

    // Move Backward
    motor1.run(BACKWARD);
    delay(2000);

    // Stop (Release)
    motor1.run(RELEASE);
    delay(1000);
}
