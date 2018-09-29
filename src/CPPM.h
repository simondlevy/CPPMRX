/*
   Class header for Arduino CPPM class library

   Copyright (C) 2017 Greg Tomasch and Simon D. Levy

   This file is part of CPPM.

   CPPM is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   CPPM is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with CPPM.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

class CPPM
{
    public:

        static const uint16_t MINPULSE  = 700;
        static const uint16_t MAXPULSE  = 2250;
        static const uint16_t SYNCPULSE = 7500;                                                                                                                       
         CPPM(uint8_t pin, uint8_t nchan);

        void begin();

        bool gotNewFrame(void);

        void computeRC(uint16_t rcData[]);

    private:

       uint8_t _pin;
        uint8_t _nchan;
};
