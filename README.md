This project implements several graph traversal and shortest-path algorithms in C++. It includes classes and functions for fundamental algorithms, a graph representation, and testing utilities.

Project Structure
Algorithms.cpp/hpp: Contains general utility functions or additional algorithms related to graph operations.

BFS.cpp/hpp: Implements Breadth-First Search (BFS), a traversal algorithm that explores nodes in layers and is commonly used for finding the shortest path in unweighted graphs.

Belman_Ford.cpp/hpp: Implements the Bellman-Ford algorithm, which computes the shortest paths from a source vertex to all other vertices in a graph, even if the graph contains negative weight edges.

Bipartite.cpp/hpp: Contains functions to check if a graph is bipartite, meaning it can be divided into two disjoint sets with edges only between the sets, which is essential in graph coloring and other applications.

DFS.cpp/hpp: Implements Depth-First Search (DFS), a traversal algorithm that explores as far along each branch as possible, commonly used for pathfinding, connectivity checks, and cycle detection.

Dijkstra.cpp/hpp: Implements Dijkstra’s algorithm, an efficient shortest-path algorithm for graphs with non-negative edge weights, typically faster than Bellman-Ford for such cases.

Graph.cpp/hpp: Defines the Graph class, which represents a graph structure and provides methods to add vertices and edges, along with utility functions used by algorithms.

Linear_Algebra.cpp/hpp: Contains functions related to linear algebra operations, possibly for matrix representations of graphs or other calculations related to graph theory.

Traverse.cpp/hpp: May contain general traversal utilities or shared methods for graph traversal algorithms.

Makefile: Automates the compilation of the project. It provides targets to compile each component and the main executable.

Test.cpp: Contains unit tests for verifying the functionality of the implemented algorithms. This file likely includes various test cases to ensure correctness and performance.

TestCounter.cpp: Additional test file, potentially for tracking performance or counting algorithm steps.

doctest.h: A single-header C++ testing framework used for writing unit tests (i.e., Doctest). This allows for easy integration of test cases within C++ code.

Features
Graph Traversal Algorithms:

BFS (Breadth-First Search): For layer-by-layer node exploration.
DFS (Depth-First Search): For depth-based node exploration.
Bipartite Check: Determines if a graph is bipartite.
Shortest Path Algorithms:

Dijkstra's Algorithm: For shortest paths in non-negative weighted graphs.
Bellman-Ford Algorithm: For shortest paths in graphs with negative weights.
Graph Representation: A flexible Graph class to represent and manipulate graphs for use in various algorithms.

Linear Algebra Utilities: Supporting functions for matrix and vector calculations needed for graph or algorithmic processing.
