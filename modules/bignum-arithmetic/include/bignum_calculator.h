// Copyright 2018 Usova Marina

#ifndef MODULES_BIGNUM_ARITHMETIC_INCLUDE_BIGNUM_CALCULATOR_H_
#define MODULES_BIGNUM_ARITHMETIC_INCLUDE_BIGNUM_CALCULATOR_H_

#include <string>
#include <vector>

class BigNumCalculator {
 public:
    BigNumCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::vector<int> z1;
        std::vector<int> z2;
        char operation;
    } Arguments;
};

#endif  // MODULES_BIGNUM_ARITHMETIC_INCLUDE_BIGNUM_CALCULATOR_H_
