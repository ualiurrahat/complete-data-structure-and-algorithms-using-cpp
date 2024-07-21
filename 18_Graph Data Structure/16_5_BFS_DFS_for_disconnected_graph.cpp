// the previous two functions BFS DFS
// works fine for connected graph
// but not for disconnected graph
// will create function BFS DFS for disconnected graph
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
void printBFS(int **edges, int n, int starting_vertex, bool *visited)
{
    // queue to store seen but not printed vertices
    queue<int> pendingVertices;
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
            if (edges[currenVertex][i] == 1 && (!visited[i]))
            {
                // since i has an edge, so pushing it in the queue
                pendingVertices.push(i);
                // marking i vertex in the visited array
                visited[i] = true;
            }
        }
    }
}

// function for DFS for disconnected graph
// works for connected too
void DFS(int **edges, int n)
{
    // array to mark visited vertex
    bool *visited = new bool[n];
    // marking all vertex as not visited initially
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // starting from vertex 0 to n-1 th index
    for (int i = 0; i < n; i++)
    {
        // checking if vertex was visited
        if (!visited[i])
        {
            // vertex not visited.
            // now calling DFS printing function
            printDFS(edges, n, i, visited);
        }
    }
    // deleting dynamic memory
    delete[] visited;
}

// function to perform BFS
// works for both connected and disconnected graph
void BFS(int **edges, int n)
{
    // array to mark visited vertex
    bool *visited = new bool[n];
    // marking all vertex as not visited initially
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // starting from vertex 0 to n-1 th index
    for (int i = 0; i < n; i++)
    {
        // checking if vertex was visited
        if (!visited[i])
        {
            // vertex not visited.
            // now calling BFS printing function
            printBFS(edges, n, i, visited);
        }
    }
    // deleting dynamic memory
    delete[] visited;
}

int main()
{
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

    // DFS for disconnected graph
    cout << "DFS Traversal : " << endl;
    DFS(edges, n);

    // BFS for disconnected graph
    cout << "BFS Traversal: " << endl;
    BFS(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}