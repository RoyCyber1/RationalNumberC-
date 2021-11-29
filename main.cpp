#include <iostream>
# include "RationalNumber.h"
//#include "RationalNumber.cpp"
#include <iostream>

using namespace std;

int main() {

    try {

        RationalNumber e = RationalNumber(15, 25);
        RationalNumber w = RationalNumber(4, 7);
        RationalNumber x = RationalNumber(15,-25);
        RationalNumber m = RationalNumber(-40,35);

        std::cout << e.ToString() << std::endl;
        std::cout << e.equals(x) << std::endl;




        w.setNumerator(3);
        w.setDenominator(5);

        std::cout << x.ToString() << std::endl;

        std::cout << m.ToString()<< std::endl;


        e =e.sub(w);
        std::cout << e.getNumerator() << std::endl;
        std::cout << e.getDenominator() << std::endl;

        std::cout << e.ToString() << std::endl;

        e = e.add(w);
        std::cout << e.getNumerator() << std::endl;
        std::cout <<e.getDenominator()<< std::endl;
        std::cout <<e.ToString()<< std::endl;


        e = e.div(w);
        std::cout <<e.getNumerator()<< std::endl;
        std::cout <<e.getDenominator()<< std::endl;
        std::cout << e.ToString() << std::endl;


        e = e.mult(w);
        std::cout <<e.getNumerator()<< std::endl;
        std::cout <<e.getDenominator()<< std::endl;


        std::cout << e.ToString()<< std::endl;
        std::cout <<e.getNumerator()<< std::endl;
        std::cout << e.getDenominator()<< std::endl;




    }catch(exception e){

    }




}

