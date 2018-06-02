// Copyright 2018 Zinoviev Vladimir

#include <cstdio>
#include <string>

#include "include/triangle-options.h"

int main(int argc, const char** argv) {
    TriangleOptions app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
