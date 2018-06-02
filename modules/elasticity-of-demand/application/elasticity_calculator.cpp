// Copyright 2018 Rodionov Fedor

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/elasticity_calculator.h"


int main(int argc, const char** argv) {
    ElasticityCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
