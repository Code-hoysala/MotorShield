#include <MotorShield.h>

// Initialize DC Motor on Port 1 of the shield
DCMotor motor1(MOTOR_1);

void setup() {
    motor1.begin();
    motor1.setSpeed(200); // Set speed (0 - 255)
}

void loop() {
    // Move Forward for 2 seconds
    motor1.run(FORWARD);
    delay(2000);

    // Stop for 1 second
    motor1.run(RELEASE);
    delay(1000);

    // Move Backward for 2 seconds
    motor1.run(BACKWARD);
    delay(2000);

    // Stop for 1 second
    motor1.run(RELEASE);
    delay(1000);
}
