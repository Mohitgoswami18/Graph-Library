#include "../include/graph.hpp"
#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
#include <queue>
using namespace std;

int main() {
    // Create a graph with 5 vertices
    Graph g(5, true, true);

    // Adding edges with weights
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    
    // prims function requires source and returns an integer showing the minimum cost of the spanning tree.
    int cost = g.prims(0); //this will implement prims algoritm  for the given graph.
    // Run Prim's Algorithm
    cout << "Prim's Minimum Spanning Tree Algorithm:"<<cost<< endl;

    return 0;
}
