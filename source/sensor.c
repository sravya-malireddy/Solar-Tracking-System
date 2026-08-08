#include "sensor.h"

static int read_left_sensor(void)
{
    return 0;
}

static int read_right_sensor(void)
{
    return 0;
}

void Sensor_Init(void)
{
}

SensorData Sensor_Read(void)
{
    SensorData data;

    data.left = read_left_sensor();
    data.right = read_right_sensor();

    return data;
}
