# ICPC-notebook
Notebook per le gare ACM ICPC 

### Istruzioni
Per inserire gli algoritmi desiderati all'interno del notebook è necesario modificare l'array `$selected` nello script `algo-selector.sh` e aggiungere i propri desiderata aggiungendo il codice corrispondente:

```text
1.2.2 Maximal Subarray Sum (Kadane's)
1.2.4 Subset Sum (Meet-in-the-Middle)
1.3.2 Ternary Search
1.2.5 Maximal Zero Submatrix
1.1.1 Sorting Algorithms
1.3.3 Hill Climbing
1.3.5 Convex Hull Trick (Fully Dynamic)
1.4.2 Cycle Detection (Brent's)
1.3.1 Binary Search
1.1.5 Selection (Quickselect)
1.4.1 Cycle Detection (Floyd's)
1.5.1 Binary Exponentiation
1.3.4 Convex Hull Trick (Semi-Dynamic)
1.1.2 Array Rotation
1.1.3 Counting Inversions
1.2.3 Majority Element (Boyer-Moore)
1.2.1 Longest Increasing Subsequence
1.1.4 Coordinate Compression
2.2.1 Shortest Path (BFS)
2.7.2 Maximum Bipartite Matching (Hopcroft-Karp)
2.3.3 Bridges, Cut-points, and Biconnectivity
2.6.1 Backtracking - Max Clique (Bron-Kerbosch)
2.1.4 Unweighted Tree Centers (DFS
2.8.2 Shortest Hamiltonian Path
2.2.2 Shortest Path (Dijkstra's)
2.5.4 Max Flow (Push-Relabel)
2.3.2 Strongly Connected Components (Tarjan's)
2.5.3 Max Flow (Dinic's)
2.1.1 Graph Class and Depth-First Search
2.7.3 Maximum Graph Matching (Edmonds's)
2.1.3 Eulerian Cycles (DFS)
2.8.1 Shortest Hamiltonian Cycle (TSP)
2.3.1 Strongly Connected Components (Kosaraju's)
2.7.1 Maximum Bipartite Matching (Kuhn's)
2.1.2 Topological Sorting (DFS)
2.5.1 Max Flow (Ford-Fulkerson)
2.4.1 Minimal Spanning Tree (Prim's)
2.2.4 Shortest Path (Floyd-Warshall)
2.2.3 Shortest Path (Bellman-Ford)
2.4.2 Minimal Spanning Tree (Kruskal's)
2.5.2 Max Flow (Edmonds-Karp)
2.6.2 Backtracking - Graph Coloring
3.4.4 2D Range Tree
3.3.6 Implicit Treap
3.2.5 Splay Tree
3.5.7 2D Fenwick Tree (Compressed)
3.3.5 Segment Tree (Compressed)
3.1.2 Randomized Mergeable Heap
3.2.7 Interval Treap
3.3.1 Sparse Table (Range Minimum Query)
3.4.5 K-d Tree (2D Range Query)
3.4.1 Quadtree (Point Update)
3.6.5 Heavy Light Decomposition
3.3.3 Segment Tree (Point Update)
3.2.4 Red-Black Tree
3.3.4 Segment Tree (Range Update)
3.1.3 Skew Heap
3.2.1 Binary Search Tree
3.6.2 Disjoint Set Forest (Compressed)
3.2.8 Hash Map
3.4.7 R-Tree (Nearest Segment)
3.4.3 2D Segment Tree
3.6.1 Disjoint Set Forest (Simple)
3.1.4 Pairing Heap
3.4.6 K-d Tree (Nearest Neighbor)
3.6.3 Lowest Common Ancestor (Sparse Table)
3.2.3 AVL Tree
3.2.9 Skip List
3.5.5 Fenwick Tree (Compressed)
3.4.2 Quadtree (Range Update)
3.5.6 2D Fenwick Tree (Simple)
3.6.6 Link-Cut Tree
3.6.4 Lowest Common Ancestor (Segment Tree)
3.2.2 Treap
3.2.6 Size Balanced Tree
3.3.2 Square Root Decomposition
3.5.3 Fenwick Tree (Point Update, Range Query)
3.1.1 Binary Heap
3.5.1 Fenwick Tree (Simple)
3.5.2 Fenwick Tree (Range Update, Point Query)
3.5.4 Fenwick Tree (Range Update, Range Query)
4.2.1 Combinatorial Calculations
4.2.3 Enumerating Permutations
4.2.5 Enumerating Partitions
4.6.3 Polynomial Root Finding (Differentiation)
4.1 Math Utilities
4.3.3 Primality Testing
4.2.6 Enumerating Generic Combinatorial Sequences
4.5.2 Row Reduction
4.4.2 Big Integers
4.5.1 Matrix Utilities
4.3.1 GCD, LCM, Mod Inverse, Chinese Remainder
4.3.4 Integer Factorization
4.5.4 LU Decomposition
4.6.2 Root Finding (Iteration)
4.6.5 Polynomial Root Finding (RPOLY)
4.5.3 Determinant and Inverse
4.4.1 Big Integers (Simple)
4.6.4 Polynomial Root Finding (Laguerre's)
4.3.2 Prime Generation
4.2.4 Enumerating Combinations
4.5.5 Simplex Algorithm
4.4.3 Rational Numbers
4.7.1 Integration (Simpson's)
4.6.1 Root Finding (Bracketing)
4.2.2 Enumerating Arrangements
4.3.5 Euler's Totient Function
5.3.4 Minimum Enclosing Circle
5.4.2 Polygon Union and Intersection
5.1.4 Triangle (2D)
5.4.4 Delaunay Triangulation (Fast)
5.1.5 Rectangle (2D)
5.3.6 Closest Pair
5.0 Geometry Library (2D)
5.2.3 Line Intersection (2D)
5.1.3 Circle (2D)
5.3.5 Diameter of Points
5.2.4 Circle Intersection (2D)
5.4.1 Convex Polygon Cut
5.3.1 Polygon Sorting and Area
5.4.3 Delaunay Triangulation (Simple)
5.3.7 Segment Intersection Finding
5.3.2 Point-in-Polygon (Ray Casting)
5.2.2 Distances (2D)
5.1.2 Line (2D)
5.2.1 Angles (2D)
5.1.1 Point (2D)
5.3.3 Convex Hull (Monotone Chain)
6.4.2 Longest Common Subsequence
6.4.3 Edit Distance
6.3.1 String Searching (KMP)
6.3.3 String Searching (Z Algorithm)
6.2.1 Recursive Descent Parsing
6.6.1 Trie (Simple)
6.1 Strings Toolbox
6.6.3 Suffix Tree (Ukkonen's Algorithm)
6.6.4 Suffix Automaton
6.3.2 String Searching (Aho-Corasick)
6.2.3 Shunting Yard Parsing
6.4.1 Longest Common Substring
6.5.3 Suffix and LCP Array (Linear DC3)
6.5.1 Suffix and LCP Array (N log^2 N)
6.2.2 Recursive Descent Parsing (Simple)
6.6.2 Radix Tree
6.5.2 Suffix and LCP Array (N log N)
```

poi basterà lanciare lo script, compilare `notebook.tex` per ottenere un documento contenete gli algoritmi scelti in ordine alfabetico.

