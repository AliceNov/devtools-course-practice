// Copyright 2018 Zinoviev Vladimir

#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>

#include "include/Triangles.h"
#include "include/triangle-options.h"

TriangleOptions::TriangleOptions() : message_("") {}

void TriangleOptions::help(const std::string message) {
    message_ =
        message +
        "Usage:  triangles-options -[hAlarRspbc] [x1 y1 x2 y2 x3 y3]\n" +
        "\t-h       shows this help message\n" +
        "\t-A       computes all triangle values\n" +
        "\t-l       computes length of each pair of edges\n" +
        "\t-a       computes angles of each edge\n" +
        "\t-r       computes radius of inscribed circle\n" +
        "\t-R       computes radius of circumscribed circle\n" +
        "\t-s       computes triangle's square\n" +
        "\t-p       computes triangle's perimeter\n" +
        "\t-b       computes triangle's barycenter\n" +
        "\t-c       computes center of inscribed circle\n" +
        "Examples :\n" +
        "\ttopt -l 1 1 1 2 2 2\n" +
        "\ttopt -a 1 1 1 2 2 2\n";
}

bool TriangleOptions::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        message_ = std::string("Usage:  triangles-options ") +
            "-[hAlarRspbc] [x1 y1 x2 y2 x3 y3]\n";
        return false;
    } else if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help("This is a triangle options application.");
        return false;
    } else if (argc != 8) {
        help(std::string("ERROR: Should be 7 arguments.\n\n"));
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

std::string TriangleOptions::operator()(int argc, const char** argv) {
    Arguments args;

    std::ostringstream stream;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.x_1 = parseDouble(argv[2]);
        args.y_1 = parseDouble(argv[3]);
        args.x_2 = parseDouble(argv[4]);
        args.y_2 = parseDouble(argv[5]);
        args.x_3 = parseDouble(argv[6]);
        args.y_3 = parseDouble(argv[7]);

        Triangles T(
            Vertex(args.x_1, args.y_1),
            Vertex(args.x_2, args.y_2),
            Vertex(args.x_3, args.y_3));

        Vertex A;
        if (argv[1][0] == '-') {
            switch (argv[1][1]) {
            case('A'):
                stream << "length 1_2 = " << T.Get_Length_side(first, second)
                    << std::endl
                    << "length 1_3 = " << T.Get_Length_side(first, third)
                    << std::endl
                    << "length 2_3 = " << T.Get_Length_side(second, third)
                    << std::endl;
                stream << "angle 1 = " << T.Get_Angle(first)
                    << std::endl
                    << "angle 2 = " << T.Get_Angle(second)
                    << std::endl
                    << "angle 3 = " << T.Get_Angle(third)
                    << std::endl;
                stream << "Radius Inscribed Circle = "
                    << T.Get_Radius_Of_Inscribed_Circle() << std::endl;
                stream << "Radius Circumscribed Circle = "
                    << T.Get_Radius_Of_Circumscribed_Circle() << std::endl;
                stream << "Square = " << T.Get_Square() << std::endl;
                stream << "Perimeter = " << T.Get_Perimeter() << std::endl;
                A = T.Get_Barycenter();
                stream << "Barycenter = <"
                    << A.x << ", " << A.y << ">" << std::endl;
                A = T.Get_Center_Of_Inscribed_Circle();
                stream << "Center Inscribed Circle = <"
                    << A.x << ", " << A.y << ">" << std::endl;
                break;
            case('l'):
                stream << "length 1_2 = " << T.Get_Length_side(first, second)
                    << std::endl
                    << "length 1_3 = " << T.Get_Length_side(first, third)
                    << std::endl
                    << "length 2_3 = " << T.Get_Length_side(second, third)
                    << std::endl;
                break;
            case('a'):
                stream << "angle 1 = " << T.Get_Angle(first)
                    << std::endl
                    << "angle 2 = " << T.Get_Angle(second)
                    << std::endl
                    << "angle 3 = " << T.Get_Angle(third)
                    << std::endl;
                break;
            case('r'):
                stream << "Radius Inscribed Circle = "
                    << T.Get_Radius_Of_Inscribed_Circle() << std::endl;
                break;
            case('R'):
                stream << "Radius Circumscribed Circle = "
                    << T.Get_Radius_Of_Circumscribed_Circle() << std::endl;
                break;
            case('s'):
                stream << "Square = " << T.Get_Square() << std::endl;
                break;
            case('p'):
                stream << "Perimeter = " << T.Get_Perimeter() << std::endl;
                break;
            case('b'):
                A = T.Get_Barycenter();
                stream << "Barycenter = <"
                    << A.x << ", " << A.y << ">" << std::endl;
                A = T.Get_Center_Of_Inscribed_Circle();
                break;
            case('c'):
                A = T.Get_Center_Of_Inscribed_Circle();
                stream << "Center Inscribed Circle = <"
                    << A.x << ", " << A.y << ">" << std::endl;
                break;
            default:
                help(std::string("Unknown option ") + argv[1] + "\n\n");
                return message_;
            }
        } else {
            help();
            return message_;
        }
    }
    catch (std::string& str) {
        return str;
    }

    message_ = stream.str();

    return message_;
}
