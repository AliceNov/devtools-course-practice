// Copyright 2018 Galochkin Boris

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/l_metrics_float_calculator.h"

int main(int argc, const char** argv) {
    LMetricsFloatCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
