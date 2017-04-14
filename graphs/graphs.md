# Graphs

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
