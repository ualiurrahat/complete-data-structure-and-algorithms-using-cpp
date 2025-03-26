#include <iostream>   // For cout, endl
#include <queue>      // For priority_queue
#include <utility>    // For pair, make_pair
#include <vector>     // For vector
#include <functional> // For greater<int>
using namespace std;

int main()
{
    // Stores element in descending order
    // Duplicates are allowed
    // With O(log n) time complexity
    // Operations: push, size, top, pop, empty

    priority_queue<int> pq;
    pq.push(20);
    pq.push(1);
    pq.push(13);
    pq.push(18);
    pq.push(14);
    pq.push(8);
    pq.push(25);

    cout << pq.top() << endl; // Output: 25 (largest element)
    pq.pop();
    cout << pq.top() << endl; // Output: 20 (next largest)

    // Pair inside a priority queue
    priority_queue<pair<int, int>> pp;
    pp.push(make_pair(18, 25));
    pp.push(make_pair(8, 5));
    pp.push(make_pair(1, 2));

    // Easy technique to get min priority queue
    // Insert elements with negative value (-x)
    // Print elements multiplying with -1: (-x) * (-1)

    priority_queue<int> p;
    p.push(-1);
    p.push(-3);
    p.push(-4);
    p.push(-6);

    cout << (-1) * p.top() << endl; // Output: 1 (smallest element: -(-1))

    // Syntax for creating an actual min priority queue
    priority_queue<int, vector<int>, greater<int>> mini;
    mini.push(18);
    mini.push(1);
    mini.push(8);
    mini.push(5);
    mini.push(20);

    cout << mini.top() << endl; // Output: 1 (smallest element)

    return 0;
}