#include<iostream>
#include<vector> 
#include<queue>
#include<limits>
#include<limits.h>
#include<stack>
#include "../include/graph.hpp"

using namespace std;
typedef pair<int,int> p;

// Constructor to initialize the graph with a given number of vertices
// Parameters:
// - vertex: Number of vertices in the graph
// - isWeighted: Flag to indicate if the graph is weighted
// - isDirected: Flag to indicate if the graph is directed
Graph::Graph(int vertex, bool isDirected, bool isWeighted){
    
    edges = 0;
    this->vertex = vertex;
    this->isWeighted = isWeighted;
    this->isDirected = isDirected;
    adjList = new vector<pair<int,int>>[vertex]; // Create adjacency list for the graph
}

// Destructor to free allocated memory for adjacency list
Graph::~Graph(){
    free(adjList);
}

// Function to add an edge between two vertices
// Parameters:
// - u: Starting vertex of the edge
// - v: Ending vertex of the edge
// - w: Weight of the edge (if graph is weighted)
void Graph::addEdge(int u, int v, int w){
    if (u<0||v<0||u>=vertex||v>=vertex) { // Check for invalid vertices
        cout << "Error: Invalid vertex index\n";
        return;
    }
    adjList[u].push_back({v,w}); // Add directed edge u -> v with weight w
    edges++;
    if(isDirected==false){ // If graph is undirected, add the reverse edge v -> u
        adjList[v].push_back({u,w});
    }
}

