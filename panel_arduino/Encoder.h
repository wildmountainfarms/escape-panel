//
// Created by josh on 7/19/19.
//

#ifndef PANEL_ARDUINO_ENCODER_H
#define PANEL_ARDUINO_ENCODER_H


class Encoder {
private:
    const int aPin;
    const int bPin;
    int position = 0;
    int lastA = 0;
    int lastB = 0;
public:
    /**
     *
     * @param aPin The DT pin
     * @param bPin The CLK pin
     */
    Encoder(int aPin, int bPin);
    void init();
    void update();
    int getPosition();
    void resetPosition();
};


#endif //PANEL_ARDUINO_ENCODER_H
