#pragma once
#define _USE_MATH_DEFINES
#ifndef cerc_cpp

#include <math.h>


class cerc  {

        int raza;
        float ariaCerc;
        float circumCerc;

    public:
        int rezultat;

        int circumferinta() {
            return circumCerc;
        }

        int aria1() {
            return ariaCerc;
        }

        float calculCerc() {
            ariaCerc = M_PI * raza * raza;
            circumCerc = 2 * M_PI * raza;
            return 0;
        }

        cerc() {
            raza = 0;
            calculCerc();
        }


        int seteaza(int x) {
            raza = x;
            calculCerc();
            return 0;
        }

    

};

#endif // !cerc_cpp