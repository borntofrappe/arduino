#define PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(PIN);
  float voltage = value / 1024.0 * 5.0;
  float temperature = (voltage - 0.5) * 100.0;

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C°");
  delay(1000);
}
