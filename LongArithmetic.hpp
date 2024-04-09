#pragma once
#include <iostream>
#include <vector>
#include <string>

class LongNumber{
private:
    int sign;
    long exponent;
    std::vector <int> Number;
    int inverse_limit = 500;
public:
    LongNumber(std::string s);
    LongNumber(const LongNumber& x);
    LongNumber();

    LongNumber remove_zeroes();
    LongNumber inverse_number();
    LongNumber rounding(int k);
    LongNumber operator- () const;
    LongNumber& operator=(const LongNumber& x);

    bool operator== (const LongNumber& x) const;
    bool operator!= (const LongNumber& x) const;
    bool operator> (const LongNumber& x) const;
    bool operator< (const LongNumber& x) const;
    bool operator>= (const LongNumber& x) const;
    bool operator<= (const LongNumber& x) const;

    LongNumber operator+ (const LongNumber& x) const;
    LongNumber operator- (const LongNumber& x) const;
    LongNumber operator* (const LongNumber& x) const;
    LongNumber operator/ (const LongNumber& x) const;

    std::string LongNumber_to_str();
};