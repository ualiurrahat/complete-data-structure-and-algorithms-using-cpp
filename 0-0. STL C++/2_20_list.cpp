// list in cpp STL
// list: bidirectional linear list which shows
// effective deletion and insertion operation.
// list is used when we need to insert and delete elements very fast.
// linked list is a non-sequential data structure.
// linked list is a connection of nodes
// having data and address.
// and the address inside the node will be next address.
#include <iostream>
#include <string>
#include <list> // header file for list(double linked list).
#include <algorithm>

using namespace std;

void display(list<int> &li)
{
    // you can not show list like vector(like previous code).
    // creating iterator to display list.
    // list only works with pointers....ie. iterators.
    cout << "Displaying this list: ";
    list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    // ways to write list.
    // way 1:
    list<int> l1;
    l1.assign({18, 1, 8, 20, 25});

    display(l1);

    // way 2;
    list<int> l2 = {20, 1, 13, 14, 14};
    display(l2);

    // way 3
    list<int> l3;
    l3.push_back(10);
    l3.push_back(20);
    l3.push_back(30);
    l3.push_back(40);
    l3.push_back(50);

    display(l3);

    // way 4.
    list<int> l4(3); // list with 3 size but no input.
    list<int>::iterator iter = l4.begin();
    *iter = 2020;
    iter++;
    *iter = 2040;
    iter++;
    *iter = 2060;

    display(l4);

    // sorting list;
    l1.sort();
    cout << "list 1 after sorting....";
    display(l1);

    // removing element from list;
    l2.remove(14); // will remove all 14 from l2.
    cout << "list2 after removing 14....";
    display(l2);

    // poping elements.
    l3.pop_back();
    cout << "list3 after popping last element...";
    display(l3);

    l4.pop_front();
    cout << "list4 after popping first element....";
    display(l4);

    // merging list.
    l1.merge(l2);
    cout << "list1 after merging with list2....";
    display(l1);

    l1.sort();
    display(l1);

    cout << l1.size() << endl;

    return 0;
}