#ifndef PTHINNESS_TREES_PTHINNESS_H
#define PTHINNESS_TREES_PTHINNESS_H

#include <iostream>
#include <vector>
#include <list>
#include "Graph.h"

using namespace std;

bool isStronglyConsistent(const Graph &g, const OrderAndPartition &op, int classes);

OrderAndPartition insertVertex(OrderAndPartition op, int i, int j, int current);

void printOrderAndPartition(const OrderAndPartition &op);

bool pthinnessRecursive(const Graph &g, const OrderAndPartition &op, int classes, int current);

bool pthinness(const Graph &g, int clases);

bool pthinnessWithVertexOrderRecursive(const Graph &g, const OrderAndPartition &op, int classes, int current,
                                       const vector<int> &vertexOrder);

bool pthinnessWithVertexOrder(const Graph &g, int classes, const vector<int> &vertexOrder);

#endif //PTHINNESS_TREES_PTHINNESS_H
