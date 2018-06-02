// Copyright 2018 Rodionov Fedor

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/elasticity_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ElasticityCalculatorTest: public ::testing::Test {
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
    ElasticityCalculator app_;
    string output_;
};

TEST_F(ElasticityCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is an elasticity calculator application\\..*");
}

TEST_F(ElasticityCalculatorTest, Can_Check_Number_Of_Arguments) {
    vector<string> args = { "22", "7"};

    Act(args);

    Assert("ERROR: Should be 5 write argument, first is -c, -p or -i\\..*");
}

TEST_F(ElasticityCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "-c", "Liverpool", "will", "never", "win" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(ElasticityCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "1", "2", "3", "4", "5" };

    Act(args);

    Assert("ERROR: Should be 5 write argument, first is -c, -p or -i\\..*");
}

TEST_F(ElasticityCalculatorTest, Can_Detect_Divide_By_Zero_1) {
    vector<string> args = { "-c", "27", "30", "10", "10" };

    Act(args);

    Assert("Can't divide by zero");
}

TEST_F(ElasticityCalculatorTest, Can_Detect_Divide_By_Zero_2) {
    vector<string> args = { "-i", "5", "18", "44", "44" };

    Act(args);

    Assert("Can't divide by zero");
}

TEST_F(ElasticityCalculatorTest, Can_Detect_Divide_By_Zero_3) {
    vector<string> args = { "-p", "28", "33", "16", "16" };

    Act(args);

    Assert("Can't divide by zero");
}

TEST_F(ElasticityCalculatorTest, Can_Make_First_Operation) {
    vector<string> args = { "-p", "45", "55", "45", "55" };

    Act(args);

    Assert("Answer = unit elasticity Coeff = 1");
}

TEST_F(ElasticityCalculatorTest, Can_Make_Second_Operation) {
    vector<string> args = { "-i", "15", "35", "5", "45" };

    Act(args);

    Assert("Answer = normal goods Coeff = 0.5");
}

TEST_F(ElasticityCalculatorTest, Can_Make_Third_Operation) {
    vector<string> args = { "-c", "45", "55", "45", "55" };

    Act(args);

    Assert("Answer = goods are interchangeable Coeff = 1");
}
