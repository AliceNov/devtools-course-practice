// Copyright 2018 Tarakanov Kirill

#ifndef MODULES_AVL_TREE_INCLUDE_AVL_APP_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_APP_H_

#include <string>

enum operation {
    Add, Remove, FindMin, RemoveMin, Search
};

class AVL_App {
 public:
    AVL_App();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_AVL_TREE_INCLUDE_AVL_APP_H_
