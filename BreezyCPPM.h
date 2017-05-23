#ifndef BreezyCPPM_h
#define BreezyCPPM_h

#define PPM_MINPULSE  700
#define PPM_MAXPULSE  2250
#define PPM_SYNCPULSE 7500                                                                                                                       
class BreezyCPPM
{
    public:

        BreezyCPPM(int pin, int nchan);

        void begin();

        void computeRC(int16_t rcData[]);

    private:

        int _pin;
        int _nchan;

        static void  BreezyCPPM_isr();
};

#endif // BreezyCPPM_h
