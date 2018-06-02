// Copyright 2018 Kudalin Roman

#ifndef MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_APP_H_
#define MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_APP_H_

#include <string>

class PrimeNumbersApp {
 public:
    PrimeNumbersApp();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumerOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int left_border;
        int right_border;
        const char* output_file_name;
    } Arguments;
};

#endif  // MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMBERS_APP_H_

