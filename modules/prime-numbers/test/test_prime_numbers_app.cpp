// Copyright 2018 Kudalin Roman

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/prime-numbers-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class PrimeNumbersAppTest : public ::testing::Test {
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
    PrimeNumbersApp app_;
    string output_;
};

TEST_F(PrimeNumbersAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a prime numbers application\\..*");
}

TEST_F(PrimeNumbersAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"10", "20"};

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(PrimeNumbersAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"aa", "bb", "out.txt"};

    Act(args);

    Assert("Wrong format or value is out of range");
}

TEST_F(PrimeNumbersAppTest, Can_Detect_Integer_Overflow) {
    vector<string> args = {"99999999999999", "999999999999999",
        "out.txt"};

    Act(args);

    Assert("Wrong format or value is out of range");
}

TEST_F(PrimeNumbersAppTest, Can_Detect_Negative_Left_Border) {
    vector<string> args = {"-10", "10", "out.txt"};

    Act(args);

    Assert("Error! Negative numbers can't be prime!");
}

TEST_F(PrimeNumbersAppTest, Can_Detect_If_Right_Border_Is_Less_Than_Left) {
    vector<string> args = {"200", "100", "out.txt"};

    Act(args);

    Assert("Error! Max can't be less than min!");
}

TEST_F(PrimeNumbersAppTest, Can_Save_Found_Numbers_To_File) {
    vector<string> args = {"2", "10", "out.txt"};

    Act(args);

    Assert("Successfully written to.*");
}

TEST_F(PrimeNumbersAppTest, Do_Print_Error_If_File_Cannot_Be_Opened) {
    vector<string> args = {"2", "10", "Nonexistent:\\/"};

    Act(args);

    Assert("Cannot open.*");
}

