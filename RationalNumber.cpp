//
// Created by ROY VAKNIN  on 9/29/21.
//

#include "RationalNumber.h"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

RationalNumber ::RationalNumber()
: numerator(0), denominator(1)
{

}

RationalNumber ::RationalNumber(int num, int dem)
{
    if (dem == 0) {
        throw ("Cant have 0 in the denominator");
    }
    this->numerator = num;
    this -> denominator = dem;



}
RationalNumber :: RationalNumber( const RationalNumber &rhs)

{
    if(rhs.denominator == 0) {
    throw ("Cant have 0 in denominator");
    }
    this->numerator = rhs.numerator;
    this->denominator = rhs.denominator;


}

RationalNumber ::~ RationalNumber() {
}

int RationalNumber::getNumerator() const {
    return this->numerator;
}
int RationalNumber::getDenominator() const {
    return this->denominator;
}
void RationalNumber::setNumerator(int n) {
    this->numerator = n;
}
void RationalNumber::setDenominator(int d) {
    this->denominator = d;
}

int RationalNumber:: GCF(int x , int y) {
    if (x == 0)
        return y;
    return GCF(y%x,x);
}

RationalNumber RationalNumber:: add( RationalNumber &rhs){

    int demF = GCF(this->denominator,rhs.denominator);
    demF = (this->denominator *rhs.denominator)/demF;
    int NumF = this->numerator * (demF/this->denominator) + rhs.numerator *(demF/rhs.denominator);
    RationalNumber x = RationalNumber(NumF,demF);
    return x;
    /*if (::abs(this->denominator) == ::abs(rhs.denominator)) {
        try {
            int n = this->numerator + rhs.numerator;
            int dem = this->denominator;
            RationalNumber a = RationalNumber(n, dem);
            return a;
        } catch (exception e) {

        }
    }
    int i = 2;
    while (::abs(this->denominator) != ::abs(rhs.denominator)) {
        if (::abs(this->denominator) * i == ::abs(rhs.denominator)) {
            int sum = this->numerator * i + rhs.numerator;
            try {
                RationalNumber a =   RationalNumber(sum, this->denominator * i);
                return a;
            } catch (exception e) {

            }

        } else if (::abs(this->denominator) == ::abs(rhs.denominator * i)) {
            int sum = this->numerator + rhs.numerator * i;
            try {
                RationalNumber a = RationalNumber(sum, rhs.denominator * i);
                return a;
            } catch (exception e) {

            }
        } else if (::abs(this->denominator) * i == ::abs(rhs.denominator * i)) {
            int sum = this->numerator * i + rhs.numerator * i;
            try {
                RationalNumber a = RationalNumber(sum, this->denominator * i);
                return a;
            } catch (exception e) {
            }


        }
        i++;*/

    }
//RationalNumber b = RationalNumber(this->numerator, this->denominator) ;
 //   return b;

//}

RationalNumber RationalNumber:: sub(RationalNumber &rhs){
    if (this->denominator == rhs.denominator) {
        try {
            int n = this->numerator - rhs.numerator;
            RationalNumber a =  RationalNumber(n, this->denominator);
            return a;
        } catch (exception e) {

        }
    }
    int i = 2;
    while (this->denominator != rhs.denominator) {
        if (this->denominator * i == rhs.denominator) {
            int sum = this->numerator * i - rhs.numerator;
            try {
                RationalNumber a = RationalNumber(sum, this->denominator * i);
                return a;
            } catch (exception e) {

            }

        } else if (this->denominator == rhs.denominator * i) {
            int sum = this->numerator - rhs.numerator * i;
            try {
                RationalNumber a = RationalNumber(sum, rhs.denominator * i);
                return a;
            } catch (exception e) {

            }
        } else if (this->denominator * i == rhs.denominator * i) {
            int sum = this->numerator * i - rhs.numerator * i;
            try {
                RationalNumber a = RationalNumber(sum, this->denominator * i);
            } catch (exception e) {
            }


        }
        i++;

    }

    return *this;



}

RationalNumber RationalNumber:: mult(const RationalNumber &rhs){
    int num = this->numerator*rhs.numerator;
   int demm =  this->denominator*rhs.denominator;
   RationalNumber x = RationalNumber(num,demm);
    return x;

}

RationalNumber RationalNumber:: div (const RationalNumber &rhs){
    int num = this->numerator*rhs.denominator;
    int demm =  this->denominator*rhs.numerator;
    RationalNumber x;
    x = RationalNumber(num,demm);
    return x;

}

