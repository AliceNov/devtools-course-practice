// Copyright 2018 Matyasov Mixail

#include"include/Student.h"
#include<string>

int Student::amountStudents = 0;
int Student::code = 0;

Student::Student(int id, int amountmarks,
int * marks, std::string sName, std::string group) {
    this->id = id;
    if (amountmarks < 0)
        amountmarks = 0;
    if (amountmarks > MAX)
        amountmarks = MAX;
    for (int i = 0; i < amountmarks; i++)
        this->marks[i] = marks[i];
    this->sName = sName;
    this->group = group;
    amountStudents++;
    this->amountMarks = amountmarks;
}

float Student::CalculateMediumMark() {
    float sum = 0;
    for (int i = 0; i < amountMarks; i++)
         sum += marks[i];
    return sum / amountMarks;
}

void Student::PrintStatistic() {
    code = 1;
    std::cout << std::endl << "---------------------------------------------";
    std::cout << std::endl;
    std::cout << "Id: " << id << std::endl;
    std::cout << "Marks: ";
    for (int i = 0; i < amountMarks; i++) {
        std::cout << marks[i];
    }
    std::cout << std::endl;
    std::cout << "sName: ";
    for (unsigned int i = 0; i < sName.length(); i++) {
         std::cout << sName[i];
    }
    std::cout << std::endl;

    float mediumMark = CalculateMediumMark();
    std::cout << "MediumMark: " << mediumMark << std::endl;
    std::cout << "Group: ";
    for (unsigned int i = 0; i < group.length(); i++)
        std::cout << group[i];
    std::cout << std::endl;
    PrintStatus();
    std::cout << "---------------------------------------------" << std::endl;
    code = 0;
}

void Student::PrintStatus() {
    code = 1;
    std::cout << "Status: ";
    float mark = CalculateMediumMark();
    if (mark >= 4.5 && mark <= 5)
        std::cout << "Excellent";
    else if (mark >= 3.5 && mark < 4.5)
        std::cout << "Good";
    else if (mark >= 2.5 && mark < 3.5)
        std::cout << "Bad";
    else
        std::cout << "Very bad";
    std::cout << std::endl;
    code = 0;
}

Student Student::operator=(const Student & st) {
    id = st.id;
    amountMarks = st.amountMarks;
    amountStudents = st.amountStudents + 1;
    sName = st.sName;
    group = st.group;
    code = st.code;

    for (int i = 0; i < amountMarks; i++)
        marks[i] = st.marks[i];

    return *this;
}
