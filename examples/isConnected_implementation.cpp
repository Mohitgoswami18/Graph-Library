#include "../include/graph.hpp"
#include <iostream>
using namespace std;

int main() {
    Graph g(6, true, false);  // Directed and unweighted

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // Check if the graph is connected
    cout << "Is the graph connected? ";
    if (g.isConnected()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
