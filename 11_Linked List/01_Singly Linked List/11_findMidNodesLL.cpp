/*
File Name: 11_findMidNodesLL.cpp
------------------------------------------------------------

Problem Statement:
------------------
Given the head of a singly linked list, return the middle node of the linked list.

Rules:
- If the linked list has an odd number of nodes, return the exact middle node.
- If the linked list has an even number of nodes, there will be TWO middle nodes.
  In that case, return the SECOND middle node.

Examples:
----------
Input:  head = [1, 2, 3, 4, 5]
Output: [3, 4, 5]
Explanation:
The middle node is node with value 3.

Input:  head = [1, 2, 3, 4, 5, 6]
Output: [4, 5, 6]
Explanation:
The two middle nodes are 3 and 4.
According to the problem, we return the SECOND middle node (4).

------------------------------------------------------------
Learning Objective:
-------------------
This problem helps in understanding:
- Linked list traversal
- Length-based (brute-force) solutions
- Two-pointer optimization techniques (Tortoise & Hare)
- Why optimized solutions are preferred over brute-force approaches
*/

/* ============================================================
   NOTE:
   -----
   The following section is an EXACT continuation of the code
   up to file 10 (delete node recursively). No logic is changed.
   Only professional rewriting of comments is preserved.
   ============================================================ */

#include <iostream>
#include "02_linkedListClass.cpp"

using namespace std;

/*
Function: takeInputBetter
-------------------------
Takes user input to construct a singly linked list using an
optimized approach.

Key Concepts:
- Linked lists are dynamic, so size is not asked beforehand.
- Input continues until sentinel value `-1` is entered.
- Maintaining both head and tail pointers allows O(1) insertion
  at the end of the list.

Returns:
- Pointer to the head of the constructed linked list.

Time Complexity:
- O(n), where n is the number of nodes.

Space Complexity:
- O(n), for storing n nodes.
*/
Node *takeInputBetter()
{
    cout << "Enter your data (enter -1 to exit): ";

    int data;
    Node *head = nullptr;
    Node *tail = nullptr;

    cin >> data;

    while (data != -1)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        cout << "Enter your data (enter -1 to exit): ";
        cin >> data;
    }

    return head;
}

/*
Function: printLinkedList
-------------------------
Prints the linked list in a readable format.

Important Note:
- The head pointer passed is a COPY.
- Traversing it does NOT affect the original list.

Output Format:
data1->data2->data3->null

Time Complexity:
- O(n)

Space Complexity:
- O(1)
*/
void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "null" << endl;
}

/*
Function: length
----------------
Computes the length of the linked list iteratively.

Returns:
- Total number of nodes.

Time Complexity:
- O(n)

Space Complexity:
- O(1)
*/
int length(Node *head)
{
    if (head == nullptr)
    {
        return 0;
    }

    int count = 1;
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
Computes the length of the linked list using recursion.

Concept:
- Each recursive call handles a smaller linked list.
- Length is built during backtracking.

Time Complexity:
- O(n)

Space Complexity:
- O(n), due to recursion stack.
*/
int lengthRecursively(Node *head)
{
    if (head == nullptr)
    {
        return 0;
    }

    if (head->next == nullptr)
    {
        return 1;
    }

    int smallLength = lengthRecursively(head->next);
    return smallLength + 1;
}

/*
Function: deleteNodeRecursively
-------------------------------
Deletes a node at index `i` using recursion.

Indexing:
- 0-based

Time Complexity:
- O(n)

Space Complexity:
- O(n), due to recursion stack.
*/
Node *deleteNodeRecursively(Node *head, int i)
{
    if (head == nullptr)
    {
        return head;
    }

    if (i == 0)
    {
        Node *nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
        return head;
    }

    Node *smallHead = deleteNodeRecursively(head->next, i - 1);
    head->next = smallHead;

    return head;
}

/*
Function: middleNodeBrute
-------------------------
Finds the middle node using the length of the linked list.

Approach:
1. Calculate the total length of the linked list.
2. Traverse length/2 steps from the head.
3. Return the node reached.

Why this works:
- For odd length, length/2 gives exact middle.
- For even length, integer division ensures we reach the
  SECOND middle node (as required).

Time Complexity:
- O(n) + O(n/2) = O(3n/2)

Space Complexity:
- O(1)
*/
Node *middleNodeBrute(Node *head)
{
    int len = length(head);

    int count = 0;
    Node *temp = head;

    while (count < len / 2)
    {
        temp = temp->next;
        count++;
    }

    return temp;
}

/*
Function: middleNode
--------------------
Finds the middle node using the Tortoise and Hare algorithm.

Approach:
- slow pointer moves one step at a time.
- fast pointer moves two steps at a time.
- When fast reaches the end, slow is at the middle.

Key Insight:
- For even-length lists, slow automatically ends up at the
  SECOND middle node.

Time Complexity:
- O(n)

Space Complexity:
- O(1)

Why this is better:
- Single traversal
- No need to calculate length
*/
Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    // Construct linked list from user input
    Node *head = takeInputBetter();
    cout << "\nOriginal Linked List:\n";
    printLinkedList(head);

    // Brute-force approach
    Node *midBrute = middleNodeBrute(head);
    cout << "\nMiddle Node (Brute Force): ";
    cout << midBrute->data << endl;

    // Optimized approach (Tortoise & Hare)
    Node *midOptimal = middleNode(head);
    cout << "Middle Node (Tortoise & Hare): ";
    cout << midOptimal->data << endl;

    return 0;
}
