#ifndef MOTOR_H
#define MOTOR_H

typedef enum
{
    MOTOR_STOP,
    MOTOR_LEFT,
    MOTOR_RIGHT
} MotorDirection;

void Motor_Init(void);
void Motor_Run(MotorDirection direction);

#endif
