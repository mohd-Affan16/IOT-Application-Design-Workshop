#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int TRIG_PIN = 26;
const int ECHO_PIN = 25;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // timeout 30ms
  float distanceCm = (duration * 0.0343) / 2.0;

  if (duration == 0) {
    Serial.println("Out of range");
    lcd.setCursor(0, 0);
    lcd.print("Out of range     ");
  } else {
    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");

    lcd.setCursor(0, 0);
    lcd.print("Distance:");
    lcd.print(distanceCm, 1);
    lcd.print(" cm ");
  }

  delay(200);
}