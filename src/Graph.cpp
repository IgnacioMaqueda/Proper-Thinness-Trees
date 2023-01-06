#include "Graph.h"

Graph::Graph(int v, AdjacencyList aristas) : vertices_(v), listaAdy_(std::move(aristas)) {}

int Graph::vertices() const {
    return vertices_;
}

bool Graph::areAdjacent(int v0, int v1) const {
    for (int i : listaAdy_[v0]) {
        if (i == v1) {
            return true;
        }
    }
    return false;
}

int Graph::maxDegreeVertex() const {
    int maxGrado = 0;
    int res;
    for (int i = 0; i < vertices(); ++i) {
        if (listaAdy_[i].size() > maxGrado) {
            maxGrado = listaAdy_[i].size();
            res = i;
        }
    }
    return res;
}

vector<int> Graph::orderWithDFS() const {
    vector<int> res(vertices());
    vector<bool> discovered(vertices(), false);
    int i = 0;
    stack<int> pila;
    int v;
    pila.push(0);
    while (!pila.empty()) {
        v = pila.top();
        pila.pop();
        if (not discovered[v]) {
            discovered[v] = true;
            res[i++] = v;
            for (int w : listaAdy_[v]) {
                pila.push(w);
            }
        }
    }
    return res;
}

void Graph::printGraph() const {
    cout << "Vertices: " << vertices_ << "\n";
    for (int i = 0; i < vertices_; ++i) {
        cout << i << ": [ ";
        for (int j : listaAdy_[i]) {
            cout << j << " ";
        }
        cout << "]\n";
    }
}
