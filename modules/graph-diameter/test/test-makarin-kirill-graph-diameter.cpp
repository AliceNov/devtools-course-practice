// Copyright 2018 Makarin Kirill

#include <gtest/gtest.h>
#include "include/graph-diameter.h"

TEST(GraphDiameter, Can_Create_Default_Graph) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(GraphDiameter graph);
}

TEST(GraphDiameter, Can_Create_Graph_With_Custom_Parameters) {
    // Arrange
    int** matrix = new int*[2];
    for (int i = 0; i < 2; i++) {
        matrix[i] = new int[2];
    }

    matrix[0][0] = matrix[1][0] = 1;
    matrix[1][1] = matrix[0][1] = 0;

    // Act & Assert
    ASSERT_NO_THROW(GraphDiameter graph(2, matrix));
}

TEST(GraphDiameter,
Throw_When_Trying_To_Create_Graph_With_Negative_Vertex_Number) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(GraphDiameter graph(-3));
}

TEST(GraphDiameter,
Throw_When_Trying_To_Create_Graph_From_Matrix_With_Negative_Element) {
    // Arrange
    int** matrix = new int*[2];
    for (int i = 0; i < 2; i++) {
        matrix[i] = new int[2];
    }

    matrix[0][0] = matrix[1][0] = -1;
    matrix[1][1] = matrix[0][1] = 0;

    // Act & Assert
    ASSERT_ANY_THROW(GraphDiameter graph(2, matrix));
}

TEST(GraphDiameter, Can_Get_Diameter) {
    // Arrange
    int** matrix = new int*[2];
    for (int i = 0; i < 2; i++) {
        matrix[i] = new int[2];
    }

    matrix[0][0] = matrix[1][0] = 11;
    matrix[1][1] = matrix[0][1] = 0;

    GraphDiameter graph(2, matrix);

    // Act & Assert
    ASSERT_NO_THROW(graph.GetDiameter());
}

TEST(GraphDiameter, Get_Diameter_Returns_Returns_Correct_Value) {
    // Arrange
    int** matrix = new int*[3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new int[3];
    }

    matrix[0][0] = matrix[1][1] = matrix[2][2] = 0;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][2] = 1;
    matrix[2][1] = 1;
    matrix[2][0] = matrix[0][2] = 0;

    GraphDiameter graph(3, matrix);

    // Act & Assert
    EXPECT_EQ(graph.GetDiameter(), 2);
}

TEST(GraphDiameter, Get_Diameter_Returns_Zero_If_Graph_Without_Edges) {
    // Arrange
    int** matrix = new int*[3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new int[3];
    }

    matrix[0][0] = matrix[0][1] = matrix[0][2] = 0;
    matrix[1][0] = matrix[1][1] = matrix[1][2] = 0;
    matrix[2][0] = matrix[2][1] = matrix[2][2] = 0;

    GraphDiameter graph(3, matrix);

    // Act & Assert
    EXPECT_EQ(graph.GetDiameter(), 0);
}
