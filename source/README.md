# Solar Tracking System - Embedded C Source

This directory contains a reference Embedded C implementation of the control logic for the Automatic Solar Tracking System.

The implementation follows the documented system architecture:

Light Sensors → Controller → Motor Driver → DC Geared Motor → Solar Panel

## Source Structure

source/
├── main.c
├── sensor.c
├── sensor.h
├── motor.c
├── motor.h
├── control.c
├── control.h
└── README.md

Modules
main.c

Coordinates the main control loop.

It:

Initializes the sensors.
Initializes the motor.
Reads the sensor values.
Determines the required motor direction.
Updates the motor continuously.
sensor.c / sensor.h

Provides the sensor interface.

Two light-sensor readings are represented:

Left sensor
Right sensor

The sensor abstraction can be connected to ADC channels of the target microcontroller.

control.c / control.h

Contains the tracking decision logic.

The controller compares the left and right light intensities.

Left > Right
     ↓
 Move Left

Right > Left
     ↓
 Move Right

Difference within threshold
     ↓
 Stop

A small threshold is used to prevent unnecessary motor movement when the two sensor readings are close.

motor.c / motor.h

Provides the motor-control abstraction.

The motor can be commanded to:

Move left
Move right
Stop

The functions can be mapped to the input pins of an L293D motor-driver circuit.

Hardware Interface

The source is intentionally written as a hardware-independent Embedded C reference implementation.

The following functions are hardware abstraction points:

read_left_sensor()
read_right_sensor()
motor_left()
motor_right()
motor_stop()

These functions should be implemented according to the selected microcontroller, ADC configuration, GPIO configuration and motor-driver connections.

Control Flow
          Start
            |
            v
      Initialize System
            |
            v
      Read Light Sensors
            |
            v
      Compare Readings
         /       \
        /         \
   Left > Right   Right > Left
       |              |
       v              v
   Move Left      Move Right
        \            /
         \          /
          \        /
           v      v
            Stop
              |
              v
        Repeat Control Loop
