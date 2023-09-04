#include <bits/stdc++.h>
#include "8_0_LinkedListClass.cpp"

using namespace std;

void print_linked_list(Node *head)
{
    // using a temp pointer as head is better
    // if there is chance of head pointer gets changed 
    // here, we are sending a copy of head pointer address
    // so, no change is happening in main() function's head node
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node n1(18);
    Node n2(1);
    Node n3(8);
    Node n4(25);
    Node n5(20);

    Node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    cout << "head address: " << head << endl;

    print_linked_list(head);
    // we send a copy of head pointer as a parameter
    // in the print linked list function
    // so our head pointer in main function
    // remains unchanged
    print_linked_list(head);

    cout << head->data << endl;
    cout << "head address: " << head << endl;

    return 0;
}