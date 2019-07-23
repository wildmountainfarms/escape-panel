//
// Created by josh on 7/19/19.
//

#include "Encoder.h"
#include <Arduino.h>

Encoder::Encoder(int aPin, int bPin, int resetButton) : aPin(aPin), bPin(bPin) {
}
void Encoder::init() {
    pinMode(aPin, INPUT);
    pinMode(bPin, INPUT);
    if(resetButton != -1){
        pinMode(resetButton, INPUT_PULLUP);
    }
}
void Encoder::update() {
    int a = digitalRead(aPin);
    int b = digitalRead(bPin);
    if((a != lastA || b != lastB) && (lastA == 0 && a == 1)){
        position -= b * 2 - 1;
    }
    lastA = a;
    lastB = b;
}
int Encoder::getPosition() { return position; }
void Encoder::resetPosition() { position = 0; }
