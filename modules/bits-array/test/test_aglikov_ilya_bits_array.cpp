// Copyright 2018 Aglikov Ilya

#include <gtest/gtest.h>

#include <vector>

#include "include/bits_array.h"

TEST(Aglikov_Ilya_BitsArray, can_create_BitsArray_with_positive_length) {
    // Assert
    ASSERT_NO_THROW(BitsArray bf(3));
}

TEST(Aglikov_Ilya_BitsArray, can_get_length) {
    // Arrange
    BitsArray bf(3);

    // Assert
    EXPECT_EQ(3, bf.GetLength());
}

TEST(Aglikov_Ilya_BitsArray, new_BitsArray_is_set_to_zero) {
    // Arrange
    BitsArray bf(100);
    int sum = 0;

    // Act
    for (int i = 0; i < bf.GetLength(); i++) {
        sum += bf.GetBit(i);
    }

    // Assert
    EXPECT_EQ(0, sum);
}

TEST(Aglikov_Ilya_BitsArray, can_set_bit) {
    // Arrange
    BitsArray bf(10);

    // Act & Assert
    EXPECT_EQ(0, bf.GetBit(3));

    bf.SetBit(3);
    EXPECT_NE(0, bf.GetBit(3));
}

TEST(Aglikov_Ilya_BitsArray, can_clear_bit) {
    // Arrange
    BitsArray bf(10);
    int bitIdx = 3;

    // Act & Assert
    bf.SetBit(bitIdx);
    EXPECT_NE(0, bf.GetBit(bitIdx));

    bf.ClrBit(bitIdx);
    EXPECT_EQ(0, bf.GetBit(bitIdx));
}

TEST(Aglikov_Ilya_BitsArray, throws_when_create_bitfield_with_negative_length) {
    // Assert
    ASSERT_ANY_THROW(BitsArray bf(-3));
}

TEST(Aglikov_Ilya_BitsArray, throws_when_set_bit_with_negative_index) {
    // Arrange
    BitsArray bf(10);

    // Assert
    ASSERT_ANY_THROW(bf.SetBit(-3));
}

TEST(Aglikov_Ilya_BitsArray, throws_when_set_bit_with_too_large_index) {
    // Arrange
    BitsArray bf(10);

    // Assert
    ASSERT_ANY_THROW(bf.SetBit(11));
}

TEST(Aglikov_Ilya_BitsArray, throws_when_get_bit_with_negative_index) {
    // Arrange
    BitsArray bf(10);

    // Assert
    ASSERT_ANY_THROW(bf.GetBit(-3));
}

TEST(Aglikov_Ilya_BitsArray, throws_when_get_bit_with_too_large_index) {
    // Arrange
    BitsArray bf(10);

    // Assert
    ASSERT_ANY_THROW(bf.GetBit(11));
}

TEST(Aglikov_Ilya_BitsArray, throws_when_clear_bit_with_negative_index) {
    // Arrange
    BitsArray bf(10);

    // Assert
    ASSERT_ANY_THROW(bf.ClrBit(-3));
}

TEST(Aglikov_Ilya_BitsArray, throws_when_clear_bit_with_too_large_index) {
    // Arrange
    BitsArray bf(10);

    // Assert
    ASSERT_ANY_THROW(bf.ClrBit(11));
}

TEST(Aglikov_Ilya_BitsArray, can_compare_BitsArray_with_not_equal_size_1) {
    // Arrange
    BitsArray bf1(1), bf2(2);

    // Assert
    EXPECT_TRUE(bf1 != bf2);
}

TEST(Aglikov_Ilya_BitsArray, can_compare_BitsArray_with_not_equal_size_2) {
    // Arrange
    BitsArray bf1(1), bf2(2);

    // Assert
    EXPECT_FALSE(bf1 == bf2);
}

TEST(Aglikov_Ilya_BitsArray, can_compare_BitsArray_with_equal_size_1) {
    // Arrange
    BitsArray bf1(2), bf2(2);

    // Act
    bf1.SetBit(1);
    bf2.SetBit(1);

    // Assert
    EXPECT_FALSE(bf1 != bf2);
}

TEST(Aglikov_Ilya_BitsArray, can_compare_BitsArray_with_equal_size_2) {
    // Arrange
    BitsArray bf1(3), bf2(3);

    // Act
    bf1.SetBit(1);
    bf2.SetBit(2);

    // Assert
    EXPECT_FALSE(bf1 == bf2);
}

TEST(Aglikov_Ilya_BitsArray, can_assign_BitsArray_of_equal_size) {
    // Arrange
    const int size = 2;
    BitsArray bf1(size), bf2(size);

    // Act
    for (int i = 0; i < size; i++) {
        bf1.SetBit(i);
    }
    bf2 = bf1;

    // Assert
    EXPECT_NE(0, bf2.GetBit(0));
    EXPECT_NE(0, bf2.GetBit(1));
}

TEST(Aglikov_Ilya_BitsArray, assign_operator_changes_BitsArray_size) {
    // Arrange
    const int size1 = 2, size2 = 5;
    BitsArray bf1(size1), bf2(size2);

    // Act
    for (int i = 0; i < size1; i++) {
        bf1.SetBit(i);
    }
    bf2 = bf1;

    // Assert
    EXPECT_EQ(2, bf2.GetLength());
}

TEST(Aglikov_Ilya_BitsArray, can_assign_BitsArray_of_non_equal_size) {
    // Arrange
    const int size1 = 2, size2 = 5;
    BitsArray bf1(size1), bf2(size2);

    // Act
    for (int i = 0; i < size1; i++) {
        bf1.SetBit(i);
    }
    bf2 = bf1;

    // Assert
    EXPECT_NE(0, bf2.GetBit(0));
    EXPECT_NE(0, bf2.GetBit(1));
}

