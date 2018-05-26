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
