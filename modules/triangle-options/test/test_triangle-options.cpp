// Copyright 2018 Zinoviev Vladimir

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/triangle-options.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class TriangleOptionsTest : public ::testing::Test {
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
    TriangleOptions app_;
    string output_;
};

TEST_F(TriangleOptionsTest, Do_Print_Help) {
    vector<string> args = {"-h"};

    Act(args);

    Assert("This is a triangle options application\\..*");
}

TEST_F(TriangleOptionsTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"-l", "1", "2"};

    Act(args);

    Assert("ERROR: Should be 7 arguments\\..*");
}

TEST_F(TriangleOptionsTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"-l", "1", "2", "1", "3", "pi", "8"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(TriangleOptionsTest, Can_Detect_Unknown_Option) {
    vector<string> args = { "-garbage", "1", "2", "1", "3", "4", "8" };

    Act(args);

    Assert("Unknown option.*");
}

TEST_F(TriangleOptionsTest, Can_Detect_Wrong_Option) {
    vector<string> args = { "garbage", "1", "2", "1", "3", "4", "8" };

    Act(args);

    Assert("Usage:.*");
}

TEST_F(TriangleOptionsTest, Can_Find_Angles) {
    vector<string> args = { "-a", "1.2", "1.3", "1.4", "1.5",
        "1.6", "1.8" };

    Act(args);

    Assert(std::string("angle 1 = 0.110657\n") +
        "angle 2 = 2.9442\n" +
        "angle 3 = 0.0867383\n");
}

TEST_F(TriangleOptionsTest, Can_Find_Lengths) {
    vector<string> args = { "-l", "1.2", "1.3", "1.4", "1.5",
        "1.6", "1.8" };

    Act(args);

    Assert(std::string("length 1_2 = 0.282843\n") +
        "length 1_3 = 0.640312\n" +
        "length 2_3 = 0.360555");
}

TEST_F(TriangleOptionsTest, Can_Find_Inscribed_Radius) {
    vector<string> args = { "-r", "1.2", "1.3", "1.4", "1.5",
        "1.6", "1.8" };

    Act(args);

    Assert("Radius Inscribed Circle = 0.0155798");
}

TEST_F(TriangleOptionsTest, Can_Find_Circumscribed_Radius) {
    vector<string> args = { "-R", "1.2", "1.3", "1.4", "1.5",
        "1.6", "1.8" };

    Act(args);

    Assert("Radius Circumscribed Circle = 1.63248");
}

TEST_F(TriangleOptionsTest, Can_Find_Square) {
    vector<string> args = { "-s", "1.2", "1.3", "1.4", "1.5",
        "1.6", "1.8"};

    Act(args);

    Assert("Square = 0.01");
}

TEST_F(TriangleOptionsTest, Can_Find_Perimeter) {
    vector<string> args = { "-p", "1.2", "1.3", "1.4", "1.5",
        "1.6", "1.8" };

    Act(args);

    Assert("Perimeter = 1.28371");
}

TEST_F(TriangleOptionsTest, Can_Find_Barycenter) {
    vector<string> args = { "-b", "1.2", "1.3", "1.4", "1.5",
        "1.6", "1.8" };

    Act(args);

    Assert("Barycenter = <1.4, 1.53333>");
}

TEST_F(TriangleOptionsTest, Can_Find_Center_Inscribed) {
    vector<string> args = { "-c", "1.2", "1.3", "1.4", "1.5",
        "1.6", "1.8" };

    Act(args);

    Assert("Center Inscribed Circle = <1.64227, 1.80637>");
}

TEST_F(TriangleOptionsTest, Can_Find_All_Options) {
    vector<string> args = { "-A", "1.2", "1.3", "1.4", "1.5",
        "1.6", "1.8"};

    Act(args);

    Assert(std::string("length 1_2 = 0.282843\n") +
        "length 1_3 = 0.640312\n" +
        "length 2_3 = 0.360555\n" +
        "angle 1 = 0.110657\n" +
        "angle 2 = 2.9442\n" +
        "angle 3 = 0.0867383\n" +
        "Radius Inscribed Circle = 0.0155798\n" +
        "Radius Circumscribed Circle = 1.63248\n" +
        "Square = 0.01\n" +
        "Perimeter = 1.28371\n" +
        "Barycenter = <1.4, 1.53333>\n" +
        "Center Inscribed Circle = <1.64227, 1.80637>");
}
