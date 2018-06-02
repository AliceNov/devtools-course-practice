// Copyright 2018 Fedorova Olga

#include "include/interp_search.h"
#include "include/interp_search_app.h"

#include <cstdlib>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>
#include <exception>

InterpSearchApp::InterpSearchApp() {
}

bool InterpSearchApp::AreArgumentsValid(int argc, const char** argv) {
    if (argc == 1) {
        msg = std::string("Input following arguments:\n") +
               "list of integers and number," +
               "which possition you want to find there.\n";
        return false;
    } else if (argc < 3) {
        msg = std::string("There should be 2 arguments:\n") +
                          "list of integers and number," +
                          "which possition you want to find there.\n";
        return false;
    }

    return true;
}

std::string InterpSearchApp::operator()(int argc, const char** argv) {
    if (!AreArgumentsValid(argc, argv)) {
         return msg;
    }

    int value;
    int length = argc - 2;
    std::vector<int> vect(length);
    try {
       for (int i = 0; i < length ; i++)
            vect[i] = std::stoi(argv[i+1]);

        value = std::stoi(argv[length+1]);
    }
    catch (const std::invalid_argument& ia) {
        return std::string("ERROR: Wrong number format!\n") + ia.what() + "\n";
    }

    if (xab::interpSearch(vect, value) == -1)
        msg = "Element " + std::to_string(value) + " hasn't been found.\n";
    else
        msg = "Element " + std::to_string(value) + " is at "
               + std::to_string(xab::interpSearch(vect, value)) + " place.\n";

    return msg;
}
