// Copyright 2018 Kuznetsov Konstantin

#ifndef MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_VECTORS_CALCULATOR_H_
#define MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_VECTORS_CALCULATOR_H_

#include <string>

#include "./vector_3d.h"

class VectorsCalculator {
 public:
    VectorsCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string getResult(const char arg, Vector3d v1, Vector3d v2);
    std::string message_;
    typedef struct {
        double v1_x;
        double v1_y;
        double v1_z;
        double v2_x;
        double v2_y;
        double v2_z;
    } Arguments;
};

#endif  // MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_VECTORS_CALCULATOR_H_
