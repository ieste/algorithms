# Graphs
A graph *G* = (*V*,*E*) is a set of vertices/nodes (*V*) and edges (*E*). Edges 
connect two vertices (can be the same vertex if the graph contains self-loops) 
and sometimes have associated direction or weighting information. These notes
cover the following areas:
* Definitions and Concepts
* Common Graph Data Structures
* Graph Traversal
* Minimum Spanning Trees
* Single-Source Shortest Paths
* All-Pairs Shortest Paths
* Network Flow
* Other


## Definitions and Concepts
A **Weighted** graph is one whose edges have weights (for example roads
between cities might have lengths). A weighted graph may or may not allow
zero or negative weight edges. 

Directed/Undirected

Sparse
Dense

The **Degree** of a vertex is the number of edges that connect to it (where a 
self-loop edge is counted twice). The **In-Degree** and **Out-Degree** of a
vertex in a directed graph are respectively the number of edges that lead in 
and out of the vertex.

Path
Cycle
Isolated
Reachable
Connected
Self-Loop
Multiple Edges

A **Multigraph** is an undirected graph in which multiple edges (two or more
edges connecting the same two vertices) are allowed. A multigraph may or may
not allow self-loops.

A **Simple Graph** 
Sub-Graph
DAG
Tree/Forest
Spanning Tree
Eulerian
Bipartite
Complete

## Graph Data Structures
There are a few common data structures used to represent a graph. The most 
appropriate data structure will depend on the specific scenario. 

### Adjacency Matrix
An **Adjacency Matrix** represents a graph in a *V* by *V* matrix. The value
stored at matrix\[i\]\[j\] is the weight of the edge from vertex i to vertex
j (or any non-zero value for an unweighted graph) if such an edge exists in
the graph, or zero otherwise.

An Adjacency Matrix can be used to represent both weighted and unweighted,
and both directed and undirected graphs. However, it cannot represent 
multigraphs or graphs with self-loops. 

Time complexities of common operations with an Adjacency Matrix:
* Enumerate neighbours of a vertex: O(V)
* Check if an edge exists between two vertices: O(1)

### Adjacency List
An **Adjacency List** is a list of lists of edges. For each vertex, there is
a list of connected edges. In an unweighted graph, each edge can simply be
represented as the vertex it connects to, however in a weighted graph both
the weight and connected vertex need to be stored. In a directed graph, the
edges listed at i are the edges from i to another vertex. An Adjacency List 
can be used to represent a multigraph.

Time complexities of common operations with an Adjacency List:
* Enumerate neighbours of a vertex: O(k) where k is the number of neighbours
* Check if an edge exists between two vertices: O(V)

### Edge List
An **Edge List** represents a graph as a list of its edges. Edges in an edge
list are typically stored in some sorted order (such as for Kruskal's MST
algorithm).

Time complexities:
* Enumerate neighbours of a vertex: O(E)
* Check if an edge exists between two vertices: O(

### Implicit Graph



## Traversal


## Connected Components
A connected component of an undirected graph is a subraph in which any two
vertices are connected to each other by paths, and which is connected to
no other additional vertices in the supergraph.

### Algorithms
It is straightforward to compute the connected components of a graph in
linear time (in terms of the number of edges and vertices in the graph)
using either BFS or DFS. To find all connected components of a graph, 
loop through its vertices, starting a new breadth-first or depth-first 
search whenever the loop reaches a vertex that has not already been included
in a previously found connected component.

## Minimum Spanning Tree
A minimum spanning tree is a subset of edges of a connected, edge-weighted
undirected graph that connects all the verticies together, without any
cycles and with the minimum possible total edge weight. More generally,
any undirected graph has a minimum spanning forest, which is a union of the
minimum spanning trees for its connected components.

Properties of a minimum spanning tree:
* **Possible Multiplicity**: 
