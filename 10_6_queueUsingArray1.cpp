#include <bits/stdc++.h>
#include "10_5_queueUsingArrayclass1.cpp"

using namespace std;

int main()
{
    QueueUsingArray<int> q(5);
    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.enqueue(40);
    // q.enqueue(50);
    // q.enqueue(60); // queue full msg will show!!!

    // cout << q.front() << endl;
    // cout << q.deque() << endl;
    // cout << q.deque() << endl;
    // cout << q.deque() << endl;
    // cout << q.deque() << endl;
    // cout << q.getSize() << endl;
    // cout << q.isEmpty() << endl;
    cout << q.isEmpty() << endl; // 1
  q.enqueue(18);
  cout << q.front() << endl; // 18
  q.enqueue(1);
  q.enqueue(8);
  cout << q.getSize() << endl; // 3
  q.enqueue(5);
  q.enqueue(20);
  q.enqueue(100); // queue is full
  cout << q.getSize() << endl; // 5
  cout << q.deque() << endl; // 18
  cout << q.deque() << endl; // 1
  cout << q.front() << endl; // 8
  cout << q.deque() << endl; // 8
  cout << q.deque() << endl;// 5 
  cout << q.deque() << endl; // 20
  cout << q.deque() << endl; //
  cout << q.deque() << endl; //

    return 0;
}