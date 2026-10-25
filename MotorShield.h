#ifndef MOTOR_SHIELD_H
#define MOTOR_SHIELD_H

#include <Arduino.h>

// Motor selection for standard L293D shield
enum DCMotorID {
    MOTOR_1 = 1,
    MOTOR_2 = 2,
    MOTOR_3 = 3,
    MOTOR_4 = 4
};

enum MotorDirection {
    FORWARD,
    BACKWARD,
    RELEASE
};

class DCMotor {
public:
    DCMotor(uint8_t motorNum);
    void begin();
    void setSpeed(uint8_t speed); // 0 to 255
    void run(MotorDirection dir);

private:
    uint8_t _motorNum;
    uint8_t _pwmPin;
    uint8_t _in1Pin;
    uint8_t _in2Pin;
};

#endif
