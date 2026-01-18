/*
Problem Statement:
------------------
Determine the length of a singly linked list.

This file is part of a step-by-step linked list learning series. It combines:
- Taking user input for a linked list using an optimized approach
- Printing the linked list
- Inserting nodes (iterative and recursive versions, reused for continuity)
- Calculating the length (number of nodes) of the linked list

The goal is not just functionality, but also clarity for learners who are
building intuition from brute-force thinking to optimized reasoning.
*/

#include <iostream>
#include "02_linkedListClass.cpp"

using namespace std;

/*
Function: takeInputBetter
-------------------------
An optimized approach to take user input for creating a linked list.

Learning-oriented explanation:
- We do NOT ask for the size of the linked list because a linked list is dynamic.
- Input continues until the sentinel value `-1` is entered by the user.
- Maintaining both `head` and `tail` pointers allows us to insert new nodes
  at the end in constant time O(1).
- This avoids repeated traversal of the linked list, which would be inefficient.

Returns:
- Pointer to the head of the constructed linked list.

Time Complexity:
- O(n), where n is the number of nodes entered by the user.

Space Complexity:
- O(n), as memory is allocated for n nodes.
*/
Node *takeInputBetter()
{
    cout << "Enter your data (enter -1 to exit): ";

    int data;

    // head -> points to the first node of the linked list
    // tail -> points to the last node of the linked list
    Node *head = nullptr;
    Node *tail = nullptr;

    cin >> data;

    // Continue taking input until sentinel value (-1) is encountered
    while (data != -1)
    {
        // Create a new node using the user-provided data
        Node *newNode = new Node(data);

        // Case 1: Linked list is empty
        // The new node becomes both head and tail
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // Case 2: Linked list already has nodes
            // Attach the new node after the current tail
            tail->next = newNode;

            // Update tail to point to the newly added node
            tail = newNode; // equivalent to: tail = tail->next;
        }

        cout << "Enter your data (enter -1 to exit): ";
        cin >> data;
    }

    // Return the head pointer of the constructed linked list
    return head;
}

/*
Function: printLinkedList
-------------------------
Prints the elements of the linked list in a readable format.

Important conceptual clarification:
- The `head` pointer received here is a copy of the pointer from `main()`.
- Any movement of this pointer inside this function does NOT affect
  the original head pointer in `main()`.
- This makes the function safe and side-effect free.

Output Format:
- data1->data2->data3->null

Time Complexity:
- O(n), where n is the number of nodes in the linked list.

Space Complexity:
- O(1), as no extra memory proportional to input size is used.
*/
void printLinkedList(Node *head)
{
    // Traverse the linked list until the end (nullptr) is reached
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
Inserts a node at a specified index using an iterative approach.

Parameters:
- head : Pointer to the head of the linked list
- i    : Index (0-based) where the new node should be inserted
- data : Data value of the new node

Conceptual explanation:
- If i == 0, the new node is inserted at the beginning and becomes the new head.
- Otherwise, we traverse the list to reach the (i-1)th node.
- The new node is inserted by carefully adjusting `next` pointers
  without breaking the existing list.

Returns:
- Updated head pointer of the linked list.

Time Complexity:
- O(1) for insertion at index 0
- O(n) for insertion at any other valid index
*/
Node *insertNode(Node *head, int i, int data)
{
    // Create a new node with the given data
    Node *newNode = new Node(data);

    // Case: inserting at the beginning of the linked list
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Counter to track current index during traversal
    int count = 0;

    // Temporary pointer used for traversal
    Node *temp = head;

    // Traverse until we reach the (i-1)th node or the list ends
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    // Insert only if a valid position is found
    if (temp != nullptr)
    {
        Node *nextNode = temp->next;
        temp->next = newNode;
        newNode->next = nextNode;

        // Alternative insertion logic (shown for understanding):
        // newNode->next = temp->next;
        // temp->next = newNode;
    }

    // Return the (possibly unchanged) head pointer
    return head;
}

/*
Function: insertNodeRecursively
-------------------------------
Inserts a node at a given index using recursion.

Parameters:
- head : Pointer to the current node of the linked list
- i    : Index at which the new node should be inserted
- data : Data value of the new node

Recursive reasoning breakdown:
1. Edge Case:
   - If head is nullptr, insertion is not possible.
2. Base Case:
   - If i == 0, create a new node and attach it before the current head.
3. Recursive Case:
   - Move forward in the list while decrementing index.
   - Reconnect the updated smaller list during backtracking.

Returns:
- Updated head pointer after insertion.

Time Complexity:
- O(n), where n is the index at which insertion occurs.

Space Complexity:
- O(n), due to recursive call stack usage.
*/
Node *insertNodeRecursively(Node *head, int i, int data)
{
    // Edge case: empty list
    if (head == nullptr)
    {
        return head;
    }

    // Base case: correct position reached
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Recursive call on the remaining linked list
    Node *smallHead = insertNodeRecursively(head->next, i - 1, data);

    // Small calculation during backtracking
    head->next = smallHead;

    return head;
}

/*
Function: length
----------------
Calculates the length of the linked list.

Definition:
- Length = total number of nodes present in the linked list.

Important conceptual note:
- The head pointer passed to this function is a copy.
- Traversing it does NOT affect the original head in main().

Returns:
- Integer count representing the number of nodes.

Time Complexity:
- O(n), where n is the number of nodes.

Space Complexity:
- O(1), no extra memory is used.
*/
int length(Node *head)
{
    // If the list is empty, length is 0
    if (head == nullptr)
    {
        return 0;
    }

    int count = 1;

    // Traverse until the last node is reached
    while (head->next != nullptr)
    {
        head = head->next;
        count++;
    }

    return count;
}
/*
Function: lengthRecursively
---------------------------
Calculates the length of a singly linked list using recursion.

Conceptual breakdown (important for learners):
- The function works by reducing the problem size at each recursive call.
- Each call focuses on a smaller linked list starting from `head->next`.
- The final length is built during the return phase of recursion.

Step-by-step reasoning:
1. Edge Case:
   - If the head pointer is nullptr, the linked list is empty.
   - In this case, the length is 0.
2. Base Case:
   - If the current node is the last node (i.e., head->next == nullptr),
     the length contributed by this node is 1.
3. Recursive Case:
   - Recursively calculate the length of the remaining linked list.
   - Add 1 to account for the current node.

Parameters:
- head : Pointer to the current node of the linked list

Returns:
- Integer value representing the total number of nodes in the linked list.

Time Complexity:
- O(n), where n is the number of nodes in the linked list.

Space Complexity:
- O(n), due to recursive call stack usage.
*/
int lengthRecursively(Node *head)
{
    // Edge case:
    // If the linked list is empty, its length is 0
    if (head == nullptr)
    {
        return 0;
    }

    // Base case:
    // If this is the last node, count it and stop recursion
    if (head->next == nullptr)
    {
        return 1;
    }

    // Recursive call:
    // Calculate length of the remaining smaller linked list
    int smallLength = lengthRecursively(head->next);

    // Small calculation:
    // Add 1 for the current node
    return smallLength + 1;
}

int main()
{
    // Taking user input to create the linked list
    Node *head = takeInputBetter();

    // Printing the address stored in head
    cout << head << endl;

    // Printing the entire linked list
    printLinkedList(head);

    // Calculating the length of the linked list
    int count = length(head);
    cout << "length: " << count << endl;

    // Printing head again to show it remains unchanged
    cout << head << endl;

    // Explanation reminder:
    // The head pointer inside main() is NOT modified by length(),
    // because only a copy of the pointer is passed to the function.

    return 0;
}
