// Copyright 2018 Shurygin Dmitriy

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/fractional_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class FractionalCalculatorTest : public ::testing::Test {
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
    FractionalCalculator app_;
    string output_;
};

TEST_F(FractionalCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a fractional number calculator application\\..*");
}

TEST_F(FractionalCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(FractionalCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "1", "e", "2", "4", "+" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(FractionalCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "1", "1", "1", "1", "plus" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(FractionalCalculatorTest, Can_Add_Fractional) {
    vector<string> args = { "1", "5", "12", "43", "+" };

    Act(args);

    Assert("Numerator = 103 Denominator = 215");
}

TEST_F(FractionalCalculatorTest, Can_Diff_Fractional) {
    vector<string> args = { "75", "165", "87", "170", "-" };

    Act(args);

    Assert("Numerator = -107 Denominator = 1870");
}

TEST_F(FractionalCalculatorTest, Can_Mult_Fractional) {
    vector<string> args = { "0", "-3", "17", "21", "*" };

    Act(args);

    Assert("Numerator = 0 Denominator = 1");
}

TEST_F(FractionalCalculatorTest, Can_Divide_Fractional) {
    vector<string> args = { "1", "2", "3", "4", "/" };

    Act(args);

    Assert("Numerator = 2 Denominator = 3");
}

TEST_F(FractionalCalculatorTest, Can_Detect_Divide_By_Zero) {
    vector<string> args = { "27", "30", "0", "0", "/" };

    Act(args);

    Assert("Can't divide by zero");
}
