// linked list in c++ STL.
#include <iostream>
#include <string>
#include <forward_list> // for single linked list.
#include <list>         // for doubly linked list.

using namespace std;

// singly linked list.
// Every node has two elements: data and address of the next node.
// also known as forward list.
// doubly linked list has 3 elements in each node:
// previous node address, data, next node address.
// The last node of any list points to null.

void display(forward_list<int> &li)
{
    // you can not show list like vector(like previous code).
    // so need to create iterator to display list.
    // list only works with pointers....ie. iterators.
    cout << "Displaying this linked list: ";
    forward_list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    // Singly LL
    // creating assigning value directly
    forward_list<int> l1 = {2, 5, 6, 7};
    // 2 is head of l1 and 7 is the tail.

    //printing the first element.
    cout << l1.front() << endl;

    // printing whole l1
    display(l1);

    // creating another single linked list.
    forward_list<int> l2;
    // assigning value with assign() function
    l2.assign({3, 8, 9, 13});

    cout << l2.front() << endl;
    l2.push_front(10);
    cout << l2.front() << endl;

    return 0;
}