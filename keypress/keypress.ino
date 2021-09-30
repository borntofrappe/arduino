#define LED_1 8
#define LED_2 9
#define LED_3 10

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int pin = Serial.readStringUntil("\n").toInt();

    switch (pin) {
      case LED_1:
      case LED_2:
      case LED_3:
        Serial.print("Selected pin #");
        Serial.println(pin);

        digitalWrite(LED_1, 0);
        digitalWrite(LED_2, 0);
        digitalWrite(LED_3, 0);

        digitalWrite(pin, 1);

        break;
      default:
        Serial.println("Invalid pin");
    }
  }
}
