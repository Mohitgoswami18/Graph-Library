#ifndef Graph_HPP
#define Graph_HPP

#include<iostream>
#include<vector>
using namespace std;

class Graph{

    private:
    int edges; // stores the total number of edges.
    bool isWeighted; // to check if graph is weighted.
    bool isDirected; // to check if graph is directed. 
    int vertex; // stroes the total number of vertex.
    vector<pair<int,int>> *adjList; // Dynamic creation of Adjacency list. 
    
    public:
    Graph(int vertex, bool isDirected = false, bool isWeighted = false); // Constructor

    ~Graph(); // Distructor

    public:
    void addEdge(int u, int v, int w=1); // Function to create graph.

    bool isConnected(); // Checks if the graph is connected or not.

    vector<int> topSort(); // Function to find the topological sort of the graph.

    void showGraph(); // Function to print the graph. 

    vector<int> BFS(int src); // Function for BFS traversal of graph. 

    vector<int> DFS(int src); // Function for DFS traversal of graph.

    vector<int> dijkstra(int src); // Function for applying dijkstra algorithm. 

    vector<int> bellman_ford(int src); // Function for applying bellmen ford algorithm. 

    int prims(); // Function for applying prims algorithm.
    
    int kruskal(); // Function for applying kruskal algorithm.

}; 

#endif