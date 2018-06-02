// Copyright 2018 Matyasov Mixail

#ifndef MODULES_ACADEMICPEFACCES_INCLUDE_STUDENT_H_
#define MODULES_ACADEMICPEFACCES_INCLUDE_STUDENT_H_
#include<iostream>
#include<string>
#include<cstdlib>

const int MAX = 255;

class Student {
 private:
    int id;
    int amountMarks;
    int marks[MAX];
    static int amountStudents;
    std::string sName;
    std::string group;
 public:
    static int code;

    float GetId() { return id; }
    int GetAmountMarks() { return amountMarks; }
    explicit Student(int = 0, int = 0, int* = 0,
    std::string = "", std::string = "");
    float CalculateMediumMark();
    void PrintStatistic();
    void PrintStatus();
    Student operator=(const Student& st);
};


#endif  // MODULES_ACADEMICPEFACCES_INCLUDE_STUDENT_H_
