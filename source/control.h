#ifndef CONTROL_H
#define CONTROL_H

#include "sensor.h"
#include "motor.h"

#define TRACKING_THRESHOLD 50

MotorDirection Control_GetDirection(const SensorData *data);

#endif
