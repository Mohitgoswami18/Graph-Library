#include "../include/graph.hpp"
#include <iostream>
#include <queue>  // for BFS
using namespace std;

int main() {
    Graph g(6, true, false);  // Directed and unweighted

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS Traversal starting from vertex 0:" << endl;
    g.BFS(0);  // this will implement BFS method for the given graph.

    return 0;
}
