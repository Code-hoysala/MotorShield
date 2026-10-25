#include "MotorShield.h"

DCMotor::DCMotor(uint8_t motorNum) {
    _motorNum = motorNum;

    // Map standard L293D motor shield pinout (utilizing Arduino PWM & Shift Register / Direct pins)
    // Standard Arduino L293D shield pin mapping:
    switch (_motorNum) {
        case 1:
            _pwmPin = 11;
            _in1Pin = 2; // Controlled via internal logic or direct pins depending on shield layout
            _in2Pin = 3;
            break;
        case 2:
            _pwmPin = 3;
            _in1Pin = 4;
            _in2Pin = 5;
            break;
        case 3:
            _pwmPin = 5;
            _in1Pin = 6;
            _in2Pin = 7;
            break;
        case 4:
            _pwmPin = 6;
            _in1Pin = 8;
            _in2Pin = 9;
            break;
        default:
            _pwmPin = 11;
            _in1Pin = 2;
            _in2Pin = 3;
            break;
    }
}

void DCMotor::begin() {
    pinMode(_pwmPin, OUTPUT);
    pinMode(_in1Pin, OUTPUT);
    pinMode(_in2Pin, OUTPUT);
    run(RELEASE);
}

void DCMotor::setSpeed(uint8_t speed) {
    analogWrite(_pwmPin, speed);
}

void DCMotor::run(MotorDirection dir) {
    switch (dir) {
        case FORWARD:
            digitalWrite(_in1Pin, HIGH);
            digitalWrite(_in2Pin, LOW);
            break;
        case BACKWARD:
            digitalWrite(_in1Pin, LOW);
            digitalWrite(_in2Pin, HIGH);
            break;
        case RELEASE:
            digitalWrite(_in1Pin, LOW);
            digitalWrite(_in2Pin, LOW);
            break;
    }
}
