#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.print("I LOVE U");
    lcd.setCursor(0, 1);
    lcd.print("Ma");
}

void loop() {
    
}