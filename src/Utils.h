#ifndef PTHINNESS_TREES_UTILS_H
#define PTHINNESS_TREES_UTILS_H

#include <vector>
#include <list>

using namespace std;

struct Pair {
    int _vertex;
    int _class;
};

using AdjacencyList = vector<vector<int> >;
using OrderAndPartition = list<Pair>;

#endif //PTHINNESS_TREES_UTILS_H
