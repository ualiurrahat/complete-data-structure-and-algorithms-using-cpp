// now let's play with our own writing priority queue DS
#include "04_minPriorityQueue.h"
using namespace std;

int main()
{
    // create a min priority queue named p
    PriorityQueue p;
    // now inserting elements in the queue
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << p.size() << endl;
    cout << p.getMin() << endl;

    while (!p.isEmpty())
    {
        cout << p.removeMin() << " ";
    }
    cout << endl;

    return 0;
}