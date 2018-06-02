// Copyright 2018 Usova Marina

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/big_number.h"

class BigNumberTest : public ::testing::Test {
 protected:
    double epsilon = 0.001;
};

TEST_F(BigNumberTest, Can_Create_With_Default_Constructor) {
    // Act
    BigNumber z;

    // Assert
    std::vector<int> result = { 0 };
    EXPECT_EQ(result, z.getNumber());
}

TEST_F(BigNumberTest, Can_Create_With_Number) {
    // Arrange
    std::string test_number = "123456789123456789123456789123456789123456789";

    // Act
    BigNumber z(test_number);

    // Assert
    std::vector<int> result = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6,
      7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3,
      4, 5, 6, 7, 8, 9 };
    EXPECT_EQ(result, z.getNumber());
}

TEST_F(BigNumberTest, Can_Create_Via_Copying) {
    // Arrange
    BigNumber z("21346944424254731232135478265527704");

    // Act
    BigNumber z_(z);

    // Assert
    EXPECT_EQ(z_.getNumber(), z.getNumber());
}

TEST_F(BigNumberTest, Can_Set_Number) {
    // Arrange
    BigNumber z;
    std::vector<int> number_ = { 2, 1, 3, 4, 6, 9, 4, 4, 4, 2, 4, 2, 5, 4, 7,
      3, 1, 2, 3, 2, 1, 3, 5, 4, 7, 8, 2, 6, 5, 5, 2, 7, 7, 0, 4 };

    // Act
    z.setNumber(number_);

    // Assert
    EXPECT_EQ(number_, z.getNumber());
}

TEST_F(BigNumberTest, Can_Add_Big_Numbers) {
    // Arrange
    BigNumber z1("46782382032574853849803565");
    BigNumber z2("257485384980356552284513453423525");

    // Act
    BigNumber z = z1 + z2;

    // Assert
    BigNumber expected_z("257485431762738584859367303227090");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Add_Big_Numbers_With_Different_Signs_1) {
    // Arrange
    BigNumber z1("-23345678909876543578876543");
    BigNumber z2("56787654345678909876543");

    // Act
    BigNumber z = z1 + z2;

    // Assert
    BigNumber expected_z("-23288891255530864669000000");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Add_Big_Numbers_With_Different_Signs_2) {
    // Arrange
    BigNumber z1("56787654345678909876543");
    BigNumber z2("-23345678909876543578876543");

    // Act
    BigNumber z = z1 + z2;

    // Assert
    BigNumber expected_z("-23288891255530864669000000");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Add_Big_Negative_Numbers) {
    // Arrange
    BigNumber z1("-46782382032574853849803565");
    BigNumber z2("-257485384980356552284513453423525");

    // Act
    BigNumber z = z1 + z2;

    // Assert
    BigNumber expected_z("-257485431762738584859367303227090");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Difference_Big_Numbers_1) {
    // Arrange
    BigNumber z1("4563746954394453687695");
    BigNumber z2("9856528520685476802455354435464");

    // Act
    BigNumber z = z1 - z2;

    // Assert
    BigNumber expected_z("-9856528516121729848060900747769");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Difference_Big_Numbers_2) {
    // Arrange
    BigNumber z1("9856528520685476802455354435464");
    BigNumber z2("4563746954394453687695");

    // Act
    BigNumber z = z1 - z2;

    // Assert
    BigNumber expected_z("9856528516121729848060900747769");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Difference_Big_Numbers_With_Different_Signs_1) {
    // Arrange
    BigNumber z1("-5247952962546546524265");
    BigNumber z2("9856528520685476802455354435464");

    // Act
    BigNumber z = z1 - z2;

    // Assert
    BigNumber expected_z("-9856528525933429765001900959729");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Difference_Big_Numbers_With_Different_Signs_2) {
    // Arrange
    BigNumber z1("9856528520685476802455354435464");
    BigNumber z2("-5247952962546546524265");

    // Act
    BigNumber z = z1 - z2;

    // Assert
    BigNumber expected_z("9856528525933429765001900959729");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Difference_Big_Negative_Numbers) {
    // Arrange
    BigNumber z1("-4563746954394453687695");
    BigNumber z2("-9856528520685476802455354435464");

    // Act
    BigNumber z = z1 - z2;

    // Assert
    BigNumber expected_z("9856528516121729848060900747769");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Multiplication_Big_Numbers) {
    // Arrange
    BigNumber z1("9856528516121729848060900747");
    BigNumber z2("575398440289675084055");

    // Act
    BigNumber z = z1 * z2;

    // Assert
    BigNumber expected_z("5671431134847148931073745831167678482646237289085");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Multiplication_Big_Numbers_With_Different_Signs_1) {
    // Arrange
    BigNumber z1("-9856528516121729848060900747");
    BigNumber z2("575398440289675084055");

    // Act
    BigNumber z = z1 * z2;

    // Assert
    BigNumber expected_z("-5671431134847148931073745831167678482646237289085");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Multiplication_Big_Numbers_With_Different_Signs_2) {
    // Arrange
    BigNumber z1("575398440289675084055");
    BigNumber z2("-9856528516121729848060900747");

    // Act
    BigNumber z = z1 * z2;

    // Assert
    BigNumber expected_z("-5671431134847148931073745831167678482646237289085");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Multiplication_Big_Negative_Numbers) {
    // Arrange
    BigNumber z1("-9856528516121729848060900747");
    BigNumber z2("-575398440289675084055");

    // Act
    BigNumber z = z1 * z2;

    // Assert
    BigNumber expected_z("5671431134847148931073745831167678482646237289085");
    EXPECT_EQ(expected_z, z);
}

