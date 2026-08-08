#include "control.h"

MotorDirection Control_GetDirection(const SensorData *data)
{
    int difference;

    if (data == 0)
    {
        return MOTOR_STOP;
    }

    difference = data->left - data->right;

    if (difference > TRACKING_THRESHOLD)
    {
        return MOTOR_LEFT;
    }

    if (difference < -TRACKING_THRESHOLD)
    {
        return MOTOR_RIGHT;
    }

    return MOTOR_STOP;
}
