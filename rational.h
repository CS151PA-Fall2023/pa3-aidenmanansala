/**
 * @file main.cpp
 * @author Aiden Manansala
 * @brief rational class prototypes
 * @version 0.1
 * @date 10-17-2023 
 * 
 */

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cstring>

class Rational{
public:
    // member functions
    Rational() {numerator=0; denominator=0;} // default constructor
    Rational(int numerator, int denominator);
    Rational(std::string rationalString);
    Rational(const Rational &rat);
    Rational(const char* cstr);

    Rational& operator=(const Rational &rat);
    operator double() const;
    friend std::ostream &operator<<(std::ostream&, Rational);
    friend Rational operator+(const Rational &rat1, const Rational &rat2);
    friend Rational operator-(const Rational &rat1, const Rational &rat2);
    friend Rational operator*(const Rational &rat1, const Rational &rat2);        
    friend Rational operator/(const Rational &rat1, const Rational &rat2);        


    void reduce();    
private:
    // member variables
    int numerator;
    int denominator;
};


#endif