// Function to detect whether a graph is connected or not.
// Returns true if the graph is connected.
// returns false if the graph is disconnected.
bool Graph:: isConnected() {
    // Run BFS or DFS to check connectivity
    vector<bool> visited(vertex, false);
    int count = 0;

    // BFS/DFS Start from node 0 (or any existing node)
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (auto neighbor : adjList[node]) {
            int nextNode = neighbor.first;
            if (!visited[nextNode]) {
                visited[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
    return count == vertex; // True if all nodes are visited
}

// Function to display the graph
// It prints all the vertices and their adjacent vertices
void Graph::showGraph(){
    for(int i=0;i<vertex;i++){
        cout<<"vertex :"<<i<<"--> ";
        for(int j=0;j<adjList[i].size();j++){
            cout<<adjList[i][j].first<<" "; // Print each adjacent vertex
        } 
        cout<<endl;
    }
}

// Function to perform BFS (Breadth-First Search) on the graph starting from vertex 0
vector<int> Graph::BFS(int src){
    queue<int> q;
    vector<int> result;
    vector<bool> visited(vertex,false); // Keep track of visited nodes

    q.push(src); // Start BFS from vertex 0
    visited[src] = 1;

    while(!q.empty()){
        int node = q.front(); // Get the node from the front of the queue
        q.pop();
        result.push_back(node); // Add the node in the result vector.

        // Visit all adjacent vertices of the current node
        for(int i=0;i<adjList[node].size();i++){
            if(!visited[adjList[node][i].first]){
                q.push(adjList[node][i].first); // Push unvisited adjacent node to the queue
                visited[adjList[node][i].first] = 1;
            }
        }
    }

    cout<<endl;
    return result;
}

// Function to perform DFS (Depth-First Search) on the graph starting from vertex 0
vector<int> Graph::DFS(int src){
    vector<bool> visited(vertex,false);
    vector<int> result;
    stack<int> st;

    st.push(src); // Start DFS from vertex 0
    visited[src] = 1;

    while(!st.empty()){
        int node = st.top(); // Get the top element from the stack
        result.push_back(node);
        st.pop();

        // Visit all adjacent vertices of the current node
        for(int i=0;i<adjList[node].size();i++){
            if(!visited[adjList[node][i].first]){
                st.push(adjList[node][i].first); // Push unvisited adjacent node to the stack
                visited[adjList[node][i].first] = 1;
            }
        }
    }

    cout<<endl;
    return result;
}

// Function to perform Topological Sort on the graph (only for directed acyclic graphs)
vector<int> Graph::topSort(){
    queue<int> q;
    vector<int> inDegree(vertex,0); // Vector to store in-degree of each vertex
    vector<int> result;
    int count = 0; // To detect any cycle in the graph.
    // Calculate in-degree for all vertices
    for(int i=0;i<vertex;i++){
        for(int j=0;j<adjList[i].size();j++){
            inDegree[adjList[i][j].first]++;
        }
    }

    // Add vertices with in-degree 0 to the queue
    for(int i=0;i<vertex;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    
    // Perform BFS to print vertices in topological order
    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);
        count++;

        // Reduce in-degree of adjacent vertices and add those with in-degree 0 to the queue
        for(auto neighbour:adjList[node]){
            inDegree[neighbour.first]--;
            if(inDegree[neighbour.first] == 0){
                q.push(neighbour.first);
            }
        }
    }

    if (count != vertex) {
    cout << "\nGraph contains a cycle. Topological sorting is not possible!" << endl;
}

    cout<<endl;
    return result;
}

// Function to perform Dijkstra's algorithm for finding the shortest path from a source vertex
// Parameters:
// - src: The source vertex
// Returns: A vector containing the shortest distance from src to all other vertices
typedef pair<int,int> p;
vector<int> Graph::dijkstra(int src) {
    vector<int> distance(vertex, INT_MAX); // Initialize distances to all vertices as infinity
    vector<bool> visited(vertex, false); // Initialize visited array
    priority_queue<p, vector<p>, greater<p>> pq; // Min-heap priority queue for shortest path calculation

    pq.push({0, src}); // Start from source vertex with distance 0
    distance[src] = 0;

    // Main loop to calculate shortest paths
    while (!pq.empty()) {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (visited[node]) continue; // Skip if node is already visited
        visited[node] = true;

        // Update distances for all adjacent vertices
        for (auto neighbour:adjList[node]) {
            int neighborNode = neighbour.first;
            int weight = neighbour.second;

            if ( !visited[neighborNode] && distance[neighborNode] > dist + weight) {
                distance[neighborNode] = dist + weight;
                pq.push({distance[neighborNode], neighborNode}); // Push updated distance to priority queue
            }
        }
    }

    return distance;
}

// Function to perform Bellman-Ford algorithm to find the shortest path from a source vertex
// Parameters:
// - src: The source vertex
// Returns: A vector containing the shortest distance from src to all other vertices
vector<int> Graph::bellman_ford(int src){
    vector<int> distance(vertex, 1e9); // Initialize distances to infinity
    distance[src] = 0;

    // Relax all edges (vertex-1) times
    for(int i=0;i<vertex-1;i++){
        bool flag = false;

        // Iterate over all edges and relax them
        for(int j=0;j<vertex;j++){
            for(auto neighbour:adjList[j]){
                int u = j;
                int v = neighbour.first;
                int wt = neighbour.second;

                if(distance[u]!=1e9 && distance[v]>distance[u]+wt){
                    distance[v] = distance[u]+wt;
                    flag = true;
                }
            }
        }

        if(flag ==false) return distance; // If no updates happened, no need to continue
    }

    // Check for negative weight cycles
    for(int j=0;j<vertex;j++){
        for(auto neighbour:adjList[j]){
            int u = j;
            int v = neighbour.first;
            int wt = neighbour.second;

            if(distance[u]!=1e9 && distance[v]>distance[u]+wt){
                cout<<"Graph contains negative cycle; cannot determine the shortest path for it "<<endl;
                return distance;
            }
        }
    }

    return distance;
}

// Function to perform Prim's algorithm to find the Minimum Spanning Tree (MST)
// Parameters:
// - src: The starting vertex
// Returns: Total weight of the MST
int Graph::prims(){

    if (!isConnected()) {
        return -1;
    }

    priority_queue<p, vector<p>, greater<p>> pq; // Min-heap priority queue for MST calculation
    vector<bool> visited(vertex, 0);

    pq.push({0,0}); // Start with source vertex
    int totalCost = 0; // Variable to store total cost of MST
    int edgecount = 0;

    // Main loop to construct MST
    while(!pq.empty()){
        auto elem = pq.top();
        pq.pop();

        int curr_node = elem.second;
        int weight = elem.first;

        if(visited[curr_node]==true) continue; // Skip if node is already visited

        visited[curr_node] = true;
        edgecount++;
        totalCost+=weight; // Add the weight to total cost

        // Explore all adjacent vertices
        for(auto tempNode:adjList[curr_node]){
            int neighbour = tempNode.first;
            int wt = tempNode.second;
            if(!visited[neighbour]){
                pq.push({wt,neighbour}); // Push unvisited nodes to the priority queue.
            }
        }
    }

    if (edgecount<vertex-1) {
        return -1;
    }

    return totalCost;
}

// Helper function to find the parent of a vertex in the disjoint-set (used in Kruskal's algorithm)
int findParent(int u, vector<int>& parent){
    if(u==parent[u]) return u;
    return parent[u] = findParent(parent[u],parent); // Path compression
}


// Function to perform Kruskal's algorithm to find the Minimum Spanning Tree (MST)
// Parameters:
// - src: The starting vertex (not used in this case, since it's for MST)
// Returns: Total weight of the MST
typedef pair<int,pair<int,int>> info;
int Graph::kruskal(){
    vector<int> parent(vertex);
    vector<int> rank(vertex,0);
    int edgeCount = 0;

    // Initialize parent of each vertex as itself
    for(int i=0;i<vertex;i++){
        parent[i] = i;
    }

    priority_queue<info, vector<info>, greater<info>> pq;
    
    // Add all edges to the priority queue
    for(int i=0;i<vertex;i++){
        for(auto neighbour:adjList[i]){
            int u = i;
            int v = neighbour.first;
            int wt = neighbour.second;

            pq.push({wt,{u,v}});
        }
    }

    int totalWeight = 0; // Variable to store total weight of MST
    int edges = 0; // Counter to track the number of edges in MST

    // Main loop to construct MST
    while(!pq.empty()){
        auto elem = pq.top();
        pq.pop();

        int u = elem.second.first;
        int v = elem.second.second;
        int wt = elem.first;

        int pu = findParent(u,parent); // Find the parent of u
        int pv = findParent(v,parent); // Find the parent of v

        if(pu!=pv){ // If they belong to different sets, add the edge to MST
            edges++;
            totalWeight += wt;
            if(rank[pu]>rank[pv]){
                parent[pv] = pu;
            } else if (rank[pv]>rank[pu]){
                parent[pu] = pv;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }

        if(edges==vertex-1) return totalWeight; // Stop once we have enough edges for MST
    }

    if (edgeCount < vertex-1) {
        return -1; // -1 indicating that the graph is disconnected.
    } 
    
    return totalWeight;
}

// End of the Library... 
// :)