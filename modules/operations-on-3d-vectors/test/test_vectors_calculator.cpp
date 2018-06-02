// Copyright 2018 Kuznetsov Konstantin

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/vectors_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class TestVectorsCalculator : public ::testing::Test {
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
    VectorsCalculator app_;
    string output_;
};

TEST_F(TestVectorsCalculator, Can_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: invalid arguments.*");
}

TEST_F(TestVectorsCalculator, Can_Print_Help_With_Wrong_Operation) {
    // Arrange
    vector<string> args = {"-f", "1", "1", "1"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: invalid operation.*");
}

TEST_F(TestVectorsCalculator, Can_Print_Help_When_Too_Many_Arguments_1) {
    // Arrange
    vector<string> args = {"-n", "1", "1", "1", "2"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: invalid arguments.*");
}

TEST_F(TestVectorsCalculator, Can_Print_Help_When_Too_Many_Arguments_2) {
    // Arrange
    vector<string> args = {"-v", "1", "1", "1", "2"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: invalid arguments.*");
}

TEST_F(TestVectorsCalculator, Can_Print_Help_When_Not_Enough_Arguments) {
    // Arrange
    vector<string> args = {"-d", "1", "1", "1", "2", "2"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: invalid arguments.*");
}

TEST_F(TestVectorsCalculator, Can_Detect_Wrong_Number_Format_1) {
    // Arrange
    vector<string> args = {"-n", "1", "1", "pi"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: wrong number format");
}

TEST_F(TestVectorsCalculator, Can_Detect_Wrong_Number_Format_2) {
    // Arrange
    vector<string> args = {"-d", "1", "1", "1", "2.5", "2.5", "pi"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: wrong number format");
}

TEST_F(TestVectorsCalculator, Can_Get_Correct_Norm) {
    // Arrange
    vector<string> args = {"-n", "0.0", "-3.0", "4.0"};

    // Act
    Act(args);

    // Assert
    Assert("Norm = 5");
}

TEST_F(TestVectorsCalculator, Can_Get_Correct_Normalized_Vector) {
    // Arrange
    vector<string> args = {"-v", "0.0", "-3.0", "4.0"};

    // Act
    Act(args);

    // Assert
    Assert("Normalized vector = \\(0, -0.6, 0.8\\)");
}

TEST_F(TestVectorsCalculator, Can_Get_Correct_Cross_Product) {
    // Arrange
    vector<string> args = {"-c", "1", "2", "-3", "3", "-2", "5"};

    // Act
    Act(args);

    // Assert
    Assert("Cross product = \\(4, -14, -8\\)");
}

TEST_F(TestVectorsCalculator, Can_Get_Correct_Dot_Product) {
    // Arrange
    vector<string> args = {"-d", "1", "2", "1", "2", "3", "-4"};

    // Act
    Act(args);

    // Assert
    Assert("Dot product = 4");
}
