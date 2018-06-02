// Copyright 2018 Grishin Anton

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/converter_numbers_in_words_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class NumberInWordsTest : public ::testing::Test {
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
    NumberInWords app_;
    string output_;
};

TEST_F(NumberInWordsTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a number in words converter application\\..*");
}

TEST_F(NumberInWordsTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 1 argument\\..*");
}

TEST_F(NumberInWordsTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"pi"};

    Act(args);

    Assert("Wrong number format!.*");
}


TEST_F(NumberInWordsTest, Can_Convert_Simple) {
    vector<string> args = {"6"};

    Act(args);

    Assert("Result: six");
}

TEST_F(NumberInWordsTest, Can_Detect_Negative_Number) {
    vector<string> args = {"-27"};

    Act(args);

    Assert("Input error: number must be pozitive.");
}

TEST_F(NumberInWordsTest, Can_Detect_Large_Number) {
    vector<string> args = { "1241242121" };

    Act(args);

    Assert("Input error: number is too large for our converter.");
}
