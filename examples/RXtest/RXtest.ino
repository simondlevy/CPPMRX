#include <BreezyCPPM.h>

BreezyCPPM rx(4, 5);

int16_t  rcData[RC_CHANS];

void setup(void)
{
    Serial.begin(115200);

    rx.begin();
}

void loop(void)
{
    rx.computeRC();

    for (int k=0; k<5; ++k) {
        Serial.print(rcData[k]);
        Serial.print(" ");
    }
    Serial.println();
}
