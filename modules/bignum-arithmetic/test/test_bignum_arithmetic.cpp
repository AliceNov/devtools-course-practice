// Copyright 2018 Usova Marina

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>

#include "include/bignum_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class BigNumCalculatorTest : public ::testing::Test {
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
    BigNumCalculator app_;
    string output_;
};

TEST_F(BigNumCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a big number calculator application\\..*");
}

TEST_F(BigNumCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(BigNumCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"123", "pi", "+"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(BigNumCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"123", "123", "garbage"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(BigNumCalculatorTest, Can_Add_Big_Numbers) {
    vector<string> args = {"46782382032574853849803565",
      "257485384980356552284513453423525", "+"};

    Act(args);

    Assert("Result: 257485431762738584859367303227090");
}

TEST_F(BigNumCalculatorTest, Can_Add_Big_Numbers_With_Different_Signs) {
    vector<string> args = { "-23345678909876543578876543",
      "56787654345678909876543", "+" };

    Act(args);

    Assert("Result: -23288891255530864669000000");
}


TEST_F(BigNumCalculatorTest, Can_Diff_Big_Numbers) {
    vector<string> args = {"4563746954394453687695",
      "9856528520685476802455354435464", "-"};

    Act(args);

    Assert("Result: -9856528516121729848060900747769");
}

TEST_F(BigNumCalculatorTest, Can_Diff_Big_Numbers_With_Different_Signs) {
    vector<string> args = { "-5247952962546546524265",
      "9856528520685476802455354435464", "-" };

    Act(args);

    Assert("Result: -9856528525933429765001900959729");
}

TEST_F(BigNumCalculatorTest, Can_Mult_Big_Numbers) {
    vector<string> args = {"9856528516121729848060900747",
      "575398440289675084055", "*"};

    Act(args);

    Assert("Result: 5671431134847148931073745831167678482646237289085");
}

TEST_F(BigNumCalculatorTest, Can_Divide_Big_Numbers) {
    vector<string> args = {"946981297153777552569472063256698346999966162796",
      "217563985493242654645645554", "/"};

    Act(args);

    Assert("Result: 4352656507035673676774");
}

TEST_F(BigNumCalculatorTest, Can_Detect_Divide_By_Zero) {
    vector<string> args = {"946981297153777552569472065974932335", "0", "/"};

    Act(args);

    Assert("Can't divide by zero");
}
