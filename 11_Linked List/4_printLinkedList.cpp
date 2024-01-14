#include <bits/stdc++.h>
#include "2_linkedListClass.cpp"

using namespace std;

// function to print linked list
void printLinkedList(Node *head)
{
    // using a temp pointer as head is better
    // if there is chance of head pointer gets changed
    // ex: Node* temp = head;
    // here, we are sending a copy of head pointer address
    // so, no change is happening in main() function's head node
    while (head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "null" << endl;
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

    printLinkedList(head);
    // we send a copy of head pointer as a parameter
    // in this printLinkedList function
    // so our head pointer in main function
    // remains unchanged
    printLinkedList(head);

    cout << head->data << endl;
    cout << "head address: " << head << endl;

    return 0;
}