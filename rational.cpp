#include "rational.h"

Rational::Rational(int num1, int num2){
    numerator = num1;
    denominator = num2;
}

Rational::Rational(std::string rationalString){
    // use c-strings to read up until division?

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

// need to figure out how to overload insertion operator
std::ostream & operator<<(std::ostream &os, Rational rat){
    os << rat.numerator << "/" << rat.denominator;
    return os;
}

