// Copyright 2018 Fedorova Olga

#ifndef MODULES_INTERPOLATIONAL_SEARCH_INCLUDE_INTERP_SEARCH_APP_H_
#define MODULES_INTERPOLATIONAL_SEARCH_INCLUDE_INTERP_SEARCH_APP_H_

#include <string>

class InterpSearchApp {
 public:
    InterpSearchApp();
    std::string operator()(int argc, const char** argv);

 private:
    std::string msg;
    bool AreArgumentsValid(int argc, const char** argv);
};

#endif  // MODULES_INTERPOLATIONAL_SEARCH_INCLUDE_INTERP_SEARCH_APP_H_
