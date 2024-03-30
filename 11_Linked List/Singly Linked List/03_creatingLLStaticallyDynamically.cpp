#include <bits/stdc++.h>
#include "02_linkedListClass.cpp"

using namespace std;

int main()
{
    // creating LL statically
    Node n1(1);
    Node *head = &n1;

    Node n2(2);
    n1.next = &n2;

    cout << n1.data << " " << n2.data << endl;
    cout << head->data << " " << head->next->data << endl;

    // creating LL dynamically
    Node *n3 = new Node(10);
    Node *head2 = n3;
    Node *n4 = new Node(20);
    n3->next = n4;

    cout << n3->data << " " << n4->data << endl;
    cout << head2->data << " " << head2->next->data << endl;

    return 0;
}