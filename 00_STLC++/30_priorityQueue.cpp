#include <bits/stdc++.h>

using namespace std;

int main()
{
    // stores element in descending order
    // duplicates are allowed.
    // with O(logn).
    // operation: push, size, top, pop, empty

    priority_queue<int> pq;
    pq.push(20);
    pq.push(1);
    pq.push(13);
    pq.push(18);
    pq.push(14);
    pq.push(8);
    pq.push(25);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    // pair inside a priority queue

    priority_queue<pair<int, int>> pp;
    pp.push(make_pair(18, 25));
    pp.push(make_pair(8, 5));
    pp.push(make_pair(1, 2));

    // easy technique to get min priority queue.
    // insert elements with negetaive value(-x)
    // print elements multiplying with -1. (-x) * (-1).

    priority_queue<int> p;
    p.push(-1);
    p.push(-3);
    p.push(-4);
    p.push(-6);

    cout << (-1) * p.top() << endl;

    //  syntax for creating originally min priority queue
    priority_queue<int, vector<int>, greater<int>> mini;
                  // <dataType,vector<dataType>,greater<int>>
    mini.push(18);
    mini.push(1);
    mini.push(8);
    mini.push(5);
    mini.push(20);

    cout << mini.top() << endl;

    return 0;
}