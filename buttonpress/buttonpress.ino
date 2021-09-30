# define LED 8
# define BUTTON 12

bool isPressed = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  int value = digitalRead(BUTTON);
  if (value == 1) {
    if (!isPressed) {
      isPressed = true;

      int state = digitalRead(LED);
      if (state == 1) digitalWrite(LED, 0);
      else digitalWrite(LED, 1);
    }
  }
  else {
    isPressed = false;
  }
}
