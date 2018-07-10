#include "stdafx.h"
#include <iostream>
#include "FractionClass.h"

Fraction Fraction::operator+(const Fraction & other) {
    const int scmTemp = this->_denominator * other._denominator;
    const int numTemp = (scmTemp / this->_denominator * this->_numerator) + (scmTemp / other._denominator * other._numerator);
    return Fraction{ numTemp,scmTemp };
}

Fraction Fraction::operator-(const Fraction & other) {
    const int gcdTemp = this->_denominator * other._denominator;
    const int numTemp = (gcdTemp / this->_denominator * this->_numerator) - (gcdTemp / other._denominator * other._numerator);
    return Fraction{ numTemp,gcdTemp };
}

Fraction Fraction::operator*(const Fraction &other) {
    return Fraction{ this->_numerator * other._numerator, (this->_denominator * other._denominator) };
}

Fraction Fraction::operator/(const Fraction &other) {
    return Fraction{ this->_numerator * other._denominator, (this->_denominator * std::abs(other._numerator)) };
}

bool Fraction::operator<(const Fraction & other)
{
    unsigned int scnTemp = this->_denominator * other._denominator;
    return (scnTemp / other._denominator * other._numerator > scnTemp / this->_denominator * this->_numerator);
}

bool Fraction::operator<=(const Fraction & other)
{
    unsigned int scnTemp = this->_denominator * other._denominator;
    return (scnTemp / other._denominator * other._numerator >= scnTemp / this->_denominator * this->_numerator);
}

bool Fraction::operator>(const Fraction & other)
{
    unsigned int scnTemp = this->_denominator * other._denominator;
    return (scnTemp / other._denominator * other._numerator < scnTemp / this->_denominator * this->_numerator);
}

bool Fraction::operator>=(const Fraction & other)
{
    unsigned int scnTemp = this->_denominator * other._denominator;
    return (scnTemp / other._denominator * other._numerator <= scnTemp / this->_denominator * this->_numerator);
}

bool Fraction::operator==(const Fraction & other)
{
        return (this->_numerator == other._numerator && this->_denominator == other._denominator);
}

bool Fraction::operator!=(const Fraction & other)
{
    return !(*this == other);
}

Fraction& Fraction::operator=(const Fraction &other) {
    this->_numerator = other._numerator;
    this->_denominator = other._denominator;
    return *this;
}



std::ostream& operator<<(std::ostream& os, const Fraction& other) {
    os << other._numerator << '/' << other._denominator << '\n';
    return os;
}
std::istream& operator>>(std::istream& is, Fraction& other)
{
    is >> other._numerator >> other._denominator;
    if (other._denominator == 0) {
        throw;
    }
    other = Fraction(other._numerator, other._denominator);
    return is;
}


unsigned int gcd(int u, int v) {
    while (v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}




