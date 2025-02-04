#include "lcd_module.h"
#include "keypad_module.h"
#include "lock_module.h"
#include "encryption.h"
#include "led_ring.h"
#include "config.h"

void setup() {
    Serial.begin(115200);
    setupLCD();
    selectLanguage();
    displayDefaultMessage();
    setupLock();
    setupLEDs();
}

void loop() {
    char key = getKey();
    if (key == '*') {
        char nextKey = getKey();
        if (nextKey == '#') {
            changeCombination();
        }
    } else {
        handleKeypadInput(key);
    }
}