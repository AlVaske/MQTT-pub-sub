#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Testing");
  lcd.setCursor(0,1);
  lcd.print("Testing 1, 2, 3!");
  lcd.autoscroll();
}

void loop() {
  delay(2000);
  lcd.clear();
  delay(500);
  Serial.println("Enter message:");
  while(Serial.available() == 0) {}
  String teststr = Serial.readString();
  teststr.trim();
  int len = teststr.length();
  //for(int i = 0, j = 0; i<len; i += 16) {
    //String chunk = teststr.substring(i, min(i + 16, len));
    //if(j == 2) {
      //delay(2000);
      //lcd.clear();
      //j = 0;
    //}
  lcd.setCursor(15,1);
  for(int i = 0; i < len; i++) {
    lcd.write(teststr[i]);
    delay(200);
  }
}
