// Copyright 2018 Fedorova Olga

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/interp_search_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class InterpSearchAppTest : public ::testing::Test {
 protected:
    void Act(vector<string> _args) {
       vector<const char*> args;

        args.push_back("app_name");
        for (size_t i = 0; i < _args.size(); ++i) {
             args.push_back(_args[i].c_str());
        }
        const char** argv = { 0 };
        if (_args.size())
            argv = &args.front();
        int argc = static_cast<int>(_args.size()) + 1;

        msg_out = app(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(msg_out, RE(expected)));
    }

 private:
    InterpSearchApp app;
    string msg_out;
};

TEST_F(InterpSearchAppTest, If_No_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("Input following arguments:*");
}

TEST_F(InterpSearchAppTest, If_Few_Arguments) {
    vector<string> args = { "1" };

    Act(args);

    Assert("There should be 2 arguments:*");
}

TEST_F(InterpSearchAppTest, If_Wrong_Number_Format) {
    vector<string> args = { "1a", "b" };

    Act(args);

    Assert("ERROR: Wrong number format.*");
}

TEST_F(InterpSearchAppTest, Cant_Find_Not_Excisting) {
    vector<string> args = { "1", "2", "3", "4" };

    Act(args);

    Assert("Element 4 hasn't been found.*");
}

TEST_F(InterpSearchAppTest, Can_Find_Element) {
    vector<string> args = { "1", "2", "3", "2" };

    Act(args);

    Assert("Element 2 is at 1 place.*");
}

TEST_F(InterpSearchAppTest, Can_Find_Element_Ifonly_1element_Array) {
    vector<string> args = { "3", "3" };

    Act(args);

    Assert("Element 3 is at 0 place.*");
}
