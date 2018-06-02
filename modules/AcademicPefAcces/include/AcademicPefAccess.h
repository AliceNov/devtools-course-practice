// Copyright 2018 Novikova Alisa

#ifndef MODULES_ACADEMICPEFACCES_INCLUDE_ACADEMICPEFACCESS_H_
#define MODULES_ACADEMICPEFACCES_INCLUDE_ACADEMICPEFACCESS_H_

#include <string>

class AcademicPefAccess {
 public:
    AcademicPefAccess();
    std::string operator()(int argc, const char **argv);

 private:
    void help(const char *appname, const char *message = "");
    bool validateNumberOfArguments(int argc, const char **argv);
    std::string message_;
    typedef struct {
        int id;
        int amountMarks;
        int marks[255];
        std::string sName;
        std::string operation;
    } Arguments;
};

#endif  // MODULES_ACADEMICPEFACCES_INCLUDE_ACADEMICPEFACCESS_H_
