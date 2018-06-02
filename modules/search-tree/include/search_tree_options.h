// Copyright 2018 Gladyshev Alexey

#ifndef MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_OPTIONS_H_
#define MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_OPTIONS_H_

#include <string>

class SearchTreeOptions {
 public:
    SearchTreeOptions();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const std::string message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double value;
    } Arguments;
};

#endif  // MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_OPTIONS_H_
