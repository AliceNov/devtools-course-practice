// Copyright 2018 Bolshakov Konstantin

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/Digits-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class DigitsApplicationTest : public ::testing::Test {
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
    DigitsApplication app_;
    string output_;
};

TEST_F(DigitsApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a digits application\\..*");
}

TEST_F(DigitsApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2", "95" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(DigitsApplicationTest, Can_Detect_Wrong_Value_Format) {
    vector<string> args = { "a", "out.txt" };

    Act(args);

    Assert("Wrong format or value is out of range");
}

TEST_F(DigitsApplicationTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "99999999999999", "out.txt" };

    Act(args);

    Assert("Wrong format or value is out of range");
}

TEST_F(DigitsApplicationTest, Can_Save_Found_Numbers_To_File) {
    vector<string> args = { "910", "out.txt" };

    Act(args);

    Assert("Successfully written to.*");
}


TEST_F(DigitsApplicationTest, Can_Print_Error_If_File_Cannot_Be_Opened) {
    vector<string> args = { "910", "Nonexistent:\\/" };

    Act(args);

    Assert("Cannot open.*");
}
