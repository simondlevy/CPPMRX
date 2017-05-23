#include <BreezyCPPM.h>

// Pin 11 will work on Teensy 3.X, Ladybug; Pin 3 will work on Arduino Uno
#define RXPIN 3 //11

#define NCHAN 5

BreezyCPPM rx(RXPIN, NCHAN);

void setup(void)
{
    Serial.begin(115200);

    rx.begin();
}

void loop(void)
{
    int16_t rcData[5];

    rx.computeRC(rcData);

    for (int k=0; k<NCHAN; ++k) {
        Serial.print(rcData[k]);
        Serial.print(" ");
    }
    Serial.println();
}
