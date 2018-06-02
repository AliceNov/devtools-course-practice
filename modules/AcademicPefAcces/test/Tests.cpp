// Copyright 2018 Matyasov Mixail
#include <gtest/gtest.h>
#include <string>
#include "include/Student.h"

TEST(Student, can_create_student_with_negative_amount_marks) {
    int marks[] = { 2, 4, 5, 2, 5, 5 };
    Student st(1, -1, marks, "Matyasov", "381608-2");

    EXPECT_EQ(st.GetAmountMarks(), 0);
}

TEST(Student, can_create_student_with_large_amount_marks) {
    int marks[] = { 2, 4, 5, 2, 5, 5 };
    Student st(1, MAX + 1, marks, "Matyasov", "381608-2");

    EXPECT_EQ(st.GetAmountMarks(), MAX);
}

TEST(Student, can_create_default_student) {
    Student s;

    EXPECT_EQ(s.GetId(), 0);
}

TEST(Student, can_calculate_medium_mark) {
    int marks[] = { 2, 4, 5 };
    Student st(1, 3, marks, "Volickov", "123");

    float mark = st.CalculateMediumMark();

    EXPECT_EQ(mark, (2 + 4 + 5) / (float)3);
}

TEST(Student, can_print_statistic) {
    int marks[] = { 2, 4, 5, 2, 5, 5 };
    Student st(1, 6, marks, "Matyasov", "381608-2");

    st.PrintStatistic();

    EXPECT_EQ(st.code, 0);
}

TEST(Student, can_copy_student) {
    int marks[] = { 2, 4, 5, 2, 5, 5 };
    Student st(1, 6, marks, "Matyasov", "381608-2");
    Student stud;
    stud = st;

    EXPECT_EQ(stud.GetId(), 1);
}

TEST(Student, can_print_status) {
    int marks[] = { 2 };
    Student st(1, 1, marks, "Matyasov", "381608-2");
    st.PrintStatus();
    int marks1[] = { 3 };
    Student st1(1, 1, marks1, "Matyasov", "381608-2");
    st1.PrintStatus();
    int marks2[] = { 4 };
    Student st2(1, 1, marks2, "Matyasov", "381608-2");
    st2.PrintStatus();
    int marks3[] = { 5 };
    Student st3(1, 1, marks3, "Matyasov", "381608-2");
    st3.PrintStatus();

    EXPECT_EQ(st3.code, 0);
}
