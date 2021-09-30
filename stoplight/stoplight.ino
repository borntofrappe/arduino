#define LED_RED 8
#define LED_YELLOW 9
#define LED_GREEN 10
#define BUZZER 11

#define BUTTON 12

int leds[] = {LED_GREEN, LED_YELLOW, LED_RED};
int delays[] = {2000, 2500, 5000};
int index = -1;

unsigned long previousMillis = 0;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(BUZZER, OUTPUT);

  pinMode(BUTTON, INPUT);

  digitalWrite(leds[0], 1);
}

void loop() {
  if (index != -1) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis > delays[index]) {
      digitalWrite(leds[index], 0);
      index = (index + 1) % 3;
      digitalWrite(leds[index], 1);

      if (index == 1) digitalWrite(BUZZER, 1);
      else digitalWrite(BUZZER, 0);

      if (index == 0) index = -1;
      else previousMillis = currentMillis;
    }
  }
  else {
    int value = digitalRead(BUTTON);
    if (value == 1) {
      index = 0;
      previousMillis = millis();
    }
  }

}
