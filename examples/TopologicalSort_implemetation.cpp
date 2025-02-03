#include "../include/graph.hpp"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    // Create a directed graph with 6 vertices
    Graph g(6, true, false);  // Directed and unweighted

    // Adding edges to the graph
    g.addEdge(5, 2);  // 5 -> 2
    g.addEdge(5, 0);  // 5 -> 0
    g.addEdge(4, 0);  // 4 -> 0
    g.addEdge(4, 1);  // 4 -> 1
    g.addEdge(2, 3);  // 2 -> 3
    g.addEdge(3, 1);  // 3 -> 1

    // Perform Topological Sort
    cout << "Topological Sort of the given graph:" << endl;
    g.topSort();  //this will implement topological sort or Kanh's algorithm  for the given graph.
    return 0;
}
