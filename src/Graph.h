#ifndef PTHINNESS_TREES_GRAPH_H
#define PTHINNESS_TREES_GRAPH_H

#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include "Utils.h"

using namespace std;

class Graph {
public:
    Graph(int, AdjacencyList);

    int vertices() const;

    bool areAdjacent(int v0, int v1) const;

    int maxDegreeVertex() const;

    vector<int> orderWithDFS() const;

    void printGraph() const;

private:
    int vertices_;
    AdjacencyList listaAdy_;
};


#endif //PTHINNESS_TREES_GRAPH_H
