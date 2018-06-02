// Copyright 2018 Kudalin Roman

#include <string>
#include <exception>
#include <sstream>
#include <fstream>
#include <vector>

#include "include/PrimeNumbers.h"
#include "include/prime-numbers-app.h"

PrimeNumbersApp::PrimeNumbersApp() : message_("") {}

void PrimeNumbersApp::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a prime numbers application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <left_border> <right_border> " +
        "<output_file_name>\n\n" +

        "Where the first two arguments are non-negative integer " +
        "numbers and <output_file_name> is the filename where you " +
        "want to save found numbers.\n";
}

bool PrimeNumbersApp::ValidateNumerOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 4) {
        Help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    int value = std::stoi(std::string(arg));
    return value;
}

std::string PrimeNumbersApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumerOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.left_border      = parseInt(argv[1]);
        args.right_border     = parseInt(argv[2]);
        args.output_file_name = argv[3];
    }
    catch (std::exception& exc) {
        return std::string("Wrong format or value is out of range");
    }

    try {
        PrimeNumbers pn(args.left_border, args.right_border);
        std::vector<int> prime_numbers = pn.FindPrimeNums();

        std::ostringstream stream;

        std::ofstream output_file_stream(args.output_file_name);
        if (output_file_stream.is_open()) {
            for (auto& i : prime_numbers)
                output_file_stream << i << " ";
            output_file_stream.close();

            stream << "Successfully written to " <<
                args.output_file_name;
        } else {
            stream << "Cannot open " << args.output_file_name;
        }
        message_ = stream.str();
        return message_;
    }
    catch (const char* exc) {
        return std::string(exc);
    }
}

