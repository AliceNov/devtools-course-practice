// Copyright 2018 Okunev Boris

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/leftist_heap_app.h"

int main(int argc, const char** argv) {
    LeftistHeapApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
