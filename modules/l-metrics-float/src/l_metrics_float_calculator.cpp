// Copyright 2018 Galochkin Boris

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include "include/l_metrics_float_calculator.h"

LMetricsFloatCalculator::LMetricsFloatCalculator() {
}

std::string LMetricsFloatCalculator::operator()(int argc, const char ** argv) {
    Arguments args = {};
    if (!parseArguments(argc, argv, &args))
        return message_;
    std::stringstream ss;
    switch (args.mode) {
    case Mode::Linf:
        ss << LMetricsFloat::LinfVecDistance(args.vec1, args.vec2);
        break;
    case Mode::L1:
        ss << LMetricsFloat::L1VecDistance(args.vec1, args.vec2);
        break;
    case Mode::L2:
        ss << LMetricsFloat::L2VecDistance(args.vec1, args.vec2);
        break;
    case Mode::L3:
        ss << LMetricsFloat::L3VecDistance(args.vec1, args.vec2);
        break;
    case Mode::L4:
        ss << LMetricsFloat::L4VecDistance(args.vec1, args.vec2);
        break;
    }
    message_ = "Distance: " + ss.str();
    return message_;
}

void LMetricsFloatCalculator::help(const char * appname, const char * message) {
    message_ = std::string(message) +
        "Please provide arguments in the following format:\n\n"

        "$ " + appname + " <distance type>\n"
        "<first vector length = n> <v1[0]> <v1[1]> ... <v1[n]>\n"
        "<second vector length = n> <v2[0]> <v2[1]> ... <v2[n]>\n\n"

        "Where <length> are integer and more then 0, "
        "vectors values are float numbers, "
        "and <distance type> is one of 'Linf', 'L1', 'L2', 'L3', 'L4'\n";
}

bool LMetricsFloatCalculator::parseArguments(int argc, const char ** argv,
                                             Arguments* out_args) {
    if (argc < 5) {
        help(argv[0]);
        return false;
    }
    auto mode = std::string(argv[1]);
    if (mode == "Linf") {
        out_args->mode = Mode::Linf;
    } else if (mode == "L1") {
        out_args->mode = Mode::L1;
    } else if (mode == "L2") {
        out_args->mode = Mode::L2;
    } else if (mode == "L3") {
        out_args->mode = Mode::L3;
    } else if (mode == "L4") {
        out_args->mode = Mode::L4;
    } else {
        help(argv[0], "ERROR: Bad distance type!\n\n");
        return false;
    }
    try {
        int v1_len = std::stoi(argv[2]);
        if (argc < v1_len + 4) {
            help(argv[0], "ERROR: Wrong arguments count "
                          "(first vector length)!\n\n");
            return false;
        }
        int v2_len = std::stoi(argv[3 + v1_len]);
        if (argc < v1_len + 4 + v2_len) {
            help(argv[0], "ERROR: Wrong arguments count "
                          "(second vector length)!\n\n");
            return false;
        }
        for (size_t i = 3; i < v1_len + static_cast<size_t>(3); i++)
            out_args->vec1.emplace_back(std::stof(argv[i]));
        auto max = v1_len + static_cast<size_t>(4) + v2_len;
        for (size_t i = v1_len + static_cast<size_t>(4); i < max; i++)
            out_args->vec2.emplace_back(std::stof(argv[i]));
    } catch (const std::invalid_argument& ia) {
        help(argv[0], "ERROR: Invalid arguments format!\n\n");
        return false;
    }
    return true;
}
