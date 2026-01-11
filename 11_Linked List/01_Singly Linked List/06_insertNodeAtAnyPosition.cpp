/*
Problem Statement:
------------------
Insert a node at any given position (index-based) in a singly linked list.
The index starts from 0. If the index is 0, the new node becomes the head.
For any other valid index, the node is inserted at that position while
preserving the existing order of nodes.
*/

#include <iostream>
#include "02_linkedListClass.cpp"

using namespace std;

/*
Function: takeInputBetter
-------------------------
This is an optimized (better) approach to take user input for a linked list.

Key ideas explained clearly:
- We do NOT ask for the size of the linked list because linked lists are dynamic.
- Input is taken until the sentinel value `-1` is encountered.
- We maintain both `head` and `tail` pointers to achieve O(1) insertion at the end.
- This avoids traversing the entire list for each insertion (which would be inefficient).

Returns:
- Pointer to the head of the newly created linked list.

Time Complexity:
- O(n), where n is the number of nodes entered by the user.

Space Complexity:
- O(n), for storing n nodes in the linked list.
*/
Node *takeInputBetter()
{
    cout << "Enter your data (enter -1 to exit): ";

    int data;

    // Initializing head and tail pointers as nullptr
    // head -> points to the first node of the list
    // tail -> always points to the last node of the list
    Node *head = nullptr;
    Node *tail = nullptr;

    cin >> data;

    // Continue taking input until sentinel value -1 is encountered
    while (data != -1)
    {
        // Creating a new node with the given data
        Node *newNode = new Node(data);

        // If this is the first node, both head and tail should point to it
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // Attaching the new node at the end of the list
            tail->next = newNode;

            // Updating the tail pointer to the newly added node
            tail = newNode;
        }

        cout << "Enter your data (enter -1 to exit): ";
        cin >> data;
    }

    // Returning the head of the linked list
    return head;
}

/*
Function: printLinkedList
-------------------------
Prints the elements of the linked list in a readable format.

Important notes for learners:
- We traverse the list using a temporary pointer.
- The original head pointer passed from main() remains unchanged
  because a copy of the pointer is used here.

Output format:
- data1->data2->data3->null

Time Complexity:
- O(n), where n is the number of nodes in the linked list.

Space Complexity:
- O(1), as no extra space proportional to input size is used.
*/
void printLinkedList(Node *head)
{
    // Traversing the linked list until we reach the end (nullptr)
    while (head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }

    cout << "null" << endl;
}

/*
Function: insertNode
--------------------
Inserts a new node at a specified index in the linked list.

Parameters:
- head : Pointer to the head of the linked list
- i    : Index at which the new node should be inserted (0-based)
- data : Data value for the new node

Detailed explanation:
- If index i == 0:
  - The new node becomes the new head of the list.
- For index i > 0:
  - We traverse the list to reach the (i-1)th node.
  - The new node is inserted after that node.
- If the index is invalid (greater than list length), no insertion occurs.

Returns:
- Updated head pointer of the linked list.

Time Complexity:
- O(1) for insertion at the beginning.
- O(n) for insertion at any other position.

Space Complexity:
- O(1), excluding the space used for the new node.
*/
Node *insertNode(Node *head, int i, int data)
{
    // Creating the new node with the provided data
    Node *newNode = new Node(data);

    // Case 1: Inserting at the beginning of the linked list
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;

        // Returning updated head since head has changed
        return head;
    }

    // Counter to keep track of the current index
    int count = 0;

    // Temporary pointer used to traverse the list
    Node *temp = head;

    // Traversing the list to reach the (i-1)th position
    // Conditions ensure:
    // - We do not dereference a null pointer
    // - We stop exactly one position before index i
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    // If temp is valid, perform insertion
    if (temp != nullptr)
    {
        // Storing the next node temporarily
        Node *nextNode = temp->next;

        // Linking new node at the correct position
        temp->next = newNode;
        newNode->next = nextNode;

        // Alternative concise approach (commented for learning clarity):
        // newNode->next = temp->next;
        // temp->next = newNode;
    }

    // Returning head (unchanged for i > 0)
    return head;
}

int main()
{
    // Creating a linked list using optimized input method
    Node *head = takeInputBetter();

    // Printing the initial linked list
    printLinkedList(head);

    // Inserting three new nodes based on user input
    for (int j = 0; j < 3; j++)
    {
        int index;
        int data;

        cout << "Insert the index for new Node: ";
        cin >> index;

        cout << "Insert data for new Node: ";
        cin >> data;

        // Inserting node and updating head if required
        head = insertNode(head, index, data);

        // Printing the linked list after each insertion
        printLinkedList(head);
    }

    return 0;
}
