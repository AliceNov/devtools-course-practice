// Copyright 2018 SHURYGIN DMITRIY

#ifndef MODULES_FRACTIONAL_NUMBER_INCLUDE_FRACTIONAL_CALCULATOR_H_
#define MODULES_FRACTIONAL_NUMBER_INCLUDE_FRACTIONAL_CALCULATOR_H_

#include <string>

class FractionalCalculator {
 public:
    FractionalCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double a1;
        double b1;
        double a2;
        double b2;
        char operation;
    } Arguments;
};

#endif  // MODULES_FRACTIONAL_NUMBER_INCLUDE_FRACTIONAL_CALCULATOR_H_
