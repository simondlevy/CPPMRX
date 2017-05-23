#ifndef BreezyCPPM_h
#define BreezyCPPM_h

#define RC_CHANS 6

extern int16_t   rcData[];

class BreezyCPPM
{
    public:

        BreezyCPPM(int pin, int nchan);
        void begin();
        void computeRC();

    private:

        int _pin;
        int _nchan;

        static void  BreezyCPPM_isr();
};

#endif // BreezyCPPM_h
