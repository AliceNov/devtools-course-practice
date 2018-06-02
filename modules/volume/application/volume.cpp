// Copyright 2018 Konakov Alexandr

#include <cstdlib>
#include <cstdio>
#include <string>

#include "include/volume_calculator.h"

int main(int argc, const char** argv) {
    VolumeCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
