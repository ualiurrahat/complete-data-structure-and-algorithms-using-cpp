#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// we are creating a generic tree class
template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adj;
    // function to create edges between to nodes u and v.
    // the bool paramater checks whether to make
    // directed or undirected graph.
    void addEdge(T u, T v, bool direction)
    {
        // direction == 0 ->  undirected graph
        // direction == 1 -> directoed graph

        // create an edge between nodes u and v
        adj[u].push_back(v);
        // check for undirected graph
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    // function to print edges
    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> : ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int n; // user input for total no. of nodes
    cout << "Enter total no. of nodes: ";
    cin >> n;

    int m; // user input for total no. of edges
    cout << "Enter total no. of edges: ";
    cin >> m;

    Graph<int> g;

    // take user input for creating edges beween nodes
    cout << "Enter two nodes to create edge betweeen them : " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }
    // printing the graph
    g.printAdjList();
    return 0;
}