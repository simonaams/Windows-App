#ifndef dreptunghi_cpp
#define dreptunghi_cpp


class dreptunghi {

    int latime;
    int lungime;
    int aria;
    int perimetru;
    int calculare;

public:
	int rezultat;

    int perimetru1() {
        return perimetru;
    }

    int aria1() {
        return aria;
    }

    int calcul() {
        aria = latime * lungime;
        perimetru = 2 * (latime + lungime);

        return 0;
    }

    int calculAP() {
        rezultat = aria + perimetru;
        return 0;
    }

    dreptunghi() {
        latime = 0;
        lungime = 0;
        calcul();
        calculAP();
        calcul();
    }


    int seteaza(int x, int y) {
        latime = x;
        lungime = y;
        calcul();
        calculAP();
        calcul();
        return 0;
    }

};



class patrat : public dreptunghi {

public:

	int seteaza(int x) {

		dreptunghi::seteaza(x, x);

		return 0;
	}

};
 
#endif // !dreptunghi_cpp