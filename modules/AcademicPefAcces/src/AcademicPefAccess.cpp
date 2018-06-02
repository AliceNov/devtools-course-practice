// Copyright 2018 Novikova Alisa

#include <cstring>
#include <string>
#include <sstream>
#include <cctype>

#include "include/AcademicPefAccess.h"
#include "include/Student.h"

AcademicPefAccess::AcademicPefAccess() : message_("") {}

void AcademicPefAccess::help(const char *appname,
                            const char *message) {
    message_ =
        std::string(message) +
        "This is a Calculation of student performance application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        " $ " + appname + "<operation> <id> <sName> " +
        "<amountMarks> <marks> \n\n" +

        "Where first and second arguments are string value" +
        "(first is one of medium, amount or id) " +
        "amountMarks, id and marks are non-negative integer.\n";
}

bool AcademicPefAccess::validateNumberOfArguments(int argc,
                                                 const char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != (5 + atoi(argv[4]))) {
        help(argv[0],
             "ERROR: Should be 5 + <marks>*<marks> arguments.\n\n");
        return false;
    }

    return true;
}

int parseInt(const char *arg) {
    char *end;
    int value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string parseName(const char *arg) {
    std::string op;
    for (int i = 0; arg[i] != 0; i++) {
        if (!isalpha(arg[i])) {
            throw std::string("Wrong name format!");
        }
    }

    return op;
}

std::string parseOperation(const char *arg) {
    std::string op;

    if (strcmp(arg, "medium") == 0) {
        op = "medium";
    } else if (strcmp(arg, "id") == 0) {
        op = "id";
    } else if (strcmp(arg, "amount") == 0) {
        op = "amount";
    } else {
        throw std::string("Wrong operation format!");
    }

    return op;
}

std::string AcademicPefAccess::operator()(int argc, const char **argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.operation = parseOperation(argv[1]);
        args.id = parseInt(argv[2]);
        args.sName = parseName(argv[3]);
        args.amountMarks = parseInt(argv[4]);
        for (int i = 0; i < args.amountMarks; i++) {
            args.marks[i] = parseInt(argv[i + 5]);
        }
    }
    catch (std::string &str) {
        return str;
    }

    Student calculator(args.id, args.amountMarks, args.marks, args.sName);
    std::ostringstream stream;

    if (args.operation == "medium") {
        stream << "Medium mark = " << calculator.CalculateMediumMark()
               << std::endl;
    } else if (args.operation == "id") {
        stream << "id of the student = " << calculator.GetId() << std::endl;
    } else if (args.operation == "amount") {
        stream << "Amount of marks = " << calculator.GetAmountMarks()
               << std::endl;
    }

    message_ = stream.str();

    return message_;
}
