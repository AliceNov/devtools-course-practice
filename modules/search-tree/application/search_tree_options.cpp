// Copyright 2018 Gladyshev Alexey

#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>

#include "include/search_tree_options.h"
#include "include/search_tree.h"

int main(int argc, const char** argv) {
    SearchTreeOptions app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
