// Copyright 2018 Levitsky Ilya
#ifndef MODULES_SET_INCLUDE_BITFIELD_H_
#define MODULES_SET_INCLUDE_BITFIELD_H_

#pragma once
#include <iostream>
class bitfield{
    int* arr;
    int n;
    int sizeU = 10;
    int k;
    int MemIndex(int k);
    int Mask(int k);

 public:
    explicit bitfield(int _SizeU = 10);
    bitfield(const bitfield&);
    ~bitfield(void);

    void SetBit(int k);
    int GetBit(int k);
    void ClearBit(int k);

    bitfield operator ~();
    bitfield operator &(const bitfield&);
    bitfield operator |(const bitfield&);
    bitfield& operator =(const bitfield&);
};
#endif  // MODULES_SET_INCLUDE_BITFIELD_H_
