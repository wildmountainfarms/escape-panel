#include <Arduino.h>
#include "User_Setup.h"

bool isPowered = false;

bool isPowerFlowing(){
    return digitalRead(7) == 0;
}

void setup() {
    pinMode(7, INPUT_PULLUP); // when connected to ground, digitalRead will be 0
    Serial.begin(9600);
}

void loop() {
    if(!isPowered){
        if(isPowerFlowing()){
            delay(500);
            if(isPowerFlowing()){
                isPowered = true;
            }
        }
    } else {

    }
    Serial.println(digitalRead(7));
    delay(500);
}
