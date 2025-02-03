#include "../include/graph.hpp"
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int main() {
    // Create a directed weighted graph
    Graph g(5, true, true);

    // Adding edges with weights
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    // Run Bellman-Ford Algorithm
    int source = 0;
    vector<int> distance;
    // bellmen_ford function requires source and returns an vector containing the shorted path from the source.
    distance = g.bellmen_ford(source);  // this will implement bellmen ford algoritm  for the given graph.

    cout << "bellmen Ford's Shortest Path Algorithm:" << endl;
    for (int i=0;i<9;i++) {
        if (distance[i]==INT_MAX) {
            cout<<i<<":Not reachable"<<endl;
        } else {
            cout<<i<<":"<<distance[i]<<endl;
        }
    }
    return 0;
}
