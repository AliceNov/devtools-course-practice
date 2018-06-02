// Copyright 2017 Khomenko Aleksei

#include "include/currency_converter.h"
#include "include/currency_converter_calc.h"

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>
#include <sstream>

CurrencyConverterCalc::CurrencyConverterCalc() : message_("") {}

void CurrencyConverterCalc::help(const char* appname, const char* message) {
    message_ =
    std::string(message) +
    "This is a currency converter application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <value> <convert function>\n\n" +

    "<value> are double-precision number, " +
    "and <convert function> is one of 'roubleToDollar'," +
    "'dollarToRouble','roubleToEuro','euroToRouble'.\n";
}

bool CurrencyConverterCalc::validateNumberOfArguments(int argc,
                                                      const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong value format!");
    }

    return value;
}

std::string parseOperation(const char* arg) {
    std::string op;
    if (strcmp(arg, "roubleToDollar") == 0) {
        op = "roubleToDollar";
    } else if (strcmp(arg, "dollarToRouble") == 0) {
        op = "dollarToRouble";
    } else if (strcmp(arg, "roubleToEuro") == 0) {
        op = "roubleToEuro";
    } else if (strcmp(arg, "euroToRouble") == 0) {
        op = "euroToRouble";
    } else if (strcmp(arg, "dollarToEuro") == 0) {
        op = "dollarToEuro";
    } else if (strcmp(arg, "euroToDollar") == 0) {
        op = "euroToDollar";
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

    std::string CurrencyConverterCalc::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.invalue = parseDouble(argv[1]);
        args.function = parseOperation(argv[2]);
    }
    catch(std::string& str) {
        return str;
    }

    double in = args.invalue;
    CurrencyConverter convert;

    std::ostringstream stream;
    while (true) {
    if (args.function == "dollarToRouble") {
        double out = convert.dollarToRouble(in);
        stream << in << " USD" << " = " << out << " RUB" <<std::endl;
        break;
    }
    if (args.function == "roubleToDollar") {
        double out = convert.roubleToDollar(in);
        stream << in << " RUB" << " = " << out << " USD" <<std::endl;
        break;
    }
    if (args.function == "roubleToEuro") {
        double out = convert.roubleToEuro(in);
        stream << in << " RUB" << " = " << out << " EUR" <<std::endl;
        break;
    }
    if (args.function == "euroToRouble") {
        double out = convert.euroToRouble(in);
        stream << in << " EUR" << " = " << out << " RUB" <<std::endl;
        break;
    }
    if (args.function == "dollarToEuro") {
        double out = convert.dollarToEuro(in);
        stream << in << " USD" << " = " << out << " EUR" <<std::endl;
        break;
    }
    if (args.function == "euroToDollar") {
        double out = convert.euroToDollar(in);
        stream << in << " EUR" << " = " << out << " USD" <<std::endl;
        break;
    }
    }
    message_ = stream.str();

    return message_;
}

