// Copyright 2018 Galochkin Boris

#ifndef MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_CALCULATOR_H_
#define MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_CALCULATOR_H_

#include <vector>
#include <string>

#include "include/l_metrics_float.h"

class LMetricsFloatCalculator {
    enum Mode {
        Linf, L1, L2, L3, L4
    };
    typedef struct {
        std::vector<float> vec1;
        std::vector<float> vec2;
        Mode mode;
    } Arguments;
 public:
    LMetricsFloatCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool parseArguments(int argc, const char** argv, Arguments* out_args);
    std::string message_;
};

#endif  // MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_CALCULATOR_H_
