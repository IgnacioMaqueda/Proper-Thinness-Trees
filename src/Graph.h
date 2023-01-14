#ifndef PTHINNESS_TREES_GRAPH_H
#define PTHINNESS_TREES_GRAPH_H

#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <algorithm>
#include "Utils.h"

using namespace std;

class Graph {
public:
    Graph(int, AdjacencyList);

    int vertices() const;

    bool areAdjacent(int v0, int v1) const;

    int maxDegreeVertex() const;

    int obtainEndWithBFS() const;

    int obtainStartWithBFS(int, vector<int> &) const;

    vector<int> orderWithDFS() const;

    vector<int> orderWithLongestPath() const;

    void printGraph() const;

private:
    int vertices_;
    AdjacencyList adjacencyList_;
};


#endif //PTHINNESS_TREES_GRAPH_H
