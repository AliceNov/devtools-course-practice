// Copyright 2018 Shurygin Dmitriy

#include "include/fractional_number.h"
#include "include/fractional_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

FractionalCalculator::FractionalCalculator() : message_("") {}

void FractionalCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a fractional number calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <Val1_Numerator> <Val1_Denomenator> " +
          "<Val2_Numerator> <Val2_Denomenator> <operation>\n\n" +

          "Where all arguments are double-precision numbers, " +
          "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool FractionalCalculator::
        validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
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

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string FractionalCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.a1 = parseDouble(argv[1]);
        args.b1 = parseDouble(argv[2]);
        args.a2 = parseDouble(argv[3]);
        args.b2 = parseDouble(argv[4]);
        args.operation    = parseOperation(argv[5]);
    }
    catch(std::string& str) {
        return str;
    }

    FractionalNumber Val1;
    FractionalNumber Val2;

    Val1.setNumerator(args.a1);
    Val1.setDenominator(args.b1);
    Val2.setNumerator(args.a2);
    Val2.setDenominator(args.b2);

    FractionalNumber Val;
    std::ostringstream stream;
    switch (args.operation) {
     case '+':
        Val = Val1 + Val2;
        stream << "Numerator = " << Val.getNumerator() << " "
               << "Denominator = " << Val.getDenominator();
        break;
     case '-':
        Val = Val1 - Val2;
        stream << "Numerator = " << Val.getNumerator() << " "
               << "Denominator = " << Val.getDenominator();
        break;
     case '*':
        Val = Val1 * Val2;
        stream << "Numerator = " << Val.getNumerator() << " "
               << "Denominator = " << Val.getDenominator();
        break;
     case '/':
        try {
            Val = Val1 / Val2;
            stream << "Numerator = " << Val.getNumerator() << " "
                   << "Denominator = " << Val.getDenominator();
            break;
        }
        catch(std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
