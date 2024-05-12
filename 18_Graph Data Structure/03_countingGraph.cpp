/*
problem link:
https://www.naukri.com/code360/problems/counting-graphs_8357237?leftPanelTabValue=PROBLEM

problem statement:
Return the number of undirected graphs that can be formed using 'N' vertices, allowing for disconnected components within the graph. Self-edges and multiple edges are not allowed.
For Example:
For N = 2,
Count is 2.
Consider the vertices to be ‘A’ and ‘B’.
These are the possible 2 graphs.

*/

#include <bits/stdc++.h>

using namespace std;

int countingGraphs(int N)

{
    // To find the total number of "undirected" graphs by N vertices

    // can be acheived by 2^(N(N-1)/2);
    int power = N * (N - 1) / 2;

    return pow(2, power);
}

int main()
{
    cout << countingGraphs(5);

    return 0;
}