bool RationalNumber :: equals(const RationalNumber &rhs){
    if(this->numerator == rhs.numerator && this->denominator == rhs.denominator){
        return true;
    }
    return false;

}
RationalNumber RationalNumber:: Simplify(RationalNumber num){
    if (abs(num.denominator) > abs(num.numerator)) {
        for (int i = 2; i <= abs(num.denominator); i++) {
            while (num.numerator % i == 0 && num.denominator % i == 0) {
                try {
                    num.numerator = num.numerator/i;
                    num.denominator= num.denominator/i;

                } catch (exception e) {

                }
            }

        }
        try {
            RationalNumber a = RationalNumber(num.numerator, num.denominator);
            return a;
        }catch(exception e){

        }
    }
    else if (abs(num.denominator) < abs(num.numerator)) {
        for (int x = 2; x <= abs(num.numerator); x++) {
            while (num.numerator % x == 0 && num.denominator % x == 0) {
                try {
                    num.numerator = num.numerator/x;
                    num.denominator= num.denominator/x;

                } catch (exception e) {

                }
            }

        }
        try {
            RationalNumber a = RationalNumber(num.numerator, num.denominator);
            return a;
        }catch(exception e){

        }

    }


    return *this;
}

bool RationalNumber:: canSimplify (RationalNumber rhs) {

    if (abs(rhs.denominator) > abs(rhs.numerator)) {
        for (int i = 2; i <= abs(denominator); i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                return true;
            }
        }
    }
    else if (abs(rhs.denominator) < abs(rhs.numerator)) {
        for(int i =2; i<=abs(numerator); i++){
            if (this->numerator % i == 0 && this->denominator % i == 0) {
                return true;
            }
        }


    }

    return false;
}
string RationalNumber:: ToString(){
    RationalNumber x = RationalNumber(this->numerator,this->denominator);

    RationalNumber simple = x.Simplify(x);

    if (simple.numerator == 0) {
        return to_string(simple.numerator) + "/" + to_string(simple.denominator) + "= 0";
    } else if (simple.denominator == simple.numerator) {
        if (simple.numerator * -1 < simple.numerator && simple.denominator * -1 > simple.denominator) {
            return "-1";
        } else return "1";
    }
    if (simple.numerator * -1 > 0 && simple.denominator * -1 > 0) {
        simple.numerator = simple.numerator * -1;
        simple.denominator = simple.denominator * -1;
    }
    if((abs(simple.numerator) < abs(simple.denominator))){
        if (simple.numerator * -1 > 0 && simple.denominator * -1 > 0) {
            return to_string(simple.numerator * -1) + "/" + to_string(simple.denominator * -1);
        } else if (simple.numerator * -1 < simple.numerator && simple.denominator * -1 > simple.denominator) {
            return "" + to_string(simple.numerator * -1) + "/" + to_string(simple.denominator * -1) + "";
        }
    }


    if (abs(simple.numerator) > abs(simple.denominator)) {
        int q = (int) simple.numerator / simple.denominator;
        int rem = (int) simple.numerator % simple.denominator;
        simple.numerator = rem;
        if(q *-1 >0 && simple.numerator*-1 >0){
            simple.numerator = simple.numerator*-1;
        }
        if (simple.numerator * -1 < simple.numerator && simple.denominator * -1 > simple.denominator && q * -1 > q) {
            q = q * -1;
            simple.numerator = simple.numerator * -1;
            simple.denominator = simple.denominator * -1;
        }
        if (simple.numerator == 0) {
            return to_string(q) + "";
        }
        if (q == 0) {
            return to_string(simple.numerator) + "/" + to_string(simple.denominator);
        }


        else return to_string(q) + " " + to_string(simple.numerator) + "/" + to_string(simple.denominator);


    }


    if (!canSimplify(simple)) {
        if (simple.numerator * -1 > simple.numerator && simple.denominator * -1 > simple.denominator) {
            return to_string(simple.numerator * -1) + "/" + to_string(simple.denominator * -1);
        } else if (simple.numerator * -1 < simple.numerator && simple.denominator * -1 > simple.denominator) {
            return "" + to_string(simple.numerator * -1) + "/" + to_string(simple.denominator * -1) + "";
        } else return to_string(simple.numerator) + "/" + to_string(simple.denominator);
    }
    simple = Simplify(simple);
   // this-> numerator = simple.numerator;
   // this-> denominator = simple.denominator;
    return to_string(simple.numerator) +"/" + to_string(simple.denominator);
}












