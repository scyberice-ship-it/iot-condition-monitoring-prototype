# Architecture Notes

This is a simple edge monitoring example.

The basic flow is:

1. Read sensor value
2. Filter the signal
3. Compare against thresholds
4. Assign device status
5. Print telemetry output

## Edge logic

The edge device does a first level of decision making before sending data somewhere else.

This can help reduce unnecessary traffic and can make local alarms faster.

## Possible hardware adaptation

In a real project, the simulated sensor function could be replaced with real input from:

- Current transformer
- Analog sensor
- Temperature sensor
- Vibration sensor
- External ADC
- PLC input

## Communication options

The serial output could later be replaced by:

- MQTT
- HTTP
- BLE gateway
- LoRaWAN
- Cellular modem
- Industrial gateway

## Production notes

A real product would need more work:

- Sensor calibration
- Watchdog
- Error handling
- Configuration memory
- Secure communication
- Power management
- Hardware validation
- Safety review