TEST(Aglikov_Ilya_BitsArray, compare_equal_BitsArray_of_equal_size) {
    // Arrange
    const int size = 2;
    BitsArray bf1(size), bf2(size);

    // Act
    for (int i = 0; i < size; i++) {
        bf1.SetBit(i);
    }
    bf2 = bf1;

    // Assert
    EXPECT_EQ(bf1, bf2);
}

TEST(Aglikov_Ilya_BitsArray, or_operator_applied_to_BitsArray_of_equal_size) {
    // Arrange
    const int size = 4;
    BitsArray bf1(size), bf2(size), expBf(size);

    // Act
    bf1.SetBit(2);  // bf1 = 0011
    bf1.SetBit(3);

    bf2.SetBit(1);  // bf2 = 0101
    bf2.SetBit(3);

    expBf.SetBit(1);  // expBf = 0111
    expBf.SetBit(2);
    expBf.SetBit(3);

    // Assert
    EXPECT_EQ(expBf, bf1 | bf2);
}

TEST(Aglikov_Ilya_BitsArray, or_operator_applied_BitsArray_non_equal_size) {
    // Arrange
    const int size1 = 4, size2 = 5;
    BitsArray bf1(size1), bf2(size2), expBf(size2);

    // Act
    bf1.SetBit(2);  // bf1 = 0011
    bf1.SetBit(3);

    bf2.SetBit(1);  // bf2 = 01010
    bf2.SetBit(3);

    expBf.SetBit(1);  // expBf = 01110
    expBf.SetBit(2);
    expBf.SetBit(3);

    // Assert
    EXPECT_EQ(expBf, bf1 | bf2);
}

TEST(Aglikov_Ilya_BitsArray, and_operator_applied_to_BitsArray_of_equal_size) {
    // Arrange
    const int size = 4;
    BitsArray bf1(size), bf2(size), expBf(size);

    // Act
    bf1.SetBit(2);  // bf1 = 0011
    bf1.SetBit(3);

    bf2.SetBit(1);  // bf2 = 0101
    bf2.SetBit(3);

    expBf.SetBit(3);  // expBf = 0001

    // Assert
    EXPECT_EQ(expBf, bf1 & bf2);
}

TEST(Aglikov_Ilya_BitsArray, and_operator_applied_size_BitsArray) {
    // Arrange
    const int size1 = 4, size2 = 5;
    BitsArray bf1(size1), bf2(size2), expBf(size2);

    // Act
    bf1.SetBit(2);  // bf1 = 0011
    bf1.SetBit(3);

    bf2.SetBit(1);  // bf2 = 01010
    bf2.SetBit(3);

    expBf.SetBit(1);  // expBf = 00010
    expBf.SetBit(2);
    expBf.SetBit(3);

    // Assert
    EXPECT_EQ(expBf, bf1 | bf2);
}

TEST(Aglikov_Ilya_BitsArray, can_invert_BitsArray) {
    // Arrange
    const int size = 2;
    BitsArray bf(size), negBf(size), expNegBf(size);

    // Act
    bf.SetBit(1);  // bf = 01
    negBf = ~bf;

    expNegBf.SetBit(0);  // expNegBf = 10

    // Assert
    EXPECT_EQ(expNegBf, negBf);
}

TEST(Aglikov_Ilya_BitsArray, can_invert_large_BitsArray) {
    // Arrange
    const int size = 38;
    BitsArray bf(size), negBf(size), expNegBf(size);

    // Act
    bf.SetBit(35);
    negBf = ~bf;

    for (int i = 0; i < size; i++)
        expNegBf.SetBit(i);
    expNegBf.ClrBit(35);

    // Assert
    EXPECT_EQ(expNegBf, negBf);
}

TEST(Aglikov_Ilya_BitsArray, can_invert_many_random_bits_BitsArray) {
    // Arrange
    const int size = 38;
    BitsArray bf(size), negBf(size), expNegBf(size);
    std::vector<int> bits;
    bits.push_back(0);
    bits.push_back(1);
    bits.push_back(14);
    bits.push_back(16);
    bits.push_back(33);
    bits.push_back(37);

    // Act
    for (unsigned int i = 0; i < bits.size(); i++)
        bf.SetBit(bits[i]);

    negBf = ~bf;

    for (int i = 0; i < size; i++)
        expNegBf.SetBit(i);
    for (unsigned int i = 0; i < bits.size(); i++)
        expNegBf.ClrBit(bits[i]);

    // Assert
    EXPECT_EQ(expNegBf, negBf);
}

TEST(Aglikov_Ilya_BitsArray, BitsArray_with_different_bits_are_not_equal) {
    // Arrange
    const int size = 4;
    BitsArray bf1(size), bf2(size);

    // Act
    bf1.SetBit(1);
    bf1.SetBit(3);

    bf2.SetBit(1);
    bf2.SetBit(2);

    // Assert
    EXPECT_NE(bf1, bf2);
}

TEST(Aglikov_Ilya_BitsArray, can_clear_a_bit_twice) {
    // Arrange
    const int size = 3;
    BitsArray bf1(3);
    BitsArray bf2(bf1);  // bf2 = 000

    // Act
    bf1.SetBit(1);  // bf1 = 010
    bf1.ClrBit(1);
    bf1.ClrBit(1);  // bf1 = 000

    // Assert
    EXPECT_EQ(bf1, bf2);
}
