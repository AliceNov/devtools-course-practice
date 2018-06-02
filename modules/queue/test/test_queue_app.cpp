// Copyright 2018 Aglikov Ilya

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/queue-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class QueueAppTest : public ::testing::Test {
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
    QueueApp app_;
    string output_;
};

TEST_F(QueueAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a single-threaded processor simulation\\..*");
}

TEST_F(QueueAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(QueueAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "2", "3", "4i"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(QueueAppTest, Can_Detect_Integer_Overflow) {
    vector<string> args = {"99999999999999", "999999999999999", "0.5", "0.5"};

    Act(args);

    Assert("Is out of range");
}

TEST_F(QueueAppTest, Can_Work) {
    vector<string> args = {"1000000", "25", "0.5", "0.5"};

    Act(args);

    Assert("Result of imitation:");
}
