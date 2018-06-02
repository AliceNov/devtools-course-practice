// Copyright 2018 Aglikov Ilya

#include "include/bits_array.h"

#include <stdexcept>

int bitSize = sizeof(unsigned int) * 8;  // bitSize = unsigned intbitSize

BitsArray::BitsArray(int len) {
    if (len > 0) {
        BitLen = len;
        MemLen = (BitLen % bitSize) ?
            (BitLen / bitSize + 1) : (BitLen / bitSize);
        pMem = new unsigned int[MemLen];
        for (int i = 0; i < MemLen; i++)
            pMem[i] = 0;
    } else {
        throw std::invalid_argument("Invalid argument in constructor!");
    }
}

BitsArray::BitsArray(const BitsArray &bf) {  // конструктор копирования
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new unsigned int[MemLen];
    for (int i = 0; i < MemLen; i++)
        pMem[i] = bf.pMem[i];
}

BitsArray::~BitsArray() {
    delete[] pMem;
}

int BitsArray::GetMemIndex(const int n) const {  // индекс Мем для бита n
    return (n / bitSize);
}

// битовая маска для бита n
unsigned int BitsArray::GetMemMask(const int n) const {
    unsigned int mask = 1 << n % bitSize;
    return mask;
}

// доступ к битам битового поля

int BitsArray::GetLength(void) const {  // получить длину (к-во битов)
    return BitLen;
}

void BitsArray::SetBit(const int n) {  // установить бит
    if (n > -1 && n < BitLen) {
        pMem[GetMemIndex(n)] |= GetMemMask(n);
    } else {
        throw std::out_of_range("Out of range in \"SetBit\"");
    }
}

void BitsArray::ClrBit(const int n) {  // очистить бит
    if (n > -1 && n < BitLen) {
        pMem[GetMemIndex(n)] &= ~GetMemMask(n);
    } else {
        throw std::out_of_range("Out of range in \"ClrBit\"");
    }
}

int BitsArray::GetBit(const int n) const {  // получить значение бита
    if (n > -1 && n < BitLen) {
        return (pMem[GetMemIndex(n)] & GetMemMask(n)) ? 1 : 0;
    } else {
        throw std::out_of_range("Out of range in \"GetBit\"");
    }
}

// битовые операции

BitsArray& BitsArray::operator=(const BitsArray &bf) {  // присваивание
    if (this != &bf) {
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = new unsigned int[MemLen];
        for (int i = 0; i < MemLen; i++)
            pMem[i] = bf.pMem[i];
    }
    return *this;
}

bool BitsArray::operator==(const BitsArray &bf) const {  // сравнение
    if (BitLen != bf.BitLen || MemLen != bf.MemLen) {
        return false;
    } else {
        for (int i = 0; i < MemLen; i++)
            if (pMem[i] != bf.pMem[i])
                return false;
    }
    return true;
}

bool BitsArray::operator!=(const BitsArray &bf) const {  // сравнение
    if (BitLen != bf.BitLen || MemLen != bf.MemLen) {
            return true;
    } else {
        for (int i = 0; i < MemLen; i++)
            if (pMem[i] != bf.pMem[i])
                return true;
    }
    return false;
}

BitsArray BitsArray::operator|(const BitsArray &bf) {  // операция "или"
    int maxMem = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    BitsArray tmp(maxMem);
    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] = pMem[i];
    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] |= bf.pMem[i];
    return tmp;
}

BitsArray BitsArray::operator&(const BitsArray &bf) {  // операция "и"
    int maxMem = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    BitsArray tmp(maxMem);
    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] = pMem[i];
    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] &= bf.pMem[i];
    return tmp;
}

BitsArray BitsArray::operator~(void) {  // отрицание
    BitsArray tmp(BitLen);
    for (int i = 0; i < BitLen; i++)
        if (GetBit(i) == 0)
            tmp.SetBit(i);
    return tmp;
}
