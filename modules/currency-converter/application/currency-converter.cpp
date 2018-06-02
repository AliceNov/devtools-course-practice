// Copyright 2017 Khomenko Aleksei

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/currency_converter_calc.h"

int main(int argc, const char** argv) {
    CurrencyConverterCalc app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
