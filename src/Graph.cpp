#include "Graph.h"

Graph::Graph(int v, AdjacencyList adjacencyList) : vertices_(v), adjacencyList_(std::move(adjacencyList)) {}

int Graph::vertices() const {
    return vertices_;
}

bool Graph::areAdjacent(int v0, int v1) const {
    for (int i: adjacencyList_[v0]) {
        if (i == v1) {
            return true;
        }
    }
    return false;
}

int Graph::maxDegreeVertex() const {
    unsigned int maxDegree = 0;
    int res;
    for (int i = 0; i < vertices(); ++i) {
        if (adjacencyList_[i].size() > maxDegree) {
            maxDegree = adjacencyList_[i].size();
            res = i;
        }
    }
    return res;
}

vector<int> Graph::orderWithDFS() const {
    vector<int> res(vertices());
    vector<bool> discovered(vertices(), false);
    int i = 0;
    stack<int> S;
    int v;
    S.push(0);
    while (!S.empty()) {
        v = S.top();
        S.pop();
        if (not discovered[v]) {
            discovered[v] = true;
            res[i++] = v;
            for (int w: adjacencyList_[v]) {
                S.push(w);
            }
        }
    }
    return res;
}

int Graph::obtainEndWithBFS() const {
    vector<bool> explored(vertices(), false);
    queue<int> Q;
    explored[0] = true;
    int v;
    Q.push(0);
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        for (int w: adjacencyList_[v]) {
            if (not explored[w]) {
                explored[w] = true;
                Q.push(w);
            }
        }
    }
    return v;
}

int Graph::obtainStartWithBFS(int end, vector<int> &parents) const {
    vector<bool> explored(vertices(), false);
    queue<int> Q;
    explored[end] = true;
    int v;
    Q.push(end);
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        for (int w: adjacencyList_[v]) {
            if (not explored[w]) {
                explored[w] = true;
                parents[w] = v;
                Q.push(w);
            }
        }
    }
    return v;
}

vector<int> Graph::orderWithLongestPath() const {
    int end = obtainEndWithBFS();
    vector<int> parents(vertices(), -1);
    int start = obtainStartWithBFS(end, parents);
    vector<int> res(vertices());
    vector<bool> discovered(vertices(), false);
    int i = 0;
    stack<int> S;
    int v = start;
    while (v != -1) {
        res[i++] = v;
        discovered[v] = true;
        for (int w: adjacencyList_[v]) {
            S.push(w);
        }
        v = parents[v];
    }
    while (!S.empty()) {
        v = S.top();
        S.pop();
        if (not discovered[v]) {
            discovered[v] = true;
            res[i++] = v;
            for (int w: adjacencyList_[v]) {
                S.push(w);
            }
        }
    }
    return res;
}

void Graph::printGraph() const {
    cerr << "Vertices: " << vertices_ << "\n";
    for (int i = 0; i < vertices_; ++i) {
        cerr << i << ": [ ";
        for (int j: adjacencyList_[i]) {
            cerr << j << " ";
        }
        cerr << "]\n";
    }
}
