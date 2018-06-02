/* Copyright 2018 TolyaTalamanov */

#include <gtest/gtest.h>
#include <vector>
#include <functional>
#include <stdexcept>
#include "include/heap.hpp"

TEST(HeapTest, Can_Create_Empty_Heap) {
  // AAA
  ASSERT_NO_THROW(atal::heap<int> h);
}

TEST(HeapTest, Can_Create_Heap_With_Reserved_Memory) {
  // AAA
  ASSERT_NO_THROW(atal::heap<int> h(100));
}

TEST(HeapTest, Can_Create_Heap_From_Initializer_List) {
  // AAA
  ASSERT_NO_THROW(atal::heap<int> h{1});
}

TEST(HeapTest, Can_Create_Heap_From_Vector) {
  // Arrange
  std::vector<int> v {1, 4, -3, 2};

  // Act & Assert
  ASSERT_NO_THROW(atal::heap<int> h(v.begin(), v.end()));
}

TEST(HeapTest, Check_That_Empty_Heap_Is_Empty) {
  // Arrange
  atal::heap<int> h;

  // Act & Assert
  ASSERT_TRUE(h.empty());
}

TEST(HeapTest, Check_Heap_Size) {
  // Arrange
  atal::heap<int> h;

  // Act
  for (int i = 0; i < 100; ++i) {
    h.push(i);
  }

  // Assert
  EXPECT_EQ(100, h.size());
}

TEST(HeapTest, Right_Push_Element) {
  // Arrange
  atal::heap<int> h = {1, 3, 5};

  // Act
  h.push(1000);

  // Assert
  EXPECT_EQ(1000, h.top());
}

TEST(HeapTest, Right_Emplace_Element) {
  // Arrange
  atal::heap<int> h = {1, 3, 5};

  // Act
  h.emplace(1000);

  // Assert
  EXPECT_EQ(1000, h.top());
}

TEST(HeapTest, Throw_When_Get_Top_From_Empty_Heap) {
  // Arrange
  atal::heap<int> h;

  // Act & Assert
  ASSERT_ANY_THROW(h.top());
}

TEST(HeapTest, Check_Get_Top) {
  // Arrange
  atal::heap<int> h;

  // Act
  for (int i = 0; i < 4; ++i) {
    h.push(i);
  }

  // Assert
  EXPECT_EQ(3, h.top());
}

TEST(HeapTest, Can_Create_Copy_Heap) {
  // Arrange
  atal::heap<int> h {2, -5, 1, 2};

  // Act
  atal::heap<int> ch(h);

  // Assert
  EXPECT_EQ(2, ch.top());
}

TEST(HeapTest, Check_Swap_Heaps) {
  // Arrange
  atal::heap<int> h1 {2, -5, 1, 2};
  atal::heap<int> h2 {100, 3, 1000};

  // Act
  h1.swap(h2);

  // Assert
  EXPECT_EQ(2, h2.top());
  EXPECT_EQ(1000, h1.top());
}

TEST(HeapTest, Check_Assignment_Operator) {
  // Arrange
  atal::heap<int> h1 {2, -5, 1, 2};
  atal::heap<int> h2 {100, 1000, 3};

  // Act
  h1 = h2;
  // Assert
  EXPECT_EQ(1000, h1.top());
}
//
TEST(HeapTest, Can_Move_Heap) {
  // Arrange
  atal::heap<int> h {2, -5, 1, 2};

  // Act
  atal::heap<int> ch(std::move(h));

  // Assert
  EXPECT_EQ(2, ch.top());
}

TEST(HeapTest, Can_Assign_Move_Heap) {
  // Arrange
  atal::heap<int> h1 {3, 9, 15};
  atal::heap<int> h2 {5, 3, 1};

  // Act
  h2 = std::move(h1);

  // Assert
  EXPECT_EQ(15, h2.top());
}

TEST(HeapTest, Throw_When_Delete_Top_From_Empty_Heap) {
  // Arrange
  atal::heap<int> h;

  // Act & Assert
  ASSERT_NO_THROW(h.pop());
}

TEST(HeapTest, Check_Delete_Top) {
  // Arrange
  atal::heap<int> h = {3, 5, 10, 2, 1};

  // Act
  h.pop();

  // Assert
  EXPECT_EQ(5, h.top());
}

TEST(HeapTest, Check_Use_Other_Comparator) {
  // Arrange
  atal::heap<int, std::greater<int>> h = {3, 5, 10, 2, 1};

  // Act & Assert
  EXPECT_EQ(1, h.top());
}

TEST(HeapTest, Check_Set_Dimension) {
  // Arrange
  atal::heap<int> h;

  // Act
  h.setDim(3);

  // Assert
  EXPECT_EQ(3, h.getDim());
}

TEST(HeapTest, Check_Set_Invalid_Dimension) {
  // Arrange
  atal::heap<int> h;

  // Act & Assert
  EXPECT_THROW(h.setDim(-3), std::logic_error);
}

TEST(HeapTest, Check_Top_When_Dimension_Changed) {
  // Arrange
  atal::heap<int> h = {2, 5, 6, 1000, -3, 50};

  // Act
  h.setDim(5);

  // Assert
  EXPECT_EQ(h.top(), 1000);
}

TEST(HeapTest, Check_Push_With_Changed_Dimension) {
  // Arrange
  atal::heap<int> h = {2, 5, 6, 7, -3, 50};

  // Act
  h.setDim(3);
  h.push(1000);

  // Assert
  EXPECT_EQ(h.top(), 1000);
}

TEST(HeapTest, Check_Delete_Top_With_Changed_Dimension) {
  // Arrange
  atal::heap<int> h = {2, 5, 6, 7, -3, 50};

  // Act
  h.setDim(5);
  h.pop();

  // Assert
  EXPECT_EQ(h.top(), 7);
}
