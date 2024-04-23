// // introduction to graph
// Graph: A graph is a set of vertices and a set of edges connecting them
// but there is no pattern to the edges.

// why to use Graph?
// -where we can't input data as tree
// ex: social media, road network

// Tree is a special kind of graph. Since it has vertices and edges connecting them
// Tree has 2 properties:
// 1. all nodes are connected
// 2. trees are acyclic. it does not have any cycle
// Graph Terminologies:

// edges: connection between two vertices
// adjacent vertices: two vertices that is directly connected by an edge
// degree: counts for vertex. number of edges going through a vertex.
// path : collection of edges through which graph can reach from one point to another point
//     and the points have no direct edge between them

// conncted graph: a graph is connected if for every two vertices there is a
// path between them

// connected components: if graph is not connected , then there will have some
// connected components(conncection between some vertices that can be said as partial connected graph) in the graph

// Tree: tree is a connected graph which does not have a cycle.

// complete graph: every vertex in the graph has direct edge with every other vertex

// for a graph with n vertices:
// 1. min number of edges: 0
//  2. min number of edges in a connected graph: n-1
//  3. number of edges in a complete graph: nC2 = n * (n-1) / 2  .....so O(n^2) for compliexity

// so if we have an algorithm that shows complexity O(edges)
// then, the algo depends on number of edges in the graph
