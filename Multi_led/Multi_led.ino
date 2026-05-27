const int ledPins[] = {2, 4, 5};
const int ledCount = 3;

void setup() {
  for (int index = 0; index < ledCount; index++) {
    pinMode(ledPins[index], OUTPUT);
  }
}

void loop() {
  for (int index = 0; index < ledCount; index++) {
    digitalWrite(ledPins[index], HIGH);
    delay(200);
    digitalWrite(ledPins[index], LOW);
  }

  delay(500);

  for (int index = ledCount - 1; index >= 0; index--) {
    digitalWrite(ledPins[index], HIGH);
    delay(200);
    digitalWrite(ledPins[index], LOW);
  }

  delay(500);
}