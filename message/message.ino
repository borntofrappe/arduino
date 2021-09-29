int i = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Booting up");
}

void loop() {
  Serial.print("Loop #");
  Serial.println(i);
  i++;

  delay(1000);
}