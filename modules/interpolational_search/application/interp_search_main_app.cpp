// Copyright 2018 Fedorova Olga

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "include/interp_search_app.h"

int main(int argc, const char** argv) {
    InterpSearchApp app;
    std::string msg = app(argc, argv);
    printf("%s\n", msg.c_str());
    return 0;
}
