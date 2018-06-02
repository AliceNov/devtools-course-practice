// Copyright 2018 Novikova Alisa

#include <iostream>
#include <string>
#include "include/converter-numerical.h"


NumericalConverter::NumericalConverter() {
        InputNumber = 0;
        ArabicNumberOutput = 0;
        RomanNumeralOuput.clear();
}

std::string NumericalConverter::ConvertOneToRomanNumeral(int inputNumber) {
        while ((inputNumber -= 1) >= 0) {
                RomanNumeralOuput.append("I");
        }
        return RomanNumeralOuput;
}

std::string NumericalConverter::ConvertThreeToRomanNumeral(int inputNumber) {
        while ((inputNumber -= 1) >= 0) {
                RomanNumeralOuput.append("I");
        }
        return RomanNumeralOuput;
}

std::string NumericalConverter::ConvertToRomanNumeral(int inputNumber) {
        int m = 1000;
        int cm = 900;
        int d = 500;
        int cd = 400;
        int c = 100;
        int xc = 90;
        int l = 50;
        int xl = 40;
        int x = 10;
        int ix = 9;
        int v = 5;
        int iv = 4;
        int i = 1;
        while (inputNumber >= m) {
                RomanNumeralOuput.append("M");
                inputNumber -= m;
        }
        while (inputNumber >= cm) {
                RomanNumeralOuput.append("CM");
                inputNumber -= cm;
        }
        while (inputNumber >= d) {
                RomanNumeralOuput.append("D");
                inputNumber -= d;
        }
        while (inputNumber >= cd) {
                RomanNumeralOuput.append("CD");
                inputNumber -= cd;
        }
        while (inputNumber >= c) {
                RomanNumeralOuput.append("C");
                inputNumber -= c;
        }
        while (inputNumber >= xc) {
                RomanNumeralOuput.append("XC");
                inputNumber -= xc;
        }
        while (inputNumber>= l) {
                RomanNumeralOuput.append("L");
                inputNumber -= l;
        }
        while (inputNumber >= xl) {
                RomanNumeralOuput.append("XL");
                inputNumber -= xl;
        }
        while (inputNumber >= x) {
                RomanNumeralOuput.append("X");
                inputNumber -= x;
        }
        while (inputNumber >= ix) {
                RomanNumeralOuput.append("IX");
                inputNumber -= ix;
        }
        while (inputNumber >= v) {
                RomanNumeralOuput.append("V");
                inputNumber-= v;
        }
        while (inputNumber >= iv) {
                RomanNumeralOuput.append("IV");
                inputNumber -= m;
        }
        while (inputNumber >= i) {
                RomanNumeralOuput.append("I");
                inputNumber -= i;
        }
        return RomanNumeralOuput;
}

int NumericalConverter::ConvertOneToArabicNumber(std::string inputString) {
        if (inputString[0] == static_cast<char>('I')) {
                ArabicNumberOutput += 1;
        }
        return ArabicNumberOutput;
}

int NumericalConverter::ConvertRomanNumeralToArabicNumber(std::string inpStr) {
        for (int i = 0; i < static_cast<int>(inpStr.size()); ++i) {
                if (inpStr[i + 1] == static_cast<char>('X')) {
                        ArabicNumberOutput += 9;
                        i++;
                } else if (inpStr[i] == static_cast<char>('I')) {
                        ArabicNumberOutput += 1;
                }
        }
        return ArabicNumberOutput;
}

int NumericalConverter::ConvertRomanNumToArabicNumRefac(std::string inputStr) {
    for (int i = 0; i <static_cast<int>(inputStr.size()); ++i) {
        if (inputStr[i] != inputStr.back()) {
            if (inputStr[i] == static_cast<char>('I')) {
                if (inputStr[i + 1] != 'I') {
                    ArabicNumberOutput -= 1;
                }
            }
            if (inputStr[i] == static_cast<char>('V')) {
                ArabicNumberOutput += 5;
            }
            if (inputStr[i] == static_cast<char>('X')) {
                if (inputStr[i + 1] == 'I' || inputStr[i + 1] == 'V') {
                    ArabicNumberOutput += 10;
                } else {
                    ArabicNumberOutput -= 10;
                }
            }
            if (inputStr[i] == static_cast<char>('L')) {
                ArabicNumberOutput += 50;
            }
            if (inputStr[i] == static_cast<char>('C')) {
                if (inputStr[i + 1] == 'D' || inputStr[i + 1] == 'M') {
                    ArabicNumberOutput -= 100;
                } else {
                    ArabicNumberOutput += 100;
                }
            }
            if (inputStr[i] == static_cast<char>('D')) {
                ArabicNumberOutput += 500;
            }
            if (inputStr[i] == static_cast<char>('M')) {
                ArabicNumberOutput += 1000;
            }
            } else {
            if (inputStr[i] == static_cast<char>('I')) {
                ArabicNumberOutput += 1;
            }
            if (inputStr[i] == static_cast<char>('V')) {
                ArabicNumberOutput += 5;
            }
            if (inputStr[i] == static_cast<char>('X')) {
                ArabicNumberOutput += 10;
            }
            if (inputStr[i] == static_cast<char>('L')) {
                ArabicNumberOutput += 50;
            }
            if (inputStr[i] == static_cast<char>('C')) {
                ArabicNumberOutput += 100;
            }
            if (inputStr[i] == static_cast<char>('D')) {
                ArabicNumberOutput += 500;
            }
            if (inputStr[i] == static_cast<char>('M')) {
                ArabicNumberOutput += 1000;
            }
        }
    }
    return ArabicNumberOutput;
}
