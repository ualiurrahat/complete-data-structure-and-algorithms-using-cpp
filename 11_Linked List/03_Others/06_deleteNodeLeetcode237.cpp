/*
Problem Statement: LeetCode 237 — Delete Node in a Linked List
------------------------------------------------------------

There is a singly linked list and we want to delete a given node from it.

You are given ONLY the node to be deleted. You will NOT be given access
to the head of the linked list.

Important guarantees:
- All values of the linked list are unique.
- The given node is NOT the last node in the linked list.
- The given node is guaranteed to exist in the linked list.

What does "delete" mean here?
- The value of the given node should no longer exist in the linked list.
- The total number of nodes in the linked list should decrease by one.
- All nodes before the given node remain in the same order.
- All nodes after the given node remain in the same order.

Example:
Input:
head = [4, 5, 1, 9], node = 5

Output:
[4, 1, 9]

Explanation:
You are given direct access to the node with value 5.
After deletion, the linked list becomes:
4 -> 1 -> 9

------------------------------------------------------------
Key Insight (Very Important for Understanding):
------------------------------------------------------------
Since the head pointer is NOT available:
- We cannot traverse from the beginning
- We cannot find the previous node
- We cannot delete the given node in the traditional way

Instead:
- We copy the value of the NEXT node into the current node
- Then bypass and delete the next node

Effectively, the given node "becomes" the next node.
*/

// ------------------------------------------------------------
// Definition for singly-linked list node.
// ------------------------------------------------------------
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// ------------------------------------------------------------
// Function: deleteNode
// ------------------------------------------------------------
// Deletes the given node from the linked list without access
// to the head pointer.
//
// Parameters:
// - node: pointer to the node that must be deleted
//
// Important Notes:
// - The given node is NOT the last node (guaranteed by problem).
// - This allows us to safely access node->next.
//
// Time Complexity:
// - O(1), since no traversal is required.
//
// Space Complexity:
// - O(1), as no extra memory proportional to input size is used.
// ------------------------------------------------------------
void deleteNode(ListNode *node)
{
    // Step 1:
    // Copy the value of the next node into the current node.
    // This overwrites the data of the node that we want to "delete".
    node->val = node->next->val;

    // Step 2:
    // Store the next node temporarily.
    // This node will be removed from the list.
    ListNode *nodeToDelete = node->next;

    // Step 3:
    // Bypass the next node by linking current node
    // directly to the node after next.
    node->next = node->next->next;

    // Step 4:
    // Delete the bypassed node to free memory.
    delete nodeToDelete;
}
