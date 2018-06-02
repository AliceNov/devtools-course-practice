// Copyright 2017 Khomenko Aleksei

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/currency_converter_calc.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class CurrencyConverterCalcTest : public ::testing::Test {
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
    CurrencyConverterCalc app_;
    string output_;
};

TEST_F(CurrencyConverterCalcTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a currency converter application\\..*");
}

TEST_F(CurrencyConverterCalcTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1"};

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(CurrencyConverterCalcTest, Can_Detect_Wrong_Value_Format) {
    vector<string> args = {"1.a23", "dollarToRouble"};

    Act(args);

    Assert("Wrong value format!.*");
}

TEST_F(CurrencyConverterCalcTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"5", "lolkek"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(CurrencyConverterCalcTest, Can_Dollar_To_Rouble) {
    vector<string> args = {"1", "dollarToRouble"};

    Act(args);

    Assert("1 USD = 60 RUB");
}

TEST_F(CurrencyConverterCalcTest, Can_Rouble_To_Euro) {
    vector<string> args = {"1123", "roubleToEuro"};

    Act(args);

    Assert("1123 RUB = 14.9733 EUR");
}

TEST_F(CurrencyConverterCalcTest, Can_Rouble_To_Dollar) {
    vector<string> args = {"60", "roubleToDollar"};

    Act(args);

    Assert("60 RUB = 1 USD");
}

TEST_F(CurrencyConverterCalcTest, Can_Dollar_To_Euro) {
    vector<string> args = {"1", "dollarToEuro"};

    Act(args);

    Assert("1 USD = 0.8 EUR");
}
TEST_F(CurrencyConverterCalcTest, Can_Euro_To_Dollar) {
    vector<string> args = {"1", "euroToDollar"};

    Act(args);

    Assert("1 EUR = 1.25 USD");
}
