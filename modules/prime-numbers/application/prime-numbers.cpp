// Copyright 2018 Kudalin Roman

#include <cstdio>
#include <string>

#include "include/prime-numbers-app.h"

int main(int argc, const char** argv) {
    PrimeNumbersApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

