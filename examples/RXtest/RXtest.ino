#include <BreezyCPPM.h>

BreezyCPPM rx(4, 5);

void setup(void)
{
    Serial.begin(115200);

    rx.begin();
}

void loop(void)
{
    int16_t rcData[8];

    rx.computeRC(rcData);

    for (int k=0; k<5; ++k) {
        Serial.print(rcData[k]);
        Serial.print(" ");
    }
    Serial.println();
}
