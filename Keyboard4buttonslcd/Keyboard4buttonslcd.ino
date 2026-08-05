#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int charcount = 0;
int line_num = 0;

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    Serial.begin(9600);
    pinMode(2, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
}

void loop() {
    if (charcount == 16 && line_num == 0) {
        lcd.setCursor(0, 1);
        charcount = 0;
        line_num = 1;
    } 
    else if (charcount == 16 && line_num == 1) {
        lcd.clear();
        lcd.setCursor(0, 0); 
        charcount = 0;
        line_num = 0;      
    }
    if (digitalRead(2) == LOW && digitalRead(4) == LOW && digitalRead(7) == LOW && digitalRead(8) == LOW) {
        charcount = 16;
    }
    else if (digitalRead(2) == LOW) {
        lcd.print("1");
        charcount++;
        delay(250);
    }
    else if (digitalRead(4) == LOW) {
        lcd.print("2");
        charcount++;
        delay(250);
    }
    else if (digitalRead(7) == LOW) {
        lcd.print("3");
        charcount++;
        delay(250);
    }
    else if (digitalRead(8) == LOW) {
        lcd.print("4");
        charcount++;
        delay(250);
    }
    delay(10);
}