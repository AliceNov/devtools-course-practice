// Copyright 2018 Usova Marina

#include "include/bignum_calculator.h"

#include <cstdlib>
#include <cstdio>
#include <string>

int main(int argc, const char** argv) {
    BigNumCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
