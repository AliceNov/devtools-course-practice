// Copyright 2018 Novikova Alisa

#include <gtest/gtest.h>
#include <string>
#include "include/converter-numerical.h"

TEST(Numerical_Converter_Test, Can_Create_Object) {
        // Assert
        ASSERT_NO_THROW(NumericalConverter temp);
}

TEST(Numerical_Converter_Test, Can_Convert_Roman_To_Arabic1) {
        // Arrange
        std::string input = "DCXLIV";
        NumericalConverter temp;
        // Act
        double result = temp.ConvertRomanNumToArabicNumRefac(input);
        // Assert
        EXPECT_EQ(644, result);
}

TEST(Numerical_Converter_Test, Can_Convert_Roman_To_Arabic2) {
        // Arrange
        std::string input = "MMCM";
        NumericalConverter temp;
        // Act
        double result = temp.ConvertRomanNumToArabicNumRefac(input);
        // Assert
        EXPECT_EQ(2900, result);
}

TEST(Numerical_Converter_Test, Can_Convert_Roman_To_Arabic3) {
        // Arrange
        std::string input = "CDLXVI";
        NumericalConverter temp;
        // Act
        double result = temp.ConvertRomanNumToArabicNumRefac(input);
        // Assert
        EXPECT_EQ(466, result);
}

TEST(Numerical_Converter_Test, Can_Convert_Roman_To_Arabic4) {
        // Arrange
        std::string input = "IX";
        NumericalConverter temp;
        // Act
        double result = temp.ConvertRomanNumToArabicNumRefac(input);
        // Assert
        EXPECT_EQ(9, result);
}

TEST(Numerical_Converter_Test, Can_Convert_Roman_To_Arabic5) {
        // Arrange
        std::string input = "ML";
        NumericalConverter temp;
        // Act
        double result = temp.ConvertRomanNumToArabicNumRefac(input);
        // Assert
        EXPECT_EQ(1050, result);
}

TEST(Numerical_Converter_Test, Can_Convert_Roman_To_Arabic6) {
        // Arrange
        std::string input = "DC";
        NumericalConverter temp;
        // Act
        double result = temp.ConvertRomanNumToArabicNumRefac(input);
        // Assert
        EXPECT_EQ(600, result);
}

TEST(Numerical_Converter_Test, Can_Convert_Roman_To_Arabic7) {
        // Arrange
        std::string input = "MD";
        NumericalConverter temp;
        // Act
        double result = temp.ConvertRomanNumToArabicNumRefac(input);
        // Assert
        EXPECT_EQ(1500, result);
}

TEST(Numerical_Converter_Test, Can_Convert_One_To_Arabic) {
        // Arrange
        std::string input = "I";
        NumericalConverter temp;
        // Act
        double result = temp.ConvertOneToArabicNumber(input);
        // Assert
        EXPECT_EQ(1, result);
}

TEST(Numerical_Converter_Test, Can_Convert_Nine_To_Arabic) {
        // Arrange
        std::string input = "IX";
        NumericalConverter temp;
        // Act
        double result = temp.ConvertRomanNumeralToArabicNumber(input);
        // Assert
        EXPECT_EQ(9, result);
}

TEST(Numerical_Converter_Test, Can_Convert_Three_To_Arabic) {
        // Arrange
        std::string input = "III";
        NumericalConverter temp;
        // Act
        double result = temp.ConvertRomanNumeralToArabicNumber(input);
        // Assert
        EXPECT_EQ(3, result);
}

TEST(Numerical_Converter_Test, Can_Convert_One_To_Roman_Numeral) {
        // Arrange
        double input = 1;
        NumericalConverter temp;
        // Act
        std::string result = temp.ConvertOneToRomanNumeral(input);
        // Assert
        EXPECT_EQ("I", result);
}

TEST(Numerical_Converter_Test, Can_Convert_Three_To_Roman_Numeral) {
        // Arrange
        double input = 3;
        NumericalConverter temp;
        // Act
        std::string result = temp.ConvertThreeToRomanNumeral(input);
        // Assert
        EXPECT_EQ("III", result);
}

TEST(Numerical_Converter_Test, Can_Convert_To_Roman_Numeral) {
        // Arrange
        double input = 466;
        NumericalConverter temp;
        // Act
        std::string result = temp.ConvertToRomanNumeral(input);
        // Assert
        EXPECT_EQ("CDLXVI", result);
}

TEST(Numerical_Converter_Test, Can_Convert_To_Roman_Big_Numeral) {
        // Arrange
        double input = 1999;
        NumericalConverter temp;
        // Act
        std::string result = temp.ConvertToRomanNumeral(input);
        // Assert
        EXPECT_EQ("MCMXCIX", result);
}

TEST(Numerical_Converter_Test, Can_Convert_To_Roman_Big2_Numeral) {
        // Arrange
        double input = 644;
        NumericalConverter temp;
        // Act
        std::string result = temp.ConvertToRomanNumeral(input);
        // Assert
        EXPECT_EQ("DCXLIV", result);
}
