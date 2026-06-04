Small embedded prototype for condition monitoring.

The idea is simple: read a sensor value, filter it a little, compare it against limits, assign a status, and print a telemetry payload.

This is not production code. It is only a basic example to show the logic I would normally start with before adapting it to real hardware.

## Why I made this

I have worked with IoT, wireless modules, embedded devices, sensors, and industrial applications for many years, but most of my current work is more on the operations, customer, and business side.

This repo is just a clean technical sample to show that I can still read, structure, and write embedded logic when needed.

## What it does

- Simulates a sensor reading
- Applies a basic low pass filter
- Checks warning and critical thresholds
- Defines the device status as NORMAL, WARNING, or CRITICAL
- Prints a simple JSON-like telemetry message through serial

## Possible real use cases

- Current monitoring
- Temperature monitoring
- Vibration monitoring
- Motor condition monitoring
- Remote equipment supervision
- Edge device alarm logic

## Files

src/condition_monitor.ino  
Main Arduino-style example.

docs/architecture.md  
Short notes about the basic architecture.

examples/sample_payload.json  
Example of the kind of telemetry payload the device could send.

## Notes

The sensor data is simulated.

In a real project, this would need to be adapted to the actual sensor, ADC, communication method, power requirements, calibration, and safety conditions.

No customer code or confidential information is included.examples/
  sample_payload.json
