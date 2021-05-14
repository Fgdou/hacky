//
// Created by fgdou on 14/05/2021.
//

#include "BigInt.h"

namespace {
    std::string deleteZeros(std::string str){
        for(int i=0; i<str.length(); i++){
            if(str[i] != '0')
                return str.substr(i, str.length()-i);
        }
    }
}

BigInt::BigInt()
    : negative(false), val("")
{

}

BigInt::BigInt(int n)
    : negative(n < 0), val(std::to_string(std::abs(n)))
{

}

BigInt::BigInt(long n)
    : negative(n < 0), val(std::to_string(std::abs(n)))
{

}

BigInt::BigInt(long long int n)
    : negative(n < 0), val(std::to_string(std::abs(n)))
{

}

BigInt::BigInt(const BigInt &copy)
    : negative(copy.negative), val(copy.val)
{

}

BigInt::BigInt(BigInt &&copy)
    : negative(copy.negative), val(std::move(copy.val))
{

}

BigInt &BigInt::operator=(int n) {
    negative = n<0;
    val = std::to_string(std::abs(n));
    return *this;
}

BigInt &BigInt::operator=(long n) {
    negative = n<0;
    val = std::to_string(std::abs(n));
    return *this;
}

BigInt &BigInt::operator=(long long int n) {
    negative = n<0;
    val = std::to_string(std::abs(n));
    return *this;
}

BigInt &BigInt::operator=(const BigInt &copy) {
    negative = copy.negative;
    val = copy.val;
    return *this;
}

BigInt &BigInt::operator=(BigInt &&copy) {
    negative = copy.negative;
    val = std::move(copy.val);
    return *this;
}

BigInt::BigInt(std::string val) {
    if(val[0] == '-'){
        negative = true;
        this->val = val.substr(1, val.length()-1);
    }else{
        negative = false;
        this->val = val;
    }
}

BigInt &BigInt::operator=(std::string val) {
    if(val[0] == '-'){
        negative = true;
        this->val = val.substr(1, val.length()-1);
    }else{
        negative = false;
        this->val = val;
    }
    return *this;
}

BigInt BigInt::operator+(const BigInt &other) const {
    std::string result;
    int carry = 0;
    int max_length = std::max(val.length(), other.val.length());

    for(int i=0; i<max_length; i++){
        int a=0, b=0;

        if(i < val.length())
            a = val[val.length()-i-1] - '0';
        if(i < other.val.length())
            b = other.val[other.val.length()-i-1] - '0';

        int c = a + b + carry;

        if(c >= 10) {
            carry = 1;
            c -= 10;
        }else{
            carry = 0;
        }

        result = std::to_string(c) + result;
    }

    if(carry)
        result = '1' + result;

    return result;
}

BigInt::operator std::string() const {
    if(negative)
        return '-' + val;
    return val;
}

BigInt::BigInt(const char *tab) {
    std::string val(tab);
    if(val[0] == '-'){
        negative = true;
        this->val = val.substr(1, val.length()-1);
    }else{
        negative = false;
        this->val = val;
    }
}

BigInt &BigInt::operator=(const char *tab) {
    std::string val(tab);
    if(val[0] == '-'){
        negative = true;
        this->val = val.substr(1, val.length()-1);
    }else{
        negative = false;
        this->val = val;
    }
}

bool BigInt::operator==(const BigInt &other) const {
    return (negative == other.negative && val == other.val);
}

BigInt BigInt::operator-(const BigInt &other) const {

    if(*this == other)
        return BigInt();

    std::string result;
    bool negative = false;
    int carry=0;

    const BigInt* min;
    const BigInt* max;

    if(*this < other){
        min = this;
        max = &other;
        negative = true;
    }else{
        min = &other;
        max = this;
    }

    int max_length = std::max(val.length(), other.val.length());

    for(int i=0; i<max_length; i++){
        int a, b=0;

        a = max->val[max->val.length()-i-1] - '0';
        if(i < min->val.length())
            b = min->val[min->val.length()-i-1] - '0';

        int c;

        if(b+carry > a){
            a += 10;
            c = a - b - carry;
            carry = 1;
        }else{
            c = a - b - carry;
            carry = 0;
        }

        result = std::to_string(c) + result;
    }

    BigInt b;
    b.val = deleteZeros(result);
    b.negative = negative;

    return b;

}

bool BigInt::operator>(const BigInt &other) const {
    if(negative)
        return -(*this) < other;
    if(other.negative)
        return true;
    return val < other.val;
}

BigInt BigInt::operator-() const {
    BigInt copy = *this;
    copy.negative = !copy.negative;
    return copy;
}

bool BigInt::operator<(const BigInt &other) const {
    if(other.negative)
        return *this > -other;
    if(negative)
        return true;
    return val < other.val;
}

bool BigInt::operator!=(const BigInt &other) const {
    return !(*this == other);
}

bool BigInt::operator<=(const BigInt &other) const {
    return *this < other || *this == other;
}

bool BigInt::operator>=(const BigInt &other) const {
    return *this > other || *this == other;
}
