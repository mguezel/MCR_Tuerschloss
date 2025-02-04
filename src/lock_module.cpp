#include "lock_module.h"
#include "lcd_module.h"
#include "keypad_module.h"
#include "led_ring.h"
#include "encryption.h"
#include <EEPROM.h>

#define EEPROM_SIZE 64

extern LiquidCrystal_I2C lcd;

String currentCombination = "1234";

void setupLock() {
    EEPROM.begin(EEPROM_SIZE);
    if (EEPROM.readString(0).length() > 0) {
        currentCombination = EEPROM.readString(0);
    }
}

void changeCombination() {
    lcd.clear();
    lcd.print("Enter new comb:");
    String newCombination = "";
    char key;

    while (true) {
        key = getKey();
        if (key == '#') {
            if (newCombination.length() > 0 && newCombination.length() <= 6) {
                currentCombination = newCombination;
                EEPROM.writeString(0, encrypt(currentCombination));
                EEPROM.commit();
                lcd.clear();
                lcd.print("Updated!");
                delay(2000);
                displayDefaultMessage();
                return;
            }
        } else if (key == '*') {
            displayDefaultMessage();
            return;
        } else if (newCombination.length() < 6) {
            newCombination += key;
            updateLEDProgress(newCombination.length(), 4);
        }
    }
}