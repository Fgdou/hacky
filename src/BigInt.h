//
// Created by fgdou on 14/05/2021.
//

#ifndef HACKY_TEST_LONGINT_TEST_H
#define HACKY_TEST_LONGINT_H

#include <string>

class BigInt{
public:

    BigInt();
    BigInt(int n);
    BigInt(long n);
    BigInt(long long n);
    BigInt(std::string val);
    BigInt(const char* val);

    BigInt(const BigInt& copy);
    BigInt(BigInt&& copy);

    BigInt& operator=(int n);
    BigInt& operator=(long n);
    BigInt& operator=(long long n);
    BigInt& operator=(std::string val);
    BigInt& operator=(const char* val);
    BigInt& operator=(const BigInt& copy);
    BigInt& operator=(BigInt&& copy);

    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;
    BigInt operator/(const BigInt& other) const;
    BigInt operator%(const BigInt& other) const;

    BigInt& operator+=(const BigInt& other);
    BigInt& operator-=(const BigInt& other);
    BigInt& operator*=(const BigInt& other);
    BigInt& operator/=(const BigInt& other);
    BigInt& operator%=(const BigInt& other);

    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;

    BigInt operator-() const;

    operator std::string() const;

    BigInt abs() const;

private:
    bool negative;
    std::string val;
};

#endif //HACKY_TEST_LONGINT_TEST_H
