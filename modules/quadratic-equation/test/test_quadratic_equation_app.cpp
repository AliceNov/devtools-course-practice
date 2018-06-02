// Copyright 2018 Tipanov Daniil

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/quadratic-equation-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class QuadraticEquationAppTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }
        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
 private:
        QuadraticEquationApp app_;
        string output_;
};

TEST_F(QuadraticEquationAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a quadratic equation application\\..*");
}

TEST_F(QuadraticEquationAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"10", "20"};

    Act(args);

    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(QuadraticEquationAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"aa", "bb", "cc", "out.txt"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(QuadraticEquationAppTest, Can_Save_Found_Numbers_To_File) {
    vector<string> args = {"2", "10", "3", "out.txt"};

    Act(args);

    Assert("Successfully written to.*");
}

TEST_F(QuadraticEquationAppTest, Do_Print_Error_If_File_Cannot_Be_Opened) {
    vector<string> args = {"2", "10", "3", "Nonexistent:\\/"};

    Act(args);

    Assert("Cannot open.*");
}

TEST_F(QuadraticEquationAppTest, Can_Detect_Zero_Quadratic_Coefficient) {
    vector<string> args = {"0", "10", "3", "out.txt"};

    Act(args);

    Assert("Quadratic coefficient can not be equal zero");
}

TEST_F(QuadraticEquationAppTest, Can_Detect_If_No_Real_Roots) {
    vector<string> args = {"1", "-2", "2", "out.txt"};

    Act(args);

    Assert("Quadratic equation has no real roots");
}
