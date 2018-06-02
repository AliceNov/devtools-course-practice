// Copyright 2018 Bolshakov Konstantin

#include <string>
#include <exception>
#include <sstream>
#include <fstream>

#include "include/Digits.h"
#include "include/Digits-app.h"

DigitsApplication::DigitsApplication() : message_("") {}

void DigitsApplication::Help(const char * appname, const char * message) {
    message_ =
        std::string(message) +
        "This is a digits application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + "<number> " +
        "<output_file_name\n\n" +
        "Number should be in non-negative integer format " +
        "<output_file_name> is the filename where you want to save result.\n";
}

bool DigitsApplication::ValidateNumberOfArguments(int argc,
    const char ** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 3) {
        Help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    int value = std::stoi(std::string(arg));
    return value;
}

std::string DigitsApplication::operator()(int argc, const char ** argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv)) return message_;
    try {
    Digits Init;
    int number = parseInt(argv[1]);
    args.output_file_name = argv[2];
    args.digit_str = Init.getNumber(number);

        std::ostringstream stream;
        std::ofstream output_file_stream(args.output_file_name);

        if (output_file_stream.is_open()) {
            output_file_stream << args.digit_str;
            output_file_stream.close();

            stream << "Successfully written to " << args.output_file_name;
        } else {
            stream << "Cannot open " << args.output_file_name;
        }

        message_ = stream.str();
        return message_;
    }
    catch (std::exception& exc) {
        return std::string("Wrong format or value is out of range");
    }
}
