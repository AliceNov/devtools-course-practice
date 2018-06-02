// Copyright 2017 Khomenko Aleksei

#ifndef MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_CALC_H_
#define MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_CALC_H_

#include <string>

class CurrencyConverterCalc {
 public:
    CurrencyConverterCalc();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double invalue;
        std::string function;
    } Arguments;
};

#endif  // MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_CALC_H_
