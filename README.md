# ICPC-notebook
Notebook per le gare ACM ICPC 

### Istruzioni
Per inserire gli algoritmi desiderati all'interno del notebook è necesario modificare l'array `$selected` nello script `algo-selector.sh` e aggiungere i propri desiderata aggiungendo il codice corrispondente:

```text
1.1.1 Sorting Algorithms.cpp
1.1.2 Array Rotation.cpp
1.1.3 Counting Inversions.cpp
1.1.4 Coordinate Compression.cpp
1.1.5 Selection (Quickselect).cpp
1.2.1 Longest Increasing Subsequence.cpp
1.2.2 Maximal Subarray Sum (Kadane's).cpp
1.2.3 Majority Element (Boyer-Moore).cpp
1.2.4 Subset Sum (Meet-in-the-Middle).cpp
1.2.5 Maximal Zero Submatrix.cpp
1.3.1 Binary Search.cpp
1.3.2 Ternary Search.cpp
1.3.3 Hill Climbing.cpp
1.3.4 Convex Hull Trick (Semi-Dynamic).cpp
1.3.5 Convex Hull Trick (Fully Dynamic).cpp
1.4.1 Cycle Detection (Floyd's).cpp
1.4.2 Cycle Detection (Brent's).cpp
1.5.1 Binary Exponentiation.cpp
2.1.1 Graph Class and Depth-First Search.cpp
2.1.2 Topological Sorting (DFS).cpp
2.1.3 Eulerian Cycles (DFS).cpp
2.1.4 Unweighted Tree Centers (DFS).cpp
2.2.1 Shortest Path (BFS).cpp
2.2.2 Shortest Path (Dijkstra's).cpp
2.2.3 Shortest Path (Bellman-Ford).cpp
2.2.4 Shortest Path (Floyd-Warshall).cpp
2.3.1 Strongly Connected Components (Kosaraju's).cpp
2.3.2 Strongly Connected Components (Tarjan's).cpp
2.3.3 Bridges, Cut-points, and Biconnectivity.cpp
2.4.1 Minimal Spanning Tree (Prim's).cpp
2.4.2 Minimal Spanning Tree (Kruskal's).cpp
2.5.1 Max Flow (Ford-Fulkerson).cpp
2.5.2 Max Flow (Edmonds-Karp).cpp
2.5.3 Max Flow (Dinic's).cpp
2.5.4 Max Flow (Push-Relabel).cpp
2.6.1 Backtracking - Max Clique (Bron-Kerbosch).cpp
2.6.2 Backtracking - Graph Coloring.cpp
2.7.1 Maximum Bipartite Matching (Kuhn's).cpp
2.7.2 Maximum Bipartite Matching (Hopcroft-Karp).cpp
2.7.3 Maximum Graph Matching (Edmonds's).cpp
2.8.1 Shortest Hamiltonian Cycle (TSP).cpp
2.8.2 Shortest Hamiltonian Path.cpp
3.1.1 Binary Heap.cpp
3.1.2 Randomized Mergeable Heap.cpp
3.1.3 Skew Heap.cpp
3.1.4 Pairing Heap.cpp
3.2.1 Binary Search Tree.cpp
3.2.2 Treap.cpp
3.2.3 AVL Tree.cpp
3.2.4 Red-Black Tree.cpp
3.2.5 Splay Tree.cpp
3.2.6 Size Balanced Tree.cpp
3.2.7 Interval Treap.cpp
3.2.8 Hash Map.cpp
3.2.9 Skip List.cpp
3.3.1 Sparse Table (Range Minimum Query).cpp
3.3.2 Square Root Decomposition.cpp
3.3.3 Segment Tree (Point Update).cpp
3.3.4 Segment Tree (Range Update).cpp
3.3.5 Segment Tree (Compressed).cpp
3.3.6 Implicit Treap.cpp
3.4.1 Quadtree (Point Update).cpp
3.4.2 Quadtree (Range Update).cpp
3.4.3 2D Segment Tree.cpp
3.4.4 2D Range Tree.cpp
3.4.5 K-d Tree (2D Range Query).cpp
3.4.6 K-d Tree (Nearest Neighbor).cpp
3.4.7 R-Tree (Nearest Segment).cpp
3.5.1 Fenwick Tree (Simple).cpp
3.5.2 Fenwick Tree (Range Update, Point Query).cpp
3.5.3 Fenwick Tree (Point Update, Range Query).cpp
3.5.4 Fenwick Tree (Range Update, Range Query).cpp
3.5.5 Fenwick Tree (Compressed).cpp
3.5.6 2D Fenwick Tree (Simple).cpp
3.5.7 2D Fenwick Tree (Compressed).cpp
3.6.1 Disjoint Set Forest (Simple).cpp
3.6.2 Disjoint Set Forest (Compressed).cpp
3.6.3 Lowest Common Ancestor (Sparse Table).cpp
3.6.4 Lowest Common Ancestor (Segment Tree).cpp
3.6.5 Heavy Light Decomposition.cpp
3.6.6 Link-Cut Tree.cpp
4.1 Math Utilities.cpp
4.2.1 Combinatorial Calculations.cpp
4.2.2 Enumerating Arrangements.cpp
4.2.3 Enumerating Permutations.cpp
4.2.4 Enumerating Combinations.cpp
4.2.5 Enumerating Partitions.cpp
4.2.6 Enumerating Generic Combinatorial Sequences.cpp
4.3.1 GCD, LCM, Mod Inverse, Chinese Remainder.cpp
4.3.2 Prime Generation.cpp
4.3.3 Primality Testing.cpp
4.3.4 Integer Factorization.cpp
4.3.5 Euler's Totient Function.cpp
4.4.1 Big Integers (Simple).cpp
4.4.2 Big Integers.cpp
4.4.3 Rational Numbers.cpp
4.5.1 Matrix Utilities.cpp
4.5.2 Row Reduction.cpp
4.5.3 Determinant and Inverse.cpp
4.5.4 LU Decomposition.cpp
4.5.5 Simplex Algorithm.cpp
4.6.1 Root Finding (Bracketing).cpp
4.6.2 Root Finding (Iteration).cpp
4.6.3 Polynomial Root Finding (Differentiation).cpp
4.6.4 Polynomial Root Finding (Laguerre's).cpp
4.6.5 Polynomial Root Finding (RPOLY).cpp
4.7.1 Integration (Simpson's).cpp
5.0 Geometry Library (2D)
5.0 Geometry Library (2D).cpp
5.1.1 Point (2D).cpp
5.1.2 Line (2D).cpp
5.1.3 Circle (2D).cpp
5.1.4 Triangle (2D).cpp
5.1.5 Rectangle (2D).cpp
5.2.1 Angles (2D).cpp
5.2.2 Distances (2D).cpp
5.2.3 Line Intersection (2D).cpp
5.2.4 Circle Intersection (2D).cpp
5.3.1 Polygon Sorting and Area.cpp
5.3.2 Point-in-Polygon (Ray Casting).cpp
5.3.3 Convex Hull and Diametral Pair.cpp
5.3.4 Minimum Enclosing Circle.cpp
5.3.5 Closest Pair.cpp
5.3.6 Segment Intersection Finding.cpp
5.4.1 Convex Polygon Cut.cpp
5.4.2 Polygon Intersection and Union.cpp
5.4.3 Delaunay Triangulation (Simple).cpp
5.4.4 Delaunay Triangulation (Fast).cpp
6.1 String Utilities.cpp
6.2.1 Recursive Descent Parsing (Simple).cpp
6.2.2 Recursive Descent Parsing (Generic).cpp
6.2.3 Shunting Yard Parsing.cpp
6.3.1 String Searching (KMP).cpp
6.3.2 String Searching (Z Algorithm).cpp
6.3.3 String Searching (Aho-Corasick).cpp
6.4.1 Longest Common Substring.cpp
6.4.2 Longest Common Subsequence.cpp
6.4.3 Sequence Alignment.cpp
6.5.1 Suffix Array and LCP (Manber-Myers).cpp
6.5.2 Suffix Array and LCP (Counting Sort).cpp
6.5.3 Suffix Array and LCP (Linear DC3).cpp
6.6.1 Trie.cpp
6.6.2 Radix Tree.cpp
6.6.3 Suffix Tree (Ukkonen's Algorithm).cpp
6.6.4 Suffix Automaton.cpp
```

poi basterà lanciare lo script, compilare `notebook.tex` per ottenere un documento contenete gli algoritmi scelti in ordine alfabetico.

