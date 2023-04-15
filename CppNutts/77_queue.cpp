/*
queue - container adaptor.
FIFO : First In First Out

*/
#include <iostream>
#include <string>
#include <queue> // header file for queue.

using namespace std;

int main()
{
    queue <int> q;
    q.push(18);
    q.push(1);
    q.push(8);
    q.push(25);
    q.push(20);

    cout << q.front() << " ";
    cout << q.back() << endl;
    q.pop();
    cout << q.front();
    cout << endl;
    cout << "size: " << q.size() << endl;
    

    
    return 0;
}