#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// 16x2 I2C LCD on address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("sketch started");

  // Initialize I2C on typical ESP32 pins and LCD
  Serial.println("Wire.begin(21,22)");
  Wire.begin(21, 22);
  delay(50);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ESP32 LCD Demo");
  lcd.setCursor(0, 1);
  lcd.print("Workshop Sample");
}

void loop() {
  // Keep showing a simple status so you can confirm the display stays active
  lcd.setCursor(0, 0);
  lcd.print("ESP32 LCD Demo   ");
  lcd.setCursor(0, 1);
  lcd.print("IP: --           ");
  delay(2000);
}