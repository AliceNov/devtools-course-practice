// Copyright 2018 Galochkin Boris

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/l_metrics_float_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class LMetricsFloatCalculatorTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

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
    LMetricsFloatCalculator app_;
    string output_;
};

TEST_F(LMetricsFloatCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("Please provide arguments in the following format:*");
}

TEST_F(LMetricsFloatCalculatorTest, Test_Bad_Mode_Type) {
    vector<string> args = { "trash", "1", "1.0", "1", "1.0" };

    Act(args);

    Assert("ERROR: Bad distance type!*");
}

TEST_F(LMetricsFloatCalculatorTest, Test_Bad_First_Vector_Length) {
    vector<string> args = { "L1", "10", "1.0", "1", "1.0" };

    Act(args);

    Assert("ERROR: Wrong arguments count \\(first vector length\\)*");
}

TEST_F(LMetricsFloatCalculatorTest, Test_Bad_Second_Vector_Length) {
    vector<string> args = { "L1", "1", "1.0", "1"};

    Act(args);

    Assert("ERROR: Wrong arguments count \\(second vector length\\)*");
}

TEST_F(LMetricsFloatCalculatorTest, Test_Invalid_Format) {
    vector<string> args = { "L1", "das", "1,0", "1", "1.0" };

    Act(args);

    Assert("ERROR: Invalid arguments format!*");
}

TEST_F(LMetricsFloatCalculatorTest, Test_Simple_Input) {
    vector<string> args = { "Linf", "1", "1,0", "1", "2.0" };

    Act(args);

    Assert("Distance: 1*");
}

TEST_F(LMetricsFloatCalculatorTest, Test_L1Distance) {
    vector<string> args = { "L1", "2", "1,0", "2.0", "1", "2.0" };

    Act(args);

    Assert("Distance: 3*");
}

TEST_F(LMetricsFloatCalculatorTest, Test_L2Distance) {
    vector<string> args = { "L2", "1", "1,0", "2", "2.0" , "3"};

    Act(args);

    Assert("Distance: 3.16*");
}

TEST_F(LMetricsFloatCalculatorTest, Test_L3Distance) {
    vector<string> args = { "L3", "1", "1,0", "4", "2.0", "2", "3", "10" };

    Act(args);

    Assert("Distance: 10.11*");
}

TEST_F(LMetricsFloatCalculatorTest, Test_L4Distance) {
    vector<string> args = { "L4", "4", "2.0", "2", "3", "5", "1", "1"};

    Act(args);

    Assert("Distance: 5.18*");
}
