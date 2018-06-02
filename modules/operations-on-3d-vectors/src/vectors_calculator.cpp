// Copyright 2018 Kuznetsov Konstantin

#include "include/vectors_calculator.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>

#include "include/vector_3d.h"
#include "include/operations_on_3d_vectors.h"

VectorsCalculator::VectorsCalculator() : message_("") {}

void VectorsCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a vectors calculator application.\n" +
          "Please provide arguments in the following format:\n\n"+

          "operations-on-3d-vectors <operation> <v1_x> <v1_y> <v1_z> " +
          "<v2_x> <v2_y> <v2_z> \n\n" +

          "operation:\n"
          "\t-h\tshow this help message\n" +
          "\t-c\tget cross product of two vectors\n" +
          "\t-d\tget dot product of two vectors\n" +
          "\t-n\tget norm\n" +
          "\t-v\tget normalized vector\n" +
          "note: 2nd vector is not required for -n(-v) operation\n\n" +

          "Examples:\n" +
          "\toperations-on-3d-vectors -n 1 1 1\n" +
          "\toperations-on-3d-vectors -d 1 1 1 3.5 2.5 3.5";
}

bool VectorsCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if ((argc <= 4) || (strlen(argv[1]) != 2) || (argv[1][0] != '-')) {
        help(argv[0], "ERROR: invalid arguments\n\n");
        return false;
    }
    if ((strspn(&argv[1][1], "cdnv") == 0)) {
        help(argv[0], "ERROR: invalid operation\n\n");
        return false;
    } else {
        switch (argv[1][1]) {
         case 'n':
            if (argc != 5) {
                help(argv[0], "ERROR: invalid arguments\n\n");
                return false;
            }
            break;
         case 'v':
            if (argc != 5) {
                help(argv[0], "ERROR: invalid arguments\n\n");
                return false;
            }
            break;
         default:
            if (argc != 8) {
                help(argv[0], "ERROR: invalid arguments\n\n");
                return false;
            }
            break;
        }
    }

    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("ERROR: wrong number format");
    }

    return value;
}

std::string VectorsCalculator::getResult(const char arg,
                                         Vector3d v1, Vector3d v2) {
    std::ostringstream stream;
    Vector3d result;

    switch (arg) {
     case 'n':
        stream << "Norm = " << OperationsOn3dVectors::GetNorm(v1);
        break;
     case 'v':
        result = OperationsOn3dVectors::GetNormalizedVector(v1);
        stream << "Normalized vector = (" << result.x << ", "
                                          << result.y << ", "
                                          << result.z << ")";
        break;
     case 'c':
         result = OperationsOn3dVectors::CrossProduct(v1, v2);
         stream << "Cross product = (" << result.x << ", "
                                       << result.y << ", "
                                       << result.z << ")";
        break;
     case 'd':
        stream << "Dot product = " << OperationsOn3dVectors::DotProduct(v1, v2);
        break;
    }

    return stream.str();
}

std::string VectorsCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    if (argc == 5) {
        try {
            args.v1_x = parseDouble(argv[2]);
            args.v1_y = parseDouble(argv[3]);
            args.v1_z = parseDouble(argv[4]);
        }
        catch(std::string& str) {
            return str;
        }
    }

    if (argc == 8) {
        try {
            args.v1_x = parseDouble(argv[2]);
            args.v1_y = parseDouble(argv[3]);
            args.v1_z = parseDouble(argv[4]);
            args.v2_x = parseDouble(argv[5]);
            args.v2_y = parseDouble(argv[6]);
            args.v2_z = parseDouble(argv[7]);
        }
        catch(std::string& str) {
            return str;
        }
    }

    // all arguments are correct
    Vector3d v1(args.v1_x, args.v1_y, args.v1_z);
    Vector3d v2;
    if (argc == 8) {
        v2.x = args.v2_x;
        v2.y = args.v2_y;
        v2.z = args.v2_z;
    }

    message_ = getResult(argv[1][1], v1, v2);

    return message_;
}
