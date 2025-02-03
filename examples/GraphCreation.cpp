#include "../include/graph.hpp"
#include <iostream>
using namespace std;

int main() {
    /*  
    Create an object of the class Graph
    Arguments: number of vertices, isDirected (TRUE for directed, FALSE for undirected),
    isWeighted (TRUE for weighted, FALSE for unweighted)
    */ 
    
    Graph directedUnweighted(6, true, false);  // Directed and unweighted
    directedUnweighted.addEdge(2, 4);          // 2 -> 4
    directedUnweighted.addEdge(1, 4);          // 1 -> 4
    directedUnweighted.addEdge(2, 1);          // 2 -> 1
    directedUnweighted.addEdge(2, 5);          // 2 -> 5
    directedUnweighted.addEdge(3, 4);          // 3 -> 4
    directedUnweighted.addEdge(5, 4);          // 5 -> 4

    Graph directedWeighted(6, true, true);     // Directed and weighted
    directedWeighted.addEdge(2, 4, 7);         // 2 -> 4 with weight 7
    directedWeighted.addEdge(1, 4, 2);         // 1 -> 4 with weight 2
    directedWeighted.addEdge(5, 2, 8);         // 5 -> 2 with weight 8
    directedWeighted.addEdge(2, 3, 8);         // 2 -> 3 with weight 8

    // Show the graph details
    cout << "Directed Unweighted Graph:" << endl;
    directedUnweighted.showGraph();
    cout << endl;

    cout << "Directed Weighted Graph:" << endl;
    directedWeighted.showGraph();

    return 0;
}
