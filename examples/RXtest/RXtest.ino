#include <BreezyCPPM.h>

BreezyCPPM rx;

int16_t  rcData[RC_CHANS];
uint32_t rawRC[RC_CHANS];

void setup(void)
{
    Serial.begin(115200);

    rx.configureReceiver();
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
