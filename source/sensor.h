#ifndef SENSOR_H
#define SENSOR_H

typedef struct
{
    int left;
    int right;
} SensorData;

void Sensor_Init(void);
SensorData Sensor_Read(void);

#endif
