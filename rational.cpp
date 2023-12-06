/**
 * @file main.cpp
 * @author Aiden Manansala
 * @brief rational class implementation
 * @version 0.1
 * @date 10-17-2023 
 * 
 */

#include "rational.h"

/**
 * brief: Constructor for a rational with numerator and denominator given
 */
Rational::Rational(int num1, int num2){
    numerator = num1;
    denominator = num2;
}

/**
 * brief: Constructor for when rational is given as a string
 */

Rational::Rational(std::string rationalString){

    std::string strNumerator, strDenominator = "";

    bool passedDivision = false;
    for(int i=0;i<size(rationalString);i++){
        if(rationalString[i]=='/'){
            passedDivision = true;
            continue;
        }
        else if(passedDivision==false){
            strNumerator += rationalString[i];
        }
        else{
            strDenominator += rationalString[i];
        }
    }

    numerator = std::stoi(strNumerator);
    denominator = std::stoi(strDenominator);
    
}

/**
 * brief: overloads the insertion stream operator
 */
std::ostream & operator<<(std::ostream &os, Rational rat){
    os << rat.numerator << "/" << rat.denominator;
    return os;
}

/**
 * brief: constructs a rational from another rational (copy constructor)
 */
Rational::Rational(const Rational &rat){
    numerator = rat.numerator;
    denominator = rat.denominator;
}

/**
 * brief: Overloads the assignment operator
 */
Rational& Rational::operator=(const Rational &rat){
   if(this!=&rat){
        numerator = rat.numerator;
        denominator = rat.denominator;
   }

   return *this;
}

/**
 * brief: Allows rationals to be cast as doubles
 */
Rational::operator double() const{
    return static_cast<double>(numerator) / static_cast<double>(denominator);
}

/**
 * brief: simplifies a rational
 */
void Rational::reduce(){
    bool ended = false;
    int top = numerator;
    int bottom = denominator;
    while(!ended){
        for(int i=2; i<100; i++){
            if((top%i==0) && (bottom%i==0)){
                top = top/i;
                bottom = bottom/i;
                break;
            }
            if(i==99){
                ended = true;
            }
        }
    }

    numerator = top;
    denominator = bottom;
}

/**
 * brief: constructs a rational from a cstring
 */
Rational::Rational(const char* cstr){
    bool passed = false;
    std::string top, bottom = "";

    for(int i=0; i<strlen(cstr); i++){
        if(cstr[i]=='/'){
            passed = true;
            continue;
        }
        if(!passed){
            top += cstr[i];
        } else{
            bottom += cstr[i];
        }
    }
    numerator = stoi(top);
    denominator = stoi(bottom);
}

/**
 * brief: overloads the addition operator
 */
Rational operator+(const Rational &rat1, const Rational &rat2){
    Rational returnable;
    int likedenom;
    if(rat1.denominator != rat2.denominator)
        likedenom = rat1.denominator * rat2.denominator;
    else
        likedenom = rat1;

    returnable.denominator = likedenom;
    returnable.numerator = (rat1.numerator * rat2.denominator) + (rat2.numerator * rat1.denominator);

    returnable.reduce();

    return returnable;
}

/**
 * brief: overloads the subtraction operator
 */
Rational operator-(const Rational &rat1, const Rational &rat2){
    Rational result;

    int likedenom;
    if(rat1.denominator !=  rat2.denominator)
        likedenom = rat1.denominator * rat2.denominator;
    else
        likedenom = rat1;

    result.denominator = likedenom;
    result.numerator = (rat1.numerator * rat2.denominator) - (rat2.numerator * rat1.denominator);

    result.reduce();

    return result;
}

/**
 * brief: overloads the multiplication operator
 */
Rational operator*(const Rational &rat1, const Rational &rat2){
    Rational result;

    result.numerator = (rat1.numerator)*(rat2.numerator);
    result.denominator = (rat1.denominator)*(rat2.denominator);
    
    result.reduce();

    return result;

}

/**
 * brief: overloads the divison operator
 */
Rational operator/(const Rational &rat1, const Rational &rat2){
    Rational result;

    result.numerator = rat1.numerator * rat2.denominator;
    result.denominator = rat1.denominator * rat2.numerator;
    
    result.reduce();

    return result;

}
