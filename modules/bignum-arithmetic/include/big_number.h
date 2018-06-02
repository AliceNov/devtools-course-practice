// Copyright 2018 Usova Marina

#ifndef MODULES_BIGNUM_ARITHMETIC_INCLUDE_BIG_NUMBER_H_
#define MODULES_BIGNUM_ARITHMETIC_INCLUDE_BIG_NUMBER_H_

#include <vector>
#include <string>

class BigNumber {
 public:
    BigNumber();
    explicit BigNumber(const std::string s);
    BigNumber(const BigNumber& z);

    BigNumber& operator=(const BigNumber& z);

    const BigNumber operator + (const BigNumber& z) const;
    const BigNumber operator - (const BigNumber& z) const;
    const BigNumber operator * (const BigNumber& z) const;
    const BigNumber operator / (const BigNumber& z) const;
    const BigNumber operator / (const int & z) const;

    bool operator>(const BigNumber & z) const;

    bool operator == (const BigNumber& z) const;
    bool operator != (const BigNumber& z) const;

    std::vector<int> getNumber();
    std::string getResultInString();
    void setNumber(const std::vector<int> number_);
    std::vector<int> reverseVector(std::vector<int> z);

 private:
    std::vector<int> number;
};

#endif  // MODULES_BIGNUM_ARITHMETIC_INCLUDE_BIG_NUMBER_H_
