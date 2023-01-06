#include <iostream>
#include <sstream>
#include <vector>
#include "src/Graph.h"
#include "src/pthinness.h"

using namespace std;

void processTrees(int ammount, int vertices) {
    int num, verts, v, w;
    string line;
    for (int n = 1; n <= ammount; ++n) {
//        cerr << n << "\n";
        getline(cin, line);
        getline(cin, line);
        istringstream lineAsStream(line);
        lineAsStream >> num >> verts;
        vector<vector<int> > adjacencyList(vertices);
        if (n != num) {
            cout << "Numbers are wrong!\n";
            return;
        }
        if (verts != vertices) {
            cout << "Vertices are wrong!\n";
            return;
        }
        for (int i = 0; i < vertices; ++i) {
            getline(cin, line);
            istringstream lineAsStream(line);
            lineAsStream >> v;
            if (v != i) {
                cout << "Adjacency list is wrong!\n";
                return;
            }
            while (lineAsStream >> w) {
                adjacencyList[i].push_back(w);
            }
        }
        Graph g(vertices, adjacencyList);
        vector<int> vertexOrder = g.orderWithDFS();
        if (not pthinness(g, 3, vertexOrder)) {
            cout << "Proper Thinness greater than 3!\n";
            return;
        }
    }
}

int main() {
    processTrees(106, 10);
//    processTrees(235, 11);
//    processTrees(551, 12);
//    processTrees(1301, 13);
//    processTrees(3159, 14);
//    processTrees(7741, 15);
//    processTrees(19320, 16);
//    processTrees(48629, 17);
//    processTrees(123867, 18);
//    processTrees(317955, 19);
//    processTrees(823065, 20);
    return 0;
}
