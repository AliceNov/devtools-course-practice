// Copyright 2018 Konakov Alexandr

#ifndef MODULES_VOLUME_INCLUDE_VOLUME_CALCULATOR_H_
#define MODULES_VOLUME_INCLUDE_VOLUME_CALCULATOR_H_

#include <string>

class VolumeCalculator {
 public:
    VolumeCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double radius;
        double height;
    } Arguments;
};

#endif  // MODULES_VOLUME_INCLUDE_VOLUME_CALCULATOR_H_
