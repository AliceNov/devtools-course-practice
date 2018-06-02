// Copyright 2018 Tipanov Daniil

#include <cstdlib>
#include <cstdio>
#include <string>

#include "include/quadratic-equation-app.h"

int main(int argc, const char** argv) {
    QuadraticEquationApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
