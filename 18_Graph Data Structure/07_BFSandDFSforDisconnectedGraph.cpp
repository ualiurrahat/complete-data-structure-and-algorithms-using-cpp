// the previous two functions printBFS and printDFS
// works fine for connected graph
// but not for disconnected graph
// we will create function BFS DFS for disconnected graph

#include <bits/stdc++.h>
using namespace std;

// function to print the graph in depth first search order;
// only for connected graph.
// it has 4 paramters.
// takes adjacency matrix i.e. graph(edges here)
// n == total no. of vertex
// sv = starting vertex
// a boolean array visited
// as parameters
void printDFS(int **edges, int n, int sv, bool *visited)
{
    // print the starting vertex first
    cout << sv << endl;
    // mark starting vertex as the visited array
    visited[sv] = true;
    // loop to find edges between starting vertex and all other vertices
    for (int i = 0; i < n; i++)
    {
        // if current vertex i is equatl to starting vertex
        if (sv == i)
        {
            // starting vertex is already printed
            // so, skipping this iteration
            continue;
        }
        // if vertex i has edge with starting vertex
        if (edges[sv][i] == 1)
        {
            // check if this edge is already visited
            if (visited[i] == true)
            {
                // this edge is visited.
                // so skipping this iteration
                continue;
            }
            // this edge is not visited
            // so recursively calling the function to print
            // all the edges between vertex i and all other vertices
            // this time, starting vertex would be i
            printDFS(edges, n, i, visited);
        }
    }
}
// function to print graph in Breadth First Search(BFS) order
// only for connected graph.
// takes 3 parameters:
// adjacency matrix(edges here) i.e. graph
// n == total no. of vertices
// sv == starting vertex
void printBFS(int **edges, int n, int sv, bool *visited)
{
    // take a queue to store vertices
    queue<int> pendingVertices;

    // insert starting vertex in the queue
    pendingVertices.push(sv);
    // mark starting vertex in the visited array since it is visited now
    visited[sv] = true;
    // loop to visit all the vertices
    while (!pendingVertices.empty())
    {
        // take out front vertex from the queue
        int currentVertex = pendingVertices.front();
        // pop out the current vertex
        pendingVertices.pop();
        // print the current vertex
        cout << currentVertex << endl;
        // loop to find edges between current vertex and all other vertices
        for (int i = 0; i < n; i++)
        {
            // skip if current vertex and i are both same
            if (i == currentVertex)
            {
                continue;
            }
            // check if current vertex and i have edge and
            // it is not visited
            if (edges[currentVertex][i] == 1 && visited[i] != true)
            {
                // insert i at the queue
                pendingVertices.push(i);
                // mark i as visited in the visited array
                visited[i] = true;
            }
        }
    }
}
// function to traverse graph in DFS order for disconnected graph
// take two paramters: n --> total no. of vertices
// edges--> an adjacency matrix to implement graph
void DFS(int **edges, int n)
{
    // take an array to keep track of whether
    // vertices has been visited or not
    bool *visited = new bool[n];
    // mark all vertices as false
    // since no vertex has been visited yet
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // now from vertex 0 to n-1, peform the printDFS function
    // to find DFS traversal
    for (int i = 0; i < n; i++)
    {
        // check if vertex i is not visited yet
        if (visited[i] == false)
        {
            // take i as the starting vertex
            // perform printDFS function
            printDFS(edges, n, i, visited);
        }
    }
    // delete dynamic memory
    delete[] visited;
}
// function to perform BFS traversal for disconnected graph
// it takes two parametes:
// n--> total no. of vertices
// edges--> an adjacency matrix to implement graph
void BFS(int **edges, int n)
{
    // take an array to keep track of whether
    // vertices has been visited or not
    bool *visited = new bool[n];
    // mark all vertices as false
    // since no vertex has been visited yet
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // now from vertex 0 to n-1, peform the printBFS function
    // to find BFS traversal
    for (int i = 0; i < n; i++)
    {
        // check if vertex i is not visited yet
        if (visited[i] == false)
        {
            // take i as the starting vertex
            // perform printBFS function
            printBFS(edges, n, i, visited);
        }
    }
    // delete dynamic memory
    delete[] visited;
}
int main()
{
    int n; // total no. of vertices
    int e; // total no. of edges.

    cout << "Enter total no. of vertices: ";
    cin >> n; // 7
    cout << "Enter total no. of edges: ";
    cin >> e; // 5

    // creating a 2D-matrix to create graph
    // the matrix is of n*n size
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
    }
    // now each location of matrix is filled with garbage value
    // assigning value 0 indicating graph is empty
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    // insert edges in the matrix from user given data
    // take first and second vetices data from user
    // and form the edge.
    for (int i = 0; i < e; i++)
    {
        // take first and second vertices data from user.
        int f, s;
        // 0 2 | 0 3 | 2 3 | 1 4 | 5 6
        cout << "enter starting and ending vertices: " << endl;
        cin >> f >> s;
        // now mark that location in the matrix by assigning 1
        // meaning that those vertices have edges
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // printing DFS traversal for disconnected graph
    cout << "DFS traversal: " << endl;
    // printing the graph
    DFS(edges, n);
    // printing BFS traversal for disconnected graph.
    cout << "BFS traversal: " << endl;
    BFS(edges, n);

    // deleting edges array i.e. graph
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}