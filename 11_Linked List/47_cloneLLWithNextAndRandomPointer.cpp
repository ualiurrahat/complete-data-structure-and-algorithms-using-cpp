/*You are given a linked list containing 'n' nodes, where every node in the linked list contains two pointers:
(1) ‘next’ which points to the next node in the list
(2) ‘random’ which points to a random node in the list or 'null'.
Your task is to create a 'deep copy' of the given linked list and return its head.
Note:
A 'deep copy' of a linked list means we do not copy the references of the nodes of the original linked list, rather for each node in the original linked list, a new node is created
*/
#include <bits/stdc++.h>
using namespace std;
// Definition for linked list.
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node() : data(0), next(nullptr), random(nullptr){};
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
    Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
};

// brute force solution to clone LL
Node *cloneLL(Node *head)
{
    // step 1: take a map and store copy nodes co-relating with orignal node of same data
    Node *temp = head;
    map<Node *, Node *> mpp;

    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }
    // step 2: connect next and random pointers in the copy list
    temp = head;
    while (temp != NULL)
    {
        Node *copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];

    // T:O(n*mapOperation)+ O(n) = O(2*n*mapOperation)
    // S:O(n)[for map] + O(n)[for clone list] = O(2*n)
}
// optimal solution
Node *cloneLLOptimal(Node *head)
{
    // step 1: insert copynodes inbetween
    Node *temp = head;
    while (temp != NULL)
    {
        Node *nextElement = temp->next;
        Node *copyNode = new Node(temp->data);
        copyNode->next = nextElement;
        temp->next = copyNode;
        temp = nextElement;
    }
    // step 2: connect random pointers
    temp = head;
    while (temp != NULL)
    {
        Node *copyNode = temp->next;
        if (temp->random)
        {
            copyNode->random = temp->random->next;
        }
        else
        {
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }

    // step 3: connect next pointer
    temp = head;
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while (temp != NULL)
    {
        // creating new list
        res->next = temp->next;
        res = res->next;
        // disconnecting and going back to
        // initial start of the LL
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;

    // S:O(n), for copy list
    // T:O(3n)
}