#ifndef BreezyCPPM_h
#define BreezyCPPM_h

#define RC_CHANS 6

extern int16_t   rcData[];
extern uint32_t  rawRC[];

class BreezyCPPM
{
  public:
                 BreezyCPPM();
     void        configureReceiver();
     void        readRawRC();
     void        computeRC();

  private:

    static void  BreezyCPPM_isr();
};

#endif // BreezyCPPM_h
