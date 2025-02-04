#include "keypad_module.h"
#include <Arduino.h>

char getKey() {
    delay(500);
    char keys[] = {'1', '2', '3', '4', '5', '*', '#'};
    return keys[random(0, sizeof(keys))];
}

void handleKeypadInput(char key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);
}