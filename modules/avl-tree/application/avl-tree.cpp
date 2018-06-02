// Copyright 2018 Tarakanov Kirill

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/avl_app.h"

int main(int argc, const char** argv) {
    AVL_App app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
