// Copyright 2018 Makarin Kirill

#include "include/graph-diameter.h"

GraphDiameter::GraphDiameter(int vertexes, int** matrix) {
    if (vertexes < 0) {
        throw std::invalid_argument("Number of vertexes should be positive");
    }

    vertexNumber = vertexes;

    for (int i = 0; i < vertexNumber; i++) {
        for (int j = 0; j < vertexNumber; j++) {
            if (matrix[i][j] < 0) {
                throw std::invalid_argument("Matrix elements must be positive");
            }
        }
    }

    graph = new int*[vertexNumber];
    for (int i = 0; i < vertexNumber; i++) {
        graph[i] = new int[vertexNumber];
        for (int j = 0; j < vertexNumber; j++) {
            graph[i][j] = matrix[i][j];
        }
    }
}

GraphDiameter::~GraphDiameter() {
    for (int i = 0; i < vertexNumber; i++) {
        delete[] graph[i];
    }
    delete[] graph;
}

int GraphDiameter::GetDiameter() {
    int** edges = new int*[vertexNumber];
    for (int i = 0; i < vertexNumber; i++) {
        edges[i] = new int[vertexNumber];
    }

    for (int i = 0; i < vertexNumber; i++) {
        for (int j = 0; j < vertexNumber; j++) {
            edges[i][j] = graph[i][j];
            if (!edges[i][j]) {
                edges[i][j] = CONNECTED;
            }
        }
    }

    for (int i = 0; i < vertexNumber; i++) {
        for (int j = 0; j < vertexNumber; j++) {
            for (int k = 0; k < vertexNumber; k++) {
                if (j != k) {
                    edges[j][k] = (edges[j][k] > (edges[j][i] + edges[i][k])) ?
                    (edges[j][i] + edges[i][k]) : edges[j][k];
                }
            }
        }
    }

    for (int i = 0; i < vertexNumber; i++) {
        for (int j = 0; j < vertexNumber; j++) {
            if (edges[i][j] == CONNECTED) {
                edges[i][j] = 0;
            }
        }
    }

    int max = edges[0][1];
    for (int i = 0; i < vertexNumber; i++) {
        for (int j = 0; j < vertexNumber; j++) {
            if (edges[i][j] > max) {
                max = edges[i][j];
            }
        }
    }

    delete[] edges;
    return max;
}
