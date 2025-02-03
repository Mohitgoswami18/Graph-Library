#include "../include/graph.hpp"
#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

int main() {
    // Create a directed weighted graph
    Graph g(9, true, true);

    // Adding edges with weights
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 8, 2);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    // Run Dijkstra's Algorithm
    int source = 0;
    vector<int> distance;

    // dijkstra function requires source and returns an vector containing the shorted path from the source.
    distance = g.dijkstra(source);  //this will implement dijkstra algoritm  for the given graph.
    cout << "Dijkstra's Shortest Path Algorithm:" << endl;
    for (int i=0;i<9;i++) {
        if (distance[i]==INT_MAX) {
            cout<<i<<":Not reachable"<<endl;
        } else {
            cout<<i<<":"<<distance[i]<<endl;
        }
    }

    return 0;
}
