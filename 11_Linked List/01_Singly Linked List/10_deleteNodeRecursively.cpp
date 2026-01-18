/*
File: 10_deleteNodeRecursively.cpp

Problem Statement

Given the head of a singly linked list and an integer index i (0-based), write a function to delete the node present at index i using recursion.

If i = 0, delete the head node and return the updated head of the linked list.

For i > 0, recursively traverse the list until the target node is reached, then delete it.

If the index i is invalid (greater than or equal to the length of the list), the linked list should remain unchanged.

Ensure proper memory deallocation for the deleted node.

Return the head of the updated linked list after the recursive deletion completes.
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
// function to delete a node from the list at any index
// takes the head node and index  i as paramter.
// returns head node
/*
Function: deleteNode
--------------------
Deletes a node at a given index from a singly linked list.

Indexing:
- Index `i` is 0-based.
- i = 0 means deleting the head node.

Conceptual explanation:
- If the linked list is empty, no deletion is possible.
- If i == 0, the head node is deleted and head is updated.
- Otherwise, we traverse to the (i-1)th node and adjust pointers
  to remove the ith node safely.

Parameters:
- head : Pointer to the head of the linked list
- i    : Index of the node to be deleted

Returns:
- Updated head pointer after deletion.

Time Complexity:
- O(1) for deleting the head node
- O(n) for deleting any other node

Space Complexity:
- O(1), as no extra space proportional to input size is used.
*/
Node *deleteNode(Node *head, int i)
{
    // Edge case:
    // If the linked list is empty, nothing can be deleted
    if (head == nullptr)
    {
        return head;
    }

    // Case 1: Deleting the head node
    if (i == 0)
    {
        Node *nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
        return head;
    }

    // Case 2: Deleting any node other than the head
    int count = 0;
    Node *temp = head;

    // Traverse to the (i-1)th node
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    // Perform deletion only if index is valid
    if (temp != nullptr && temp->next != nullptr)
    {
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Return (possibly unchanged) head
    return head;
}
/*
Function: deleteNodeRecursively
-------------------------------
Deletes a node at a given index from a singly linked list using recursion.

Indexing:
- Index `i` is 0-based.
- i = 0 means deleting the head node.

Recursive intuition:
- Each recursive call reduces the problem size by moving one node forward.
- When i becomes 0, the node at that position is deleted.
- During backtracking, links are reconnected properly.

Parameters:
- head : Pointer to the current node of the linked list
- i    : Index of the node to be deleted

Returns:
- Updated head pointer of the linked list.

Time Complexity:
- O(n), where n is the index of the node to be deleted.

Space Complexity:
- O(n), due to recursive call stack usage.
*/
Node *deleteNodeRecursively(Node *head, int i)
{
    // Edge case:
    // If the linked list is empty, nothing can be deleted
    if (head == nullptr)
    {
        return head;
    }

    // Base case:
    // When index becomes 0, delete the current head node
    if (i == 0)
    {
        Node *nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
        return head;
    }

    // Recursive call:
    // Delete node from the remaining smaller linked list
    Node *smallHead = deleteNodeRecursively(head->next, i - 1);

    // Small calculation:
    // Reattach the current node to the updated smaller list
    head->next = smallHead;

    // Return current head after deletion
    return head;
}

int main()
{
    Node *head = takeInputBetter();
    printLinkedList(head);

    int i;
    for (int j = 0; j < 3; j++)
    {
        cout << "Enter index of node you wanna delete:";
        cin >> i;

        head = deleteNodeRecursively(head, i);
        printLinkedList(head);
    }
    return 0;
}