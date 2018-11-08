#ifndef BIGINT_H
#define BIGINT_H

// All variables to be exposed shoudl be done as functions
// Make a destructor

#include <iostream>
#include <string>

using namespace std;

class BigInt
{

    string num;

public:
    int length();
    bool isPositive();

    BigInt();
    BigInt(string str);

    BigInt operator+(BigInt);
    BigInt operator*(BigInt &);
    BigInt operator-(BigInt);
    int operator>(BigInt);
    bool operator==(BigInt);

    // private
    void removeLeadingZeros();
    int makeEqualLength(BigInt &);

    // Implement input and output stream
    void print()
    {
        cout << num << endl;
    }

    // Radix mantissa
};

#endif