// Copyright 2018 Kuznetsov Konstantin

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/vectors_calculator.h"

int main(int argc, const char** argv) {
    VectorsCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
