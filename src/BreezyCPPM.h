/*
   Class header for Arduino BreezyCPPM class library

   Copyright (C) 2017 Greg Tomasch and Simon D. Levy

   This file is part of BreezyCPPM.

   BreezyCPPM is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   BreezyCPPM is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with BreezyCPPM.  If not, see <http://www.gnu.org/licenses/>.
 */

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

        static void  isr();
};

#endif // BreezyCPPM_h
