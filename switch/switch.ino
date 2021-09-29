#define PIN 8

int state = 0;

void setup() {
  pinMode(PIN, OUTPUT);
}

void loop() {
  digitalWrite(PIN, state);

  if (state == 0) state = 1;
  else state = 0;

  delay(1000);
}