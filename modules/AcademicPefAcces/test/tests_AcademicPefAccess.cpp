// Copyright 2018 Novikova Alisa

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/AcademicPefAccess.h"

using std::string;
using std::vector;
using ::testing::internal::RE;

class AcademicPefAcces_Test : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char *> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }
        const char **argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    AcademicPefAccess app_;
    string output_;
};

TEST_F(AcademicPefAcces_Test, Can_Print_Default_Help) {
    vector<string> args = {};

    Act(args);

    Assert("This is a Calculation of student performance application\\..*");
}

TEST_F(AcademicPefAcces_Test, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"id", "1", "Matyasov", "1"};

    Act(args);

    Assert("ERROR: Should be 5 +.*");
}

TEST_F(AcademicPefAcces_Test, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"id", "1", "name", "2", "pi", "3"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(AcademicPefAcces_Test, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"hth", "1", "name", "1", "2"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(AcademicPefAcces_Test, Can_Detect_Wrong_Name_Format) {
    vector<string> args = {"id", "1", "152", "1", "2"};

    Act(args);

    Assert("Wrong name format!.*");
}

TEST_F(AcademicPefAcces_Test, Can_Print_Id) {
    vector<string> args = {"id", "1", "name", "1", "2"};

    Act(args);

    Assert("id of the student = 1");
}

TEST_F(AcademicPefAcces_Test, Can_Print_medium) {
    vector<string> args = {"medium", "2", "name", "2", "5", "2"};

    Act(args);

    Assert("Medium mark = 3.5");
}

TEST_F(AcademicPefAcces_Test, Can_Print_amount) {
    vector<string> args = {"amount", "1", "name", "1", "2"};

    Act(args);

    Assert("Amount of marks = 1");
}
