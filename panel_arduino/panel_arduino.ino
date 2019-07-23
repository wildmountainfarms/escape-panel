#include <Arduino.h>
#include "Encoder.h"
#include "PullUpButton.h"

bool isPowered = false;
Encoder encoder(8, 9);

bool isPowerFlowing(){
    return digitalRead(6) == 0;
}

void setup() {
    pinMode(7, INPUT_PULLUP); // when connected to ground, digitalRead will be 0
    Serial.begin(9600);
}
l
void loop() {
    encoder.update();
    if(!isPowered){
        if(isPowerFlowing()){
            delay(500);
            if(isPowerFlowing()){
                isPowered = true;
            }
        }
    } else {

    }
    Serial.println(encoder.getPosition());
}
