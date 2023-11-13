#ifndef rational_h
#define rational_h

#include <iostream>
#include <cstring>

class Rational{
public:
    // member functions
    Rational() {}
    Rational(int numerator, int denominator);
    Rational(std::string rationalString);

    friend ostream &operator<ord<(ostream&, Rational);
private:
    // member variables
    int numerator;
    int denominator;
};


#endif
