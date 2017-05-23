#include "Arduino.h"
#include "BreezyCPPM.h"

#define RC_CHANS 6

#define PPM_MINPULSE  700
#define PPM_MAXPULSE  2250
#define PPM_SYNCPULSE 7500                                                                                                                       
volatile uint16_t RCVR[RC_CHANS];
volatile uint16_t PPM_temp[RC_CHANS];
volatile uint32_t startPulse = 0;
volatile uint8_t  ppmCounter = RC_CHANS;
volatile uint16_t PPM_error = 0;

BreezyCPPM::BreezyCPPM(int pin, int nchan)
{
    _pin = pin;
    _nchan = nchan;
}

/**
 * @fn: configureReceiver()
 *
 * @brief: Configures input pin and interrupt for 6Ch cPPM receiver
 * @params:
 * @returns:
 */  
void BreezyCPPM::begin()
{
    pinMode(_pin, INPUT);
    attachInterrupt(_pin, BreezyCPPM_isr, RISING);
    for (uint8_t i=0; i < RC_CHANS; i++)
    {
        RCVR[i] = 1500;
        PPM_temp[i] = 1500;
    }
}

/**
 * @fn: BreezyCPPM_isr()
 *
 * @brief: Pulse train decoder interrupt service routine for 6Ch cPPM receiver
 * @params:
 * @returns:
 */
void BreezyCPPM::BreezyCPPM_isr()
{
    uint32_t stopPulse = micros();

    // clear channel interrupt flag (CHF)
    volatile uint32_t pulseWidth = stopPulse - startPulse;

    // Error sanity check
    if (pulseWidth < PPM_MINPULSE || (pulseWidth > PPM_MAXPULSE && pulseWidth < PPM_SYNCPULSE))
    {
        PPM_error++;

        // set ppmCounter out of range so rest and (later on) whole frame is dropped
        ppmCounter = RC_CHANS + 1;
    }
    if (pulseWidth >= PPM_SYNCPULSE)
    {
        // Verify if this is the sync pulse
        if (ppmCounter <= RC_CHANS)
        {
            // This indicates that we received an correct frame = push to the "main" PPM array
            // if we received an broken frame, it will get ignored here and later get over-written
            // by new data, that will also be checked for sanity.
            for (uint8_t i = 0; i < RC_CHANS; i++)
            {
                RCVR[i] = PPM_temp[i];             
            }
        }

        // restart the channel counter
        ppmCounter = 0;
    } else
    {  
        // extra channels will get ignored here
        if (ppmCounter < RC_CHANS)
        {   
            // Store measured pulse length in us
            PPM_temp[ppmCounter] = pulseWidth;

            // Advance to next channel
            ppmCounter++;
        }
    }

    // Save time at pulse start
    startPulse = stopPulse;
}

/**
 * @fn: computeRC()
 *
 * @brief: Calculates and assigns smoothed RC data to the correct channel
 * @params:
 * @returns:
 */
void BreezyCPPM::computeRC(int16_t rcData[])
{
    static uint16_t rcData4Values[RC_CHANS][4], rcDataMean[RC_CHANS];
    static uint8_t rc4ValuesIndex = 0;
    uint8_t chan,a;
    uint32_t rawRC[RC_CHANS];

    rc4ValuesIndex++;
    if (rc4ValuesIndex == 4) rc4ValuesIndex = 0;

    for (int k=0; k<5; ++k) {
        rawRC[k] = RCVR[k];
    }

    for (chan = 0; chan < RC_CHANS; chan++)
    {
        rcData4Values[chan][rc4ValuesIndex] = rawRC[chan];
        rcDataMean[chan] = 0;
        for (a=0; a<4; a++) rcDataMean[chan] += rcData4Values[chan][a];
        rcDataMean[chan]= (rcDataMean[chan] + 2) >> 2;
        if ( rcDataMean[chan] < (uint16_t)rcData[chan] - 3)  rcData[chan] = rcDataMean[chan] + 2;
        if ( rcDataMean[chan] > (uint16_t)rcData[chan] + 3)  rcData[chan] = rcDataMean[chan] - 2;
    }
}
