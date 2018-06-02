// Copyright 2018 Tarakanov Kirill

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/avl_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class AVLTreeTest : public ::testing::Test {
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
    AVL_App app_;
    string output_;
};

TEST_F(AVLTreeTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a AVL_Tree application\\..*");
}

TEST_F(AVLTreeTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be more then 4 arguments\\..*");
}

TEST_F(AVLTreeTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "3", "pi", "2", "4", "+" "9" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(AVLTreeTest, Can_Detect_Wrong_Value_Node) {
    vector<string> args = { "tri", "1", "2", "4", "+" "9" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(AVLTreeTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "3", "1", "2", "3", "do it" "5"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(AVLTreeTest, Can_Add_Node) {
    vector<string> args = { "3", "1", "2", "3", "+", "5" };

    Act(args);

    Assert("1 2 3 5");
}

TEST_F(AVLTreeTest, Can_Remove_Node) {
    vector<string> args = { "3", "1", "2", "3", "-", "1" };

    Act(args);

    Assert("2 3");
}

TEST_F(AVLTreeTest, Can_Find_Min) {
    vector<string> args = { "4", "8", "4", "1", "9", "fmin"};

    Act(args);

    Assert("1");
}

TEST_F(AVLTreeTest, Can_Remove_Min) {
    vector<string> args = { "4", "8", "4", "1", "9", "min-" };

    Act(args);

    Assert("4 8 9");
}

TEST_F(AVLTreeTest, Can_Search_Node) {
    vector<string> args = { "4", "8", "4", "1", "9", "search", "8"};

    Act(args);

    Assert("8");
}

TEST_F(AVLTreeTest, Cant_Search_Node) {
    vector<string> args = { "4", "8", "4", "1", "9", "search", "3" };

    Act(args);

    Assert("This element not in a tree");
}


