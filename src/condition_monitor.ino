/*
  IoT Condition Monitoring Prototype

  Basic embedded example:
  - Simulated sensor reading
  - Simple low-pass filtering
  - Warning and critical thresholds
  - Status classification
  - Serial telemetry output

  This is not production code.
*/

enum SystemStatus {
  STATUS_NORMAL,
  STATUS_WARNING,
  STATUS_CRITICAL
};

const float WARNING_THRESHOLD = 75.0;
const float CRITICAL_THRESHOLD = 90.0;
const float FILTER_ALPHA = 0.20;

float filteredValue = 0.0;

unsigned long lastSampleTime = 0;
const unsigned long SAMPLE_INTERVAL_MS = 1000;

void setup() {
  Serial.begin(9600);
  delay(1000);

  randomSeed(analogRead(0));

  Serial.println("IoT condition monitoring prototype started");
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastSampleTime >= SAMPLE_INTERVAL_MS) {
    lastSampleTime = currentTime;

    float rawValue = readSimulatedSensor();
    filteredValue = applyLowPassFilter(rawValue, filteredValue);

    SystemStatus status = evaluateStatus(filteredValue);

    printTelemetry(rawValue, filteredValue, status);
  }
}

float readSimulatedSensor() {
  /*
    In a real project, this could be replaced by:
    - analogRead()
    - ADC from an external sensor
    - current transformer reading
    - temperature sensor
    - vibration sensor
  */

  int simulatedValue = random(50, 100);
  return (float)simulatedValue;
}

float applyLowPassFilter(float newValue, float previousValue) {
  return (FILTER_ALPHA * newValue) + ((1.0 - FILTER_ALPHA) * previousValue);
}

SystemStatus evaluateStatus(float value) {
  if (value >= CRITICAL_THRESHOLD) {
    return STATUS_CRITICAL;
  }

  if (value >= WARNING_THRESHOLD) {
    return STATUS_WARNING;
  }

  return STATUS_NORMAL;
}

const char* statusToText(SystemStatus status) {
  switch (status) {
    case STATUS_NORMAL:
      return "NORMAL";
    case STATUS_WARNING:
      return "WARNING";
    case STATUS_CRITICAL:
      return "CRITICAL";
    default:
      return "UNKNOWN";
  }
}

void printTelemetry(float rawValue, float filteredValue, SystemStatus status) {
  Serial.print("{");
  Serial.print("\"device_id\":\"edge-monitor-001\",");
  Serial.print("\"raw_value\":");
  Serial.print(rawValue);
  Serial.print(",");
  Serial.print("\"filtered_value\":");
  Serial.print(filteredValue);
  Serial.print(",");
  Serial.print("\"status\":\"");
  Serial.print(statusToText(status));
  Serial.print("\"");
  Serial.println("}");
}
