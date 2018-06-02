// Copyright 2018 Konakov Alexandr

#include <gtest/gtest.h>

#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <vector>

#include "include/volume_calculator.h"

using std::string;
using std::vector;
using ::testing::internal::RE;

class VolumeCalculatorTest : public ::testing::Test {
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
  VolumeCalculator app_;
  string output_;
};

TEST_F(VolumeCalculatorTest, Do_Print_Help_No_Arguments) {
  vector<string> args = {};

  Act(args);

  Assert("Usage:.*");
}

TEST_F(VolumeCalculatorTest, Do_Print_Help_Corresponding_Flag) {
  vector<string> args = {"-h"};

  Act(args);

  Assert("Usage:.*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Arguments) {
  vector<string> args = {"abra", "cadabra"};

  Act(args);

  Assert("Usage:.*");
}

TEST_F(VolumeCalculatorTest, Can_Detect_Wrong_Number_Format) {
  vector<string> args = {"-s", "pi"};

  Act(args);

  Assert("Wrong number format!.*");
}

TEST_F(VolumeCalculatorTest, Can_Detect_Wrong_Primitive_Type) {
  vector<string> args = {"-z", "1"};

  Act(args);

  Assert("Usage:.*");
}

TEST_F(VolumeCalculatorTest,
Wont_Calculate_Cylinder_Volume_Odd_Parameters) {
  vector<string> args = {"-c", "1", "2", "12"};

  Act(args);

  Assert("Usage:.*");
}

TEST_F(VolumeCalculatorTest,
Wont_Calculate_Sphere_Volume_Odd_Parameters) {
  vector<string> args = {"-s", "1", "2"};

  Act(args);

  Assert("Usage:.*");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Sphere_Volume) {
  vector<string> args = {"-s", "1"};

  Act(args);

  Assert("Volume = 3.14159");
}
TEST_F(VolumeCalculatorTest,
       Cant_Calculate_Sphere_Volume_Negative_Radius) {
  vector<string> args = {"-s", "-1"};

  Act(args);

  Assert("Number can't be less then zero");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Cube_Volume) {
  vector<string> args = {"-b", "5"};

  Act(args);

  Assert("Volume = 125");
}

TEST_F(VolumeCalculatorTest, Cant_Calculate_Cube_Volume_Negative_Width) {
  vector<string> args = {"-b", "-4"};

  Act(args);

  Assert("Number can't be less then zero");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Cylinder_Volume) {
  vector<string> args = {"-c", "1", "2"};

  Act(args);

  Assert("Volume = 6.28319");
}

TEST_F(VolumeCalculatorTest,
       Cant_Calculate_Cylinder_Volume_Negative_Height) {
  vector<string> args = {"-c", "1", "-2"};

  Act(args);

  Assert("Number can't be less then zero");
}

TEST_F(VolumeCalculatorTest,
       Cant_Calculate_Cylinder_Volume_Negative_Radius) {
  vector<string> args = {"-c", "-1", "2"};

  Act(args);

  Assert("Number can't be less then zero");
}
