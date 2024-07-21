// breadth first search traversal
//similar to level order traversal in tree

#include <bits/stdc++.h>

using namespace std;

// function to print the graph
// Depth first search DFS print
// only for connected graph
void printDFS(int **edges, int n, int starting_vertex, bool *visited)
{
    // first printing the starting vertex
    cout << starting_vertex << endl;
    // marking starting_vertex in the visited array
    visited[starting_vertex] = 1;

    // loop to find edges between starting_vertex and among all other vertices
    for (int i = 0; i < n; i++)
    {
        // no point to look for when i == starting_vertex
        if (i == starting_vertex)
        {
            continue;
        }
        // if i has edge with starting_vertex
        if (edges[starting_vertex][i] == 1)
        {
            // checking if i vertex is already visited
            if (visited[i] == true)
            {
                // skipping this iteration
                // as i vertex is done
                continue;
            }
            // recursively calling and printing all other vertices that has edge
            // now starting vertex would be i;
            // to print all other vertices that has edge with i
            printDFS(edges, n, i, visited);
        }
    }
}

// function for BFS traversal
// only for connected graph
void printBFS(int **edges, int n, int starting_vertex)
{
    // queue to store seen but not printed vertices
    queue<int> pendingVertices;
    // array to store visited vertices to check if there is an edge
    bool *visited = new bool[n];

    // visited array is filled with garbage value
    // assigning false as initial value
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // pushing starting_vertex in the queue and array
    pendingVertices.push(starting_vertex);
    // now starting_vertex is visted. so marking it in the array
    visited[starting_vertex] = true;

    // loop for BFS traversal
    while (!pendingVertices.empty())
    {
        int currenVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currenVertex << endl;
        // level order traversal
        for (int i = 0; i < n; i++)
        {
            if (i == currenVertex)
            {
                continue;
            }
            // condition for having an edge between vertex i and currentVertex
            if (edges[currenVertex][i] == 1 && !visited[i])
            {
                // since i has an edge, so pushing it in the queue
                pendingVertices.push(i);
                // marking i vertex in the visited array
                visited[i] = true;
            }
        }
    }
    // deleting dynamic memory
    delete[] visited;
}

int main()
{
    // 8 9
    // 0 4
    // 0 5
    // 4 3
    // 3 2
    // 2 1
    // 1 3
    // 5 6
    // 3 6
    // 6 7

    int n; // number of vertices
    int e; // number of edges

    cout << "enter total vertices: " << endl;
    cin >> n;
    cout << "enter total edges: " << endl;
    cin >> e;

    // creating 2D-matrix dynamically
    // forn n vertices, matrix will be n*n size
    int **edges = new int *[n];
    // each array inside edges has n spaces for int data
    for (int i = 0; i < n; i++)
    {
        // allocating space for each array
        edges[i] = new int[n];
        // now each box is having garbage value
        // assigning 0 to them
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    // take user input for vertices
    cout << "enter first and second point of edges: " << endl;
    int first;
    int second;
    for (int i = 0; i < e; i++)
    {
        cin >> first >> second;

        // if point 1,2 has an edge, then 2,1 also has edge
        // as edges are bidirectonal
        // assigning 1 to the boxes of vertices
        // between them edges are being found
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    // array to store vertices that are already visited
    // in the DFS
    bool *visited = new bool[n];
    // initializing with 0 signing as not visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // printing the grapth from 0 vertex as starting point
    // in DFS Form
    cout << "DFS Traversal: " << endl;
    printDFS(edges, n, 0, visited);

    // printing in BFS form
    // 0 as starting vertex
    cout << "BFS Traversal: " << endl;
    printBFS(edges, n, 0);

    // deleting all dynamic memories
    delete[] visited;

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}