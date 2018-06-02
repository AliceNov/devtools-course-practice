// Copyright 2018 Tipanov Daniil

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APP_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APP_H_

#include <string>

class QuadraticEquationApp {
 public:
    QuadraticEquationApp();
    std::string operator()(int argc, const char** argv);
 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumerOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double aK;
        double bK;
        double cK;
        const char* output_file_name;
    } Arguments;
};

#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APP_H_
