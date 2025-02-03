# GraphLibrary

GraphLibrary is a C++ library for working with graphs, offering various algorithms such as BFS, DFS, Dijkstra's, Bellman-Ford, Kruskal's, Prim's, and Topological Sort. It also provides basic graph operations like adding edges, showing the graph, and checking connectivity.

## Features

- **Graph creation**: Create directed and undirected, weighted and unweighted graphs.
- **Graph Traversals**: Supports BFS (Breadth-First Search) and DFS (Depth-First Search) traversals.
- **Shortest Path Algorithms**: Implements Dijkstra's and Bellman-Ford algorithms.
- **Minimum Spanning Tree Algorithms**: Implements Prim's and Kruskal's algorithms.
- **Topological Sort**: Performs topological sorting on directed acyclic graphs (DAGs).
- **Graph Representation**: Uses an adjacency list for efficient space and time complexity.

## Getting Started

### Prerequisites

Ensure you have the following installed on your machine:
- C++ compiler (G++, Clang, MSVC, etc.)
- CMake (if you want to build using CMake)
- Git (to clone the repository)

### Installing

1. Clone the repository:

   ```bash
   git clone https://github.com/Mohitgoswami18/GraphLibrary.git
2. Navigate to the project directory:
   ```bash
     cd GraphLibrary
3. If you're using CMake, run the following commands to build:
   ```bash
    mkdir build
    cd build
    cmake ..
    make

4. Using Without CMake
If you prefer not to use CMake for building the library, you can directly compile the source files. Follow the steps below:

## A. Include the graph.hpp file: In your project, make sure to include the graph.hpp file that defines the graph class and its methods.

## B. Compile your source code:

You can compile your source files using a C++ compiler like g++. Here's an example of compiling the files without using CMake:
  ```bash
    g++ -std=c++11 -I./include -o main src/main.cpp src/graph.cpp
```

This command does the following:

-I./include: Specifies the include directory where the header files are located.
-o main: Specifies the output executable name (in this case, main).
src/main.cpp and src/graph.cpp: The source files you want to compile.

## C. Run the executable:

After compiling, you can run the generated executable:

```bash
./main
```

Example for creating a graph and performing BFS:
  ```cpp
    #include "graph.hpp"
    int main() {
        Graph g(6, true, false);  // Directed, unweighted graph
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        vector<int> bfsResult = g.BFS(0);  // Perform BFS starting from vertex 0
        for (int v : bfsResult) {
            cout << v << " ";
        }
        return 0;
    }
```
Example for performing Dijkstra’s Algorithm:
  ```cpp
        
    #include "graph.hpp"
    
    int main() {
        Graph g(5, true, true);  // Directed, weighted graph
        g.addEdge(0, 1, 10);
        g.addEdge(0, 2, 5);
        g.addEdge(1, 2, 2);
        g.addEdge(2, 3, 3);
        vector<int> distances = g.dijkstra(0);  // Shortest path from vertex 0
        for (int d : distances) {
            cout << d << " ";
        }
        return 0;
    }
```
For more examples, please check the examples/ directory.

## Testing
To test the graph operations, you can find unit tests under the tests/ folder. The tests cover the following operations:

-BFS and DFS traversal
-Shortest path algorithms (Dijkstra and Bellman-Ford)
-Minimum Spanning Tree algorithms (Prim's and Kruskal's)
-Topological Sort

To run the tests, you can use the following command (make sure to have a testing framework set up):
    ```bash
             
    ./tests/test_graph_operations


## Contributing
We welcome contributions! If you have suggestions, bug reports, or pull requests, feel free to open an issue or create a pull request. Please make sure to follow the existing code style and provide tests for your contributions.

1. Fork the repository.
2. Create a new branch for your feature/fix.
3. Commit your changes.
4. Push to your fork and create a pull request.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments
This project was built to explore fundamental graph algorithms and their implementation in C++.
Thanks to the open-source community for their valuable contributions to graph theory resources.
