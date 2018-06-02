// Copyright 2018 Novikova Alisa

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/AcademicPefAccess.h"

int main(int argc, const char** argv) {
    AcademicPefAccess app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
