// Copyright 2018 Grishin Anton

#include "include/converter_numbers_in_words.h"
#include "include/converter_numbers_in_words_app.h"

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>
#include <sstream>

NumberInWords::NumberInWords() : message_("") {}

void NumberInWords::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a number in words converter application.\n\n" +
          "Please provide argument in the following format:\n\n"+

          "  $ " + appname + " <number> " +
          "\n\n" +

          "Where argument is integer number" +
          ".\n";
}

bool NumberInWords::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 2) {
        help(argv[0], "ERROR: Should be 1 argument.\n\n");
        return false;
    }
    return true;
}

double parseInt(const char* arg) {
    char* end;
    double value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}



std::string NumberInWords::operator()(int argc, const char** argv) {
    int argument;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        argument = parseInt(argv[1]);
    }
    catch(std::string& str) {
        return str;
    }

    ConverterNumbersInWords niw;

    niw.SetNumber(argument);
    std::ostringstream stream;

    std::string result;
    try {
        result = niw.ConvertToWords();
        stream << "Result: " << result;
    }
    catch (std::string& str) {
        return str;
    }

    message_ = stream.str();

    return message_;
}
