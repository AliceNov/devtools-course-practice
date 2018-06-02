// Copyright 2018 Aglikov Ilya

#ifndef MODULES_BITS_ARRAY_INCLUDE_BITS_ARRAY_H_
#define MODULES_BITS_ARRAY_INCLUDE_BITS_ARRAY_H_

class BitsArray {
 public:
    explicit BitsArray(int len);
    BitsArray(const BitsArray &bf);
    ~BitsArray();

    // доступ к битам
    int GetLength(void) const;      // получить длину (к-во битов)
    void SetBit(const int n);       // установить бит
    void ClrBit(const int n);       // очистить бит
    int  GetBit(const int n) const;  // получить значение бита

                                    // битовые операции
    bool operator==(const BitsArray &bf) const;  // сравнение
    bool operator!=(const BitsArray &bf) const;  // сравнение
    BitsArray& operator=(const BitsArray &bf);  // присваивание
    BitsArray  operator|(const BitsArray &bf);  // операция "или"
    BitsArray  operator&(const BitsArray &bf);  // операция "и"
    BitsArray  operator~(void);                // отрицание

 private:
    int  BitLen;  // длина битового поля - макс. к-во битов
    unsigned int *pMem;  // память для представления битового поля
    int  MemLen;  // к-во эл-тов Мем для представления бит.поля

                 // методы реализации
    int   GetMemIndex(const int n) const;  // индекс в pМем для бита n
    unsigned int GetMemMask(const int n) const;  // битовая маска для бита n
};

#endif  // MODULES_BITS_ARRAY_INCLUDE_BITS_ARRAY_H_
