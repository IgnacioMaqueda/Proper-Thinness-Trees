#include "pthinness.h"

bool isStronglyConsistent(const Graph &g, const OrderAndPartition &op, int classes) {
    for (auto it = op.begin(); it != op.end(); ++it) {
        auto it2 = it;
        it2++;
        while (it2 != op.end() and it2->_class != it->_class) {
            it2++;
        }
        if (it2 != op.end()) {
            it2++;
            while (it2 != op.end()) {
                if (it2->_class == it->_class and g.areAdjacent(it->_vertex, it2->_vertex)) {
                    return false;
                }
                it2++;
            }
        }
        for (int i = 1; i < classes; ++i) {
            int clase = (it->_class + i) % classes;
            it2 = it;
            it2++;
            while (it2 != op.end() and (it2->_class != clase or g.areAdjacent(it->_vertex, it2->_vertex))) {
                it2++;
            }
            if (it2 != op.end()) {
                it2++;
                while (it2 != op.end()) {
                    if (it2->_class == clase and g.areAdjacent(it->_vertex, it2->_vertex)) {
                        return false;
                    }
                    it2++;
                }
            }
        }
    }
    for (auto it = op.rbegin(); it != op.rend(); ++it) {
        auto it2 = it;
        it2++;
        while (it2 != op.rend() and it2->_class != it->_class) {
            it2++;
        }
        if (it2 != op.rend()) {
            it2++;
            while (it2 != op.rend()) {
                if (it2->_class == it->_class and g.areAdjacent(it->_vertex, it2->_vertex)) {
                    return false;
                }
                it2++;
            }
        }
        for (int i = 1; i < classes; ++i) {
            int clase = (it->_class + i) % classes;
            it2 = it;
            it2++;
            while (it2 != op.rend() and (it2->_class != clase or g.areAdjacent(it->_vertex, it2->_vertex))) {
                it2++;
            }
            if (it2 != op.rend()) {
                it2++;
                while (it2 != op.rend()) {
                    if (it2->_class == clase and g.areAdjacent(it->_vertex, it2->_vertex)) {
                        return false;
                    }
                    it2++;
                }
            }
        }
    }
    return true;
}

_List_iterator<Pair> insertVertex(OrderAndPartition &op, int i, int j, int current) {
    auto it = op.begin();
    for (int k = 0; k < i; ++k) {
        it++;
    }
    return op.insert(it, {current, j});;
}

void printOrderAndPartition(const OrderAndPartition &op) {
    for (Pair p: op) {
        cout << "|" << p._vertex << "," << p._class;
    }
    cout << "|\n";
}

bool pthinnessRecursive(const Graph &g, OrderAndPartition &op, int classes, int current,
                        const vector<int> &vertexOrder) {
    if (not isStronglyConsistent(g, op, classes)) {
        return false;
    }
    if (current == g.vertices()) {
        printOrderAndPartition(op);
        return true;
    }
    for (int j = 0; j < classes; ++j) {
        for (int i = 0; i <= current; ++i) {
            auto it = insertVertex(op, i, j, vertexOrder[current]);
            if (pthinnessRecursive(g, op, classes, current + 1, vertexOrder)) {
                return true;
            }
            op.erase(it);
        }
    }
    return false;
}

bool pthinness(const Graph &g, int classes, const vector<int> &vertexOrder) {
    OrderAndPartition op;
    return pthinnessRecursive(g, op, classes, 0, vertexOrder);
}
