//
// Created by ROY VAKNIN  on 9/29/21.
//

#ifndef RATIONALNUMBERS_RATIONALNUMBER_H
#define RATIONALNUMBERS_RATIONALNUMBER_H
#include <string>
#include <cmath>
#include <iostream>

// -- set the default namespace, avoids having to do std:: on objects/methods
using namespace std;

class RationalNumber{
protected:
    int numerator;
    int denominator;

    RationalNumber Simplify(RationalNumber num);
    bool canSimplify(RationalNumber num);
    int GCF(int a, int b);


public:

    RationalNumber();

    RationalNumber(int num, int dem);

    RationalNumber(const RationalNumber &rhs);

    ~RationalNumber();


    int getNumerator() const;
    int getDenominator() const ;



    void setNumerator(int n);
    void setDenominator(int d);


    RationalNumber add( RationalNumber &rhs);

    RationalNumber sub( RationalNumber &rhs);

    RationalNumber mult(const RationalNumber &rhs);

    RationalNumber div (const RationalNumber &rhs);

    bool equals(const RationalNumber &rhs);

    string ToString();







};


#endif //RATIONALNUMBERS_RATIONALNUMBER_H
