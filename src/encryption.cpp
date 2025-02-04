#include "encryption.h"
#include <Arduino.h>

String encrypt(String data) {
    String encrypted = "";
    for (char c : data) {
        encrypted += char(c + 3);
    }
    return encrypted;
}

String decrypt(String data) {
    String decrypted = "";
    for (char c : data) {
        decrypted += char(c - 3);
    }
    return decrypted;
}