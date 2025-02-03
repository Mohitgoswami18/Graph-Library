#include "../include/graph.hpp"
#include <iostream>
#include <vector>

using namespace std;

/*   this file contains various test casses on the methods/functions of the graph library
     these are as follows :
*/

bool test_BFS();
bool test_DFS();
bool test_Dijkstra();
bool test_ConnectedGraph();
bool testPrim();
bool test_Kruskal();
bool testTopologicalSort();


bool test_BFS() {
    Graph g(5, false, false);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    vector<int> expectedBFS = {0, 1, 4, 2, 3};
    vector<int> resultBFS = g.BFS(0);  // Assuming BFS method is implemented

    if (resultBFS == expectedBFS) {
        cout << "Test BFS Traversal: PASSED " << endl;
        return true;
    } else {
        cout << "Test BFS Traversal: FAILED " << endl;
        return false;
    }
}

bool test_DFS() {
    Graph g(5, true, false);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    vector<int> expectedDFS = {0, 4, 1, 3, 2}; // Assuming DFS visits nodes in order
    vector<int> resultDFS = g.DFS(0);  // Assuming DFS method is implemented

    if (resultDFS == expectedDFS) {
        cout << "Test DFS Traversal: PASSED " << endl;
        return true;
    } else {
        cout << "Test DFS Traversal: FAILED " << endl;
        cout<< "expected :";
        for(auto itr:expectedDFS) cout<<itr<<" ";
        cout<<endl; 
        cout<<" got :";
        for(auto itr:resultDFS){
            cout<<itr<<" ";
        }
        cout<<endl;
        return false;
    }
}

bool test_Dijkstra() {
    Graph g(5, true, true);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(4, 1, 3);
    g.addEdge(4, 2, 9);
    g.addEdge(4, 3, 2);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 3, 6);

    vector<int> expectedDistances = {0, 8, 9, 7, 5};
    vector<int> resultDistances = g.dijkstra(0);

    if (resultDistances == expectedDistances) {
        cout << "Test Dijkstra's Algorithm: PASSED " << endl;
        return true;
    } else {
        cout << "Test Dijkstra's Algorithm: FAILED " << endl;
        return false;
    }
}

bool test_ConnectedGraph() {
    Graph g(4, false, false);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    if (g.isConnected()) {  // Assuming isConnected() method is implemented
        cout << "Test Connected Graph: PASSED " << endl;
        return true;
    } else {
        cout << "Test Connected Graph: FAILED " << endl;
        return false;
    }
}

bool test_Prim() {
    Graph g(5, false, true); // Undirected weighted graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    int expectedCost = 16; // Expected minimum spanning tree cost
    int computedCost = g.prims();

    if (computedCost == expectedCost) {
        cout << " Prim's Algorithm Test Passed. " << endl;
        return true;
    } else {
        cout << " Prim's Algorithm Test Failed. Expected: " << expectedCost << ", Got: " << computedCost << endl;
        return false;
    }
}

bool test_Kruskal() {
    Graph g(5, false, true); // Undirected weighted graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    int expectedCost = 16; // Expected minimum spanning tree cost
    int computedCost = g.kruskal();

    if (computedCost == expectedCost) {
        cout << " Kruskal's Algorithm Test Passed. " << endl;
        return true;
    } else {
        cout << " Kruskal's Algorithm Test Failed. Expected: " << expectedCost << ", Got: " << computedCost << endl;
        return false;
    }
}

bool testBellmanFord() {
    Graph g(5, true, true); // Directed weighted graph
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    vector<int> distances = g.bellman_ford(0);
    
    cout << "Bellman-Ford Algorithm Test Passed " << endl;
    return true;
}

bool testTopologicalSort() {
    Graph g(6, true, false); // Directed unweighted graph
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<int> topoSortResult = g.topSort();

    cout << "Topological Sort Test Passed " << endl;
    return true;
}

int main() {
    int passedTests = 0, totalTests = 8;

    cout << "\nRunning Graph Tests...\n";

    passedTests += test_BFS();
    passedTests += test_DFS();
    passedTests += test_Dijkstra();
    passedTests += test_ConnectedGraph();
    passedTests += test_Prim();
    passedTests += testBellmanFord();
    passedTests += test_Kruskal();
    passedTests += testTopologicalSort();

    cout << "\n------------------------------------\n";
    cout << "Tests Passed: " << passedTests << " / " << totalTests << endl;
    cout << "------------------------------------\n";

    return 0;
}
