// breadth first search traversal
// similar to level order traversal in tree

#include <bits/stdc++.h>
using namespace std;

// function to print the graph using depth first search;
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
// takes 3 parameters:
// adjacency matrix(edges here) i.e. graph
// n == total no. of vertices
// sv == starting vertex
void printBFS(int **edges, int n, int sv)
{
    // take a queue to store vertices
    queue<int> pendingVertices;
    // take an array to keep track of
    // which vertices have been visited
    bool *visited = new bool[n];
    // assign false as value for all vertices in visited array
    // since no vertices have been visited yet
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
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
    // delete visited array
    delete[] visited;
}
int main()
{
    int n; // total no. of vertices
    int e; // total no. of edges.

    cout << "Enter total no. of vertices: ";
    cin >> n; // 8
    cout << "Enter total no. of edges: ";
    cin >> e; // 9

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
        // 0 4 | 0 5 | 4 3 | 3 2 | 2 1 | 1 3 | 5 6 | 6 7 | 3 6
        cout << "enter starting and ending vertices: " << endl;
        cin >> f >> s;
        // now mark that location in the matrix by assigning 1
        // meaning that those vertices have edges
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // taking an array to keep track of which nodes are visited
    // true--> already visited
    // false-> not visited
    bool *visited = new bool[n];
    // assign initial value 0 for all vertices
    // since none is visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    cout << "DFS traversal: " << endl;
    // printing the graph
    printDFS(edges, n, 0, visited);
    cout << "BFS traversal: " << endl;
    printBFS(edges, n, 0);
    // deleting memory: edges and visited array
    // deleting visited array
    delete[] visited;
    // deleting edges array i.e. graph
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}