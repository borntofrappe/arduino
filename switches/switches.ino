#define LED_1 8
#define LED_2 9
#define LED_3 10
#define BUZZER 11

int pin = 0;

void updatePin();

void setup() {
  pin = LED_1;

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  digitalWrite(LED_1, 0);
  digitalWrite(LED_2, 0);
  digitalWrite(LED_3, 0);
  digitalWrite(BUZZER, 0);

  digitalWrite(pin, 1);
  updatePin();

  delay(1000);
}


void updatePin() {
  switch (pin) {
    case LED_1:
      pin = LED_2;
      break;
    case LED_2:
      pin = LED_3;
      break;
    case LED_3:
      pin = BUZZER;
      break;
    default:
      pin = LED_1;
  }
}
