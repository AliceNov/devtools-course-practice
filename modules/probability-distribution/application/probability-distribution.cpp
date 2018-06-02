// Copyright 2018 Lalykin Oleg
#include <cstdlib>
#include <cstdio>

#include <string>

#include "include/prob_dis_calculator.h"

int main(int argc, const char** argv) {
    ProbDisCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
