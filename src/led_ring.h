#ifndef LED_RING_H
#define LED_RING_H

#include <Adafruit_NeoPixel.h>

#define LED_PIN 5
#define NUM_LEDS 12

void setupLEDs();
void updateLEDProgress(int progress, int total);
void indicateSuccess();
void indicateFailure();

#endif