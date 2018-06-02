// Copyright 2018 Makarin Kirill

#ifndef MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_H_
#define MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_H_

#include <stdexcept>

class GraphDiameter {
 private:
    const int CONNECTED = 1000;
    int vertexNumber;
    int ** graph;
 public:
    explicit GraphDiameter(int vertexes = 0, int** matrix = nullptr);
    ~GraphDiameter();

    int GetDiameter();
};

#endif  // MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_H_
