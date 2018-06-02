// Copyright 2018 Bolshakov Konstantin

#ifndef MODULES_DIGITS_INCLUDE_DIGITS_APP_H_
#define MODULES_DIGITS_INCLUDE_DIGITS_APP_H_

#include <iostream>

#include <string>

class DigitsApplication {
 public:
    DigitsApplication();
    std::string operator()(int argc, const char** argv);
 private:
    std::string message_;
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    typedef struct {
        std::string digit_str;
        const char* output_file_name;
    } Arguments;
};

#endif  // MODULES_DIGITS_INCLUDE_DIGITS_APP_H_

