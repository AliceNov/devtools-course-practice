// Copyright 2018 Rodionov Fedor

#ifndef MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_CALCULATOR_H_
#define MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_CALCULATOR_H_

#include <string>

class ElasticityCalculator {
 public:
    ElasticityCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validArgs(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double first_param;
        double second_param;
        double third_param;
        double forth_param;
    } Arguments;
};

#endif  // MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_CALCULATOR_H_
