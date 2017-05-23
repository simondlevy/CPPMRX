#ifndef BreezyCPPM_h
#define BreezyCPPM_h

#define RC_CHANS 6

class BreezyCPPM
{
    public:

        BreezyCPPM(int pin, int nchan);

        void begin();

        void computeRC(int16_t rcData[8]);

    private:

        int _pin;
        int _nchan;

        static void  BreezyCPPM_isr();
};

#endif // BreezyCPPM_h
