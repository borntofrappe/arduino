#define LED_1 8
#define LED_2 9
#define LED_3 10

int leds[] = {LED_1, LED_2, LED_3};
int delays[] = {2500, 500, 5000};
int index = 0;

unsigned long previousMillis = 0;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }
  digitalWrite(leds[0], 1);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > delays[index]) {
    digitalWrite(leds[index], 0);
    index = (index + 1) % 3;
    digitalWrite(leds[index], 1);

    previousMillis = currentMillis;
  }
}
