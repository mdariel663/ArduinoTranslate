// StepperStub.h
#ifndef STEPPER_STUB_H
#define STEPPER_STUB_H

class Stepper {
public:
    Stepper(int steps, int pin1, int pin2);
    void setSpeed(long rpm);
    void step(int steps);
};

#endif // STEPPER_STUB_H
