// Copyright 2018 Grishin Anton

#ifndef MODULES_CONVERTER_NUMBERS_IN_WORDS_INCLUDE_CONVERTER_NUMBERS_IN_WORDS_APP_H_
#define MODULES_CONVERTER_NUMBERS_IN_WORDS_INCLUDE_CONVERTER_NUMBERS_IN_WORDS_APP_H_

#include <string>

class NumberInWords {
 public:
    NumberInWords();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_CONVERTER_NUMBERS_IN_WORDS_INCLUDE_CONVERTER_NUMBERS_IN_WORDS_APP_H_
