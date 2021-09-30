#define LED_1 8
#define LED_2 9
#define LED_3 10
#define BUZZER 11

#define TRIGGER 6
#define ECHO 7

#define CENTIMETERS_THRESHOLD 100.0

int switches[] = {LED_1, LED_2, LED_3, BUZZER};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(switches[i], OUTPUT);
  }

  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIGGER, 1);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, 0);

  long duration = pulseIn(ECHO, 1);

  long distance = duration / 58.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < CENTIMETERS_THRESHOLD) {
    int n = (CENTIMETERS_THRESHOLD - distance) / CENTIMETERS_THRESHOLD * 4 + 1;
    for (int i = 0; i < 4; i++) {
      if (i < n) digitalWrite(switches[i], 1);
      else digitalWrite(switches[i], 0);
    }
  } else {
    for (int i = 0; i < 4; i++) {
      digitalWrite(switches[i], 0);
    }
  }

  delay(1000);
}