TEST_F(BigNumberTest, Can_Division_Big_Numbers) {
    // Arrange
    BigNumber z1("9469812971537775525694720659749323356437443739413630");
    BigNumber z2("2175639854932426546456455546245");

    // Act
    BigNumber z = z1 / z2;

    // Assert
    BigNumber expected_z("4352656507035673676774");
    std::string res = expected_z.getResultInString();
    EXPECT_EQ(z, expected_z);
}

TEST_F(BigNumberTest, Can_Division_Big_Numbers_With_Different_Signs_1) {
    // Arrange
    BigNumber z1("-9469812971537775525694720659749323356437443739413630");
    BigNumber z2("2175639854932426546456455546245");

    // Act
    BigNumber z = z1 / z2;

    // Assert
    BigNumber expected_z("-4352656507035673676774");
    std::string res = expected_z.getResultInString();
    EXPECT_EQ(z, expected_z);
}

TEST_F(BigNumberTest, Can_Division_Big_Numbers_With_Different_Signs_2) {
    // Arrange
    BigNumber z1("9469812971537775525694720659749323356437443739413630");
    BigNumber z2("-2175639854932426546456455546245");

    // Act
    BigNumber z = z1 / z2;

    // Assert
    BigNumber expected_z("-4352656507035673676774");
    std::string res = expected_z.getResultInString();
    EXPECT_EQ(z, expected_z);
}

TEST_F(BigNumberTest, Can_Division_Big_Negative_Numbers) {
    // Arrange
    BigNumber z1("-9469812971537775525694720659749323356437443739413630");
    BigNumber z2("-2175639854932426546456455546245");

    // Act
    BigNumber z = z1 / z2;

    // Assert
    BigNumber expected_z("4352656507035673676774");
    std::string res = expected_z.getResultInString();
    EXPECT_EQ(z, expected_z);
}

TEST_F(BigNumberTest, Can_Division_Big_Numbers_With_Rounded) {
    // Arrange
    BigNumber z1("78987654323456567654");
    BigNumber z2("9469812971537775525696306765");

    // Act
    BigNumber z = z1 / z2;

    // Assert
    BigNumber expected_z("0");
    EXPECT_EQ(z, expected_z);
}

TEST_F(BigNumberTest, Can_Division_Big_Numbers_By_Int) {
    // Arrange
    BigNumber z1("94698129715377755256963456506765");

    // Act
    BigNumber z = z1 / 5;

    // Assert
    BigNumber expected_z("18939625943075551051392691301353");
    EXPECT_EQ(z, expected_z);
}

TEST_F(BigNumberTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    BigNumber z1("324546789888765434567890987654323");
    BigNumber z2("0");

    // Act & Assert
    EXPECT_THROW(z1 / z2, std::string);
}

TEST_F(BigNumberTest, Number_Is_Equal_To_Itself) {
    // Arrange
    BigNumber z("57483923456574392084392084");

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST_F(BigNumberTest, Equal_Numbers_Are_Equal) {
    // Arrange
    BigNumber z1("2175639854932426546456455546245");
    BigNumber z2("2175639854932426546456455546245");

    // Act & Assert
    EXPECT_TRUE(z1 == z2);
}

TEST_F(BigNumberTest, Different_Numbers_Not_Equal) {
    // Arrange
    BigNumber z1("2175639854932426546456455546245");
    BigNumber z2("2175639854932426546456455546244");

    // Act & Assert
    EXPECT_TRUE(z1 != z2);
}

TEST_F(BigNumberTest, Can_Comparison_Numbers) {
    // Arrange
    BigNumber z1("2175639854935");
    BigNumber z2("2175639854932426546456455546244");

    // Act & Assert
    EXPECT_TRUE(z2 > z1);
}

TEST_F(BigNumberTest, Can_Comparison_Numbers_With_Different_Signs_1) {
    // Arrange
    BigNumber z1("2175639854935");
    BigNumber z2("-2175639854932426546456455546244");

    // Act & Assert
    EXPECT_FALSE(z2 > z1);
}

TEST_F(BigNumberTest, Can_Comparison_Numbers_With_Different_Signs_2) {
    // Arrange
    BigNumber z1("-2454356352251244");
    BigNumber z2("217563985676544935");

    // Act & Assert
    EXPECT_TRUE(z2 > z1);
}


TEST_F(BigNumberTest, Can_Return_Result_In_String) {
    // Arrange
    BigNumber z1("46782382032574853849803565");
    BigNumber z2("257485384980356552284513453423525");
    BigNumber z = z1 + z2;

    // Act
    std::string result = z.getResultInString();

    // Assert
    EXPECT_EQ(result, "257485431762738584859367303227090");
}
