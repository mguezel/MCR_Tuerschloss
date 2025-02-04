#include "led_ring.h"
Adafruit_NeoPixel ring = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setupLEDs() {
    ring.begin();
    ring.show();
}

void updateLEDProgress(int progress, int total) {
    ring.clear();
    int step = NUM_LEDS / total;
    for (int i = 0; i < progress * step; i++) {
        ring.setPixelColor(i, ring.Color(0, 0, 255));
    }
    ring.show();
}

void indicateSuccess() {
    for (int i = 0; i < NUM_LEDS; i++) {
        ring.setPixelColor(i, ring.Color(0, 255, 0));
    }
    ring.show();
    delay(1000);
    ring.clear();
    ring.show();
}

void indicateFailure() {
    for (int i = 0; i < NUM_LEDS; i++) {
        ring.setPixelColor(i, ring.Color(255, 0, 0));
    }
    ring.show();
    delay(500);
    ring.clear();
    ring.show();
}