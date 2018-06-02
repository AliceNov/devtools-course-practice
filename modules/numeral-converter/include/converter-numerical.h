// Copyright 2018 Novikova Alisa

#include <iostream>
#include <string>

#ifndef MODULES_NUMERAL_CONVERTER_INCLUDE_CONVERTER_NUMERICAL_H_
#define MODULES_NUMERAL_CONVERTER_INCLUDE_CONVERTER_NUMERICAL_H_

class NumericalConverter {
 public:
        int InputNumber;
        int ArabicNumberOutput;
        std::string RomanNumeralOuput;
        NumericalConverter();

        // Functions to convert from Arabic numbers to Roman Numeral
        std::string ConvertOneToRomanNumeral(int inputNumber);
        std::string ConvertThreeToRomanNumeral(int inputNumber);
        std::string ConvertToRomanNumeral(int inputNumber);
        // Functions to convert from Roman Numeral to Arabic numbers
        int ConvertOneToArabicNumber(std::string inputString);
        int ConvertRomanNumeralToArabicNumber(std::string inputString);
        int ConvertRomanNumToArabicNumRefac(std::string inputStr);
};

#endif  // MODULES_NUMERAL_CONVERTER_INCLUDE_CONVERTER_NUMERICAL_H_
