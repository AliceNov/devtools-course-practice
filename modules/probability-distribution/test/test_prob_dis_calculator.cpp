// Copyright 2018 Lalykin Oleg

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/prob_dis_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ProbDisCalculatorTest : public ::testing::Test {
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
    ProbDisCalculator app_;
    string output_;
};

TEST_F(ProbDisCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a probability distribution calculator application\\..*");
}
TEST_F(ProbDisCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"2", "4", "0.2", "RawMoment", "0"};

    Act(args);

    Assert("ERROR: Should be other number arguments\\..*");
}
TEST_F(ProbDisCalculatorTest, Can_Detect_Wrong_Number_Of_Arguments_Format) {
    vector<string> args = { "Baga", "4", "0.2", "RawMoment", "0" };

    Act(args);

    Assert("Wrong number format!.*");
}
TEST_F(ProbDisCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "1", "Baga", "0.2", "RawMoment", "0" };

    Act(args);

    Assert("Wrong number format!.*");
}
TEST_F(ProbDisCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "1", "4", "0.2", "Baga", "0" };

    Act(args);

    Assert("Wrong operation format!");
}
TEST_F(ProbDisCalculatorTest, Can_Detect_Wrong_Level_Format) {
    vector<string> args = { "2",
        "1", "3",
        "0.2", "0.8",
        "RawMoment", "Baga" };

    Act(args);

    Assert("Wrong level format!");
}
TEST_F(ProbDisCalculatorTest, Can_Detect_Wrong_Probabilities) {
    vector<string> args = { "2",
        "1", "3",
        "0.3", "-12341",
        "RawMoment", "1" };

    Act(args);

    Assert("Invalid probabilities values");
}
TEST_F(ProbDisCalculatorTest, Can_Get_Zeroth_Raw_Moment) {
    vector<string> args = {"2",
        "1", "3",
        "0.2", "0.8",
        "RawMoment", "0"};

    Act(args);

    Assert("RawMoment = 1");
}
TEST_F(ProbDisCalculatorTest, Can_Get_Second_Raw_Moment) {
    vector<string> args = { "3",
        "1", "3", "5",
        "0.2", "0.5", "0.3",
        "RawMoment", "2"};

    Act(args);

    Assert("RawMoment = 12.2");
}
TEST_F(ProbDisCalculatorTest, Can_Get_Zeroth_Central_Moment) {
    vector<string> args = { "3",
        "1", "3", "5",
        "0.2", "0.5", "0.3",
        "CentralMoment", "0" };

    Act(args);

    Assert("CentralMoment = 1");
}
TEST_F(ProbDisCalculatorTest, Can_Get_First_Central_Moment) {
    vector<string> args = { "3",
        "1", "3", "5",
        "0.2", "0.5", "0.3",
        "CentralMoment", "1" };

    Act(args);

    Assert("CentralMoment = 0");
}
TEST_F(ProbDisCalculatorTest, Can_Get_Variance) {
    vector<string> args = { "3",
        "1", "3", "5",
        "0.2", "0.5", "0.3",
        "Variance"};

    Act(args);

    Assert("Variance = 1.96");
}
TEST_F(ProbDisCalculatorTest, Can_Get_Expected_Value) {
    vector<string> args = { "3",
        "1", "3", "5",
        "0.2", "0.5", "0.3",
        "Expected"};

    Act(args);

    Assert("Expected = 3.2");
}
