#include "sensor.h"
#include "motor.h"
#include "control.h"

int main(void)
{
    Sensor_Init();
    Motor_Init();

    while (1)
    {
        SensorData data = Sensor_Read();

        MotorDirection direction = Control_GetDirection(&data);

        Motor_Run(direction);
    }

    return 0;
}
