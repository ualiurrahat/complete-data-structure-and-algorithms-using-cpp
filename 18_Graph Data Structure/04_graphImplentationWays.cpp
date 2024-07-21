// We can create graph by the following ways

// 1) edge list
// will create a class for graph
// having a list of vertices
// and another one of edges
// edges list will contain edges in a pair
// will call the class EdgeList
// can do it using pair

// problem: checking connection between two edges would cost O(n^2)
// it is very costly as we have to check this for many many times in graph.

// 2) Adjacency list
// will create a list of all vertices
// inside each vertices, there will be list of vertices(map)
// which are connected with in
// ex: vertices-- A,B,C,D
//                 A--> B,C   means A has edges with B and C
// can do it using map
// checking connection between two edges would cost O(n)

// 3) Adjacency Matrix
// -will create a 2D matrix of n*n size for n vertices
// space : O(n*n)
// - good for graphs with less vertices
// we will use adjacency matrix to implement graph
// in our codes