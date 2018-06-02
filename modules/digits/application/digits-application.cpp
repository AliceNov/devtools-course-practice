// Copyright 2018 Bolshakov Konstantin

#include <stdio.h>
#include <string>

#include "include/Digits-app.h"

int main(int argc, const char**argv) {
    DigitsApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
