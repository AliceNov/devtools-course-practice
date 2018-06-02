// Copyright 2018 Gladyshev Alexey

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/search_tree_options.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class SearchTreeAppTest : public ::testing::Test {
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
    SearchTreeOptions app_;
    string output_;
};

TEST_F(SearchTreeAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("Usage:  search-tree-options\\..*");
}

TEST_F(SearchTreeAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2", "3"};

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(SearchTreeAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"-i", "pi"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(SearchTreeAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"-trash", "1"};

    Act(args);

    Assert("Unknown option.*");
}

TEST_F(SearchTreeAppTest, Can_Insert_Node) {
    vector<string> args = {"-i", "3"};

    Act(args);

    Assert("Insert was successful!.*");
}

TEST_F(SearchTreeAppTest, Cant_Find_Node) {
    vector<string> args = {"-f", "7"};

    Act(args);

    Assert("Tree hasn't node with this value.");
}

TEST_F(SearchTreeAppTest, Can_Find_Node) {
    vector<string> args = { "-f", "47" };

    Act(args);

    Assert("Search was successful! Found value:.*");
}

TEST_F(SearchTreeAppTest, Can_Print_Help) {
    vector<string> args = {"-h"};

    Act(args);

    Assert("This is a search tree application.*");
}

TEST_F(SearchTreeAppTest, Incorrect_Input) {
    vector<string> args = { "+i", "2" };

    Act(args);

    Assert("Usage.*");
}
