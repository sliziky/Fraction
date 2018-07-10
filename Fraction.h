#ifndef FRACTION
#define FRACTION
#include <iostream>

unsigned int gcd(int n1, int n2);

class Fraction {

private:
    int _numerator;
    int _denominator;

public:
    Fraction(int num = 0, int denom = 1) :
        _numerator( num / gcd( std::abs(num),std::abs(denom) )),
        _denominator( denom / gcd( std::abs(num),std::abs(denom) )) {
        if (denom == 0) {
            throw std::logic_error("Division by 0");
        }
        if (num < 0 && denom < 0) {
            _numerator *= -1;
            _denominator *= -1;
        }
    }
    Fraction operator+(const Fraction& other);
    Fraction operator-(const Fraction& other);
    Fraction operator*(const Fraction& other);
    Fraction operator/(const Fraction& other);
    Fraction& operator=(const Fraction& other);
    bool operator<(const Fraction& other);
    bool operator<=(const Fraction& other);
    bool operator>(const Fraction& other);
    bool operator>=(const Fraction& other);
    bool operator==(const Fraction& other);
    bool operator!=(const Fraction& other);
    friend std::ostream& operator<<(std::ostream& os, const Fraction& other);
    friend std::istream& operator>>(std::istream& is, Fraction& other);
    int getNum() { return _numerator; }
    int getDenum() { return _denominator; }
};

#endif
