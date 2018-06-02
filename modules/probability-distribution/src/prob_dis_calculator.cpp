// Copyright 2018 Lalykin Oleg


#include "include/prob_dis_calculator.h"

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>
#include <sstream>

#include "include/probability_distribution.h"

ProbDisCalculator::ProbDisCalculator() : message_("") {}

void ProbDisCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a probability distribution calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname +
        " <sample_size> <array_values> <array_probabilities> " +
        "<characteristic> <level> \n\n" +

        "Where all arguments are double-precision numbers, " +
        "and <characteristic> is one of" +
        "'RawMoment', 'CentralMoment', 'Variance', 'Expected'.\n";
}

bool ProbDisCalculator::HaveArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}
bool ProbDisCalculator::validateNumberOfArguments(int argc,
    const char** argv, int n) {
    if ((argc != 2 * n + 4) && (argc != 2 * n + 3)) {
        help(argv[0], "ERROR: Should be other number arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

unsigned char parseChar(const char* arg) {
    char* end;
    unsigned char value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong level format!");
    }

    return value;
}


char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "RawMoment") == 0) {
        op = '1';
    } else if (strcmp(arg, "CentralMoment") == 0) {
        op = '2';
    } else if (strcmp(arg, "Variance") == 0) {
        op = '3';
    } else if (strcmp(arg, "Expected") == 0) {
        op = '4';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string ProbDisCalculator::operator()(int argc, const char** argv) {
    Arguments args;
    DescretePD dpd;
    if (!HaveArguments(argc, argv)) {
        return message_;
    }
    try {
    args.n = parseDouble(argv[1]);
    }
    catch (std::string& str) {
        return str;
    }
        if (!validateNumberOfArguments(argc, argv, args.n)) {
            return message_;
        }

    try {
        for (int i = 0; i < args.n; i++) {
            args.values.push_back(parseDouble(argv[i + 2]));
            args.probabilities.push_back(parseDouble(argv[i + 2 + args.n]));
        }
        args.operation = parseOperation(argv[2 * args.n + 2]);
        if ((args.operation != '3') && (args.operation != '4')) {
            args.level = parseChar(argv[2 * args.n + 3]);
        }
        dpd.setData(args.values, args.probabilities);
    }
    catch (std::string& str) {
        return str;
    }

    unsigned char k = args.level;

    std::ostringstream stream;
    switch (args.operation) {
    case '1':
        stream << "RawMoment = " << dpd.rawMoment(k);
        break;
    case '2':
        stream << "CentralMoment = " << dpd.centralMoment(k);
        break;
    case '3':
        stream << "Variance = " << dpd.variance();
        break;
    case '4':
        stream << "Expected = " << dpd.expectedValue();
        break;
    }
    message_ = stream.str();
    return message_;
}
