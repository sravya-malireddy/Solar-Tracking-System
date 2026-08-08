#include "motor.h"

static void motor_left(void)
{
}

static void motor_right(void)
{
}

static void motor_stop(void)
{
}

void Motor_Init(void)
{
    motor_stop();
}

void Motor_Run(MotorDirection direction)
{
    switch (direction)
    {
        case MOTOR_LEFT:
            motor_left();
            break;

        case MOTOR_RIGHT:
            motor_right();
            break;

        default:
            motor_stop();
            break;
    }
}
