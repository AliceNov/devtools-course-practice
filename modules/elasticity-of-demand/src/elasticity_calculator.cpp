// Copyright 2018 Rodionov Fedor

#include "include/elasticity-of-demand.h"
#include "include/elasticity_calculator.h"


#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>
#include <sstream>

ElasticityCalculator::ElasticityCalculator() : message_("") {}

void ElasticityCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an elasticity calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname +
        "<operation> \n\n" +
        " <q1>\n " + " <q2>\n " + " <t1>\n " + " <t2>\n " +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '-p', '-i', '-c',\n" +
        "where is '-p' - priceElasticity" +
        "'-i' - incomeElasticity, '-c' - crossElasticity.\n";
}


bool ElasticityCalculator::validArgs(int argc,
    const char ** argv) {
    if (argc != 6 || strlen(argv[1]) != 2 || argv[1][0] != '-'
        || (strspn(&argv[1][1], "cpi") == 0)) {
        help(argv[0],
            "ERROR: Should be 5 write argument, first is -c, -p or -i.\n\n");
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

std::string ElasticityCalculator::operator()(int argc,
    const char** argv) {
    Arguments args;

    if (!validArgs(argc, argv)) {
        return message_;
    }
    try {
        args.first_param = parseDouble(argv[2]);
        args.second_param = parseDouble(argv[3]);
        args.third_param = parseDouble(argv[4]);
        args.forth_param = parseDouble(argv[5]);
    }
    catch (std::string& str) {
        return str;
    }

    Elasticity E;

    std::ostringstream stream;
    switch (argv[1][1]) {
    case 'p':
        try {
            E.PriceElasticity(args.first_param, args.second_param,
                args.third_param, args.forth_param);
            E.PriceAnswer();
            stream << "Answer = " << E.GetAns() << " "
                << "Coeff = " << E.GetCoeff();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    case 'i':
        try {
            E.IncomeElasticity(args.first_param, args.second_param,
                args.third_param, args.forth_param);
            E.IncomeAnswer();
            stream << "Answer = " << E.GetAns() << " "
                << "Coeff = " << E.GetCoeff();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    case 'c':
        try {
            E.CrossElasticity(args.first_param, args.second_param,
                args.third_param, args.forth_param);
            E.CrossAnswer();
            stream << "Answer = " << E.GetAns() << " "
                << "Coeff = " << E.GetCoeff();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
