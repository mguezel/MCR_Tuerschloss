#include "lcd_module.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setupLCD() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void selectLanguage() {
    lcd.setCursor(0, 0);
    lcd.print("Select Language:");
}

void displayDefaultMessage() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Combination:");
}