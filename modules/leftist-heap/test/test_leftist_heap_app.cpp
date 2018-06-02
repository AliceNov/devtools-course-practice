// Copyright 2018 Okunev Boris

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/leftist_heap_app.h"

using ::testing::internal::RE;
using std::vector;

class LeftistHeapAppTest : public ::testing::Test {
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
    LeftistHeapApp app_;
    string output_;
};

TEST_F(LeftistHeapAppTest, Can_print_help) {
    vector<string> args = {};

    Act(args);
    // Act and Assert
    Assert("This is leftist heap application\\..*");
}

TEST_F(LeftistHeapAppTest, Can_Check_Too_Much_Args) {
    vector<string> args = { "merge", "(2,3)", "(3,4)", "1" };

    Act(args);

    Assert("ERROR: Too mush arguments\\..*");
}

TEST_F(LeftistHeapAppTest, Can_Detect_Wrong_Operator) {
    vector<string> args = { "mee", "(2,3)", "(3,4)"};

    Act(args);

    Assert("Wrong operation format!.*");
}

TEST_F(LeftistHeapAppTest, Can_Detect_Wrong_Heap_First_Bracket) {
    vector<string> args = { "merge", "[2,3)", "(3,4)" };

    Act(args);

    Assert("Wrong heap format!.*");
}

TEST_F(LeftistHeapAppTest, Can_Detect_Wrong_Heap_Second_Bracket) {
    vector<string> args = { "merge", "(2,3]", "(3,4)" };

    Act(args);

    Assert("Wrong heap format!.*");
}

TEST_F(LeftistHeapAppTest, Can_Detect_Wrong_Heap_Empty_Second) {
    vector<string> args = { "merge", "(]", "(3,4)" };

    Act(args);

    Assert("Wrong heap format!.*");
}

TEST_F(LeftistHeapAppTest, Can_Merge_Two_Heap) {
    vector<string> args = { "merge", "(2,4)", "(3,4)" };

    Act(args);

    Assert("2 3 4 4");
}

TEST_F(LeftistHeapAppTest, Can_Merge_Two_Empty_Heap) {
    vector<string> args = { "merge", "()", "()" };

    Act(args);

    Assert("");
}

TEST_F(LeftistHeapAppTest, Can_Insert) {
    vector<string> args = { "insert", "(1,2,5)", "(4)" };

    Act(args);

    Assert("1 2 4 5");
}

TEST_F(LeftistHeapAppTest, Can_Get_Min) {
    vector<string> args = { "minKey", "(1,2,5)" };

    Act(args);

    Assert("1");
}

TEST_F(LeftistHeapAppTest, Can_Delete_Min) {
    vector<string> args = { "deleteMin", "(1,2,5)" };

    Act(args);

    Assert("2 5");
}

TEST_F(LeftistHeapAppTest, Can_Detect_Empty_Heap_For_minKey) {
    vector<string> args = { "minKey", "()" };

    Act(args);

    Assert("Can't find minimum in empty heap");
}
