/*Y ou are given a linked list containing 'n' 'head' nodes, where every node in the linked list contains two pointers:
(1) ‘next’ which points to the next node in the list
(2) ‘child’ pointer to a linked list where the current node is the head.
Each of these child linked lists is in sorted order and connected by 'child' pointer.
Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.
*/
#include <bits/stdc++.h>

using namespace std;

// Node class for flatten Linked List.
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

// function to convert array into vertical LL
// vertical LL means each node will be connected to the other as child node,not next node.
Node *convertArrayIntoFlattenList(vector<int> &arr)
{
    // create head of list with array's first element.
    Node *head = new Node(arr[0]);
    Node *temp = head;
    // traverse the array.
    for (int i = 1; i < arr.size(); i++)
    {
        // creating new node with arr element as data
        Node *newNode = new Node(arr[i]);
        // creating linkes with newNode to the list
        temp->child = newNode;
        // update temp node.
        temp = temp->child;
    }
    return head;
}
// brute force solution to flatten a LL
Node *flattenLinkedList(Node *head)
{
    // step 1: take an array store all node's data from the list.
    Node *temp = head;
    vector<int> arr;
    while (temp != NULL)
    {
        Node *t2 = temp;
        // going through child nodes of current temp node
        while (t2 != NULL)
        {
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        // child node traversing done.
        // moving to the next node of the list by updating temp node.
        temp = temp->next;
    }
    // step 2: sorting the array.
    sort(arr.begin(), arr.end());
    // step3: creating flatten list
    Node *newNode = convertArrayIntoFlattenList(arr);
    // returning flatten list.
    return newNode;

    /* let's assume,
     n = total horizontal nodes
     m = total child nodes of each nodes
     so n*m = total no. of nodes in the list = x
     S:O(x)[for array] + O(x)[for new flatten list] = O(2*x)
     T:O(x)[traversing array] + O(xlogx)[sorting array] + O(x)[creating list] = O(2*x+xlogx)
     */
}

// function to merge 2 lists on vertically
Node *merge(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data < list2->data)
        {
            temp->child = list1;
            temp = list1;
            list1 = list1->child;
        }
        else
        {
            temp->child = list2;
            temp = list2;
            list2 = list2->child;
        }
        temp->next = nullptr;
    }
    if (list1 != nullptr)
    {
        temp->child = list1;
    }
    else
    {
        temp->child = list2;
    }
    return dummyNode->child;
}
// optimal approach to flatten a LL
Node *flattenLinkedListBetter(Node *head)
{
    // base case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // recursive call
    Node *mergeHead = flattenLinkedList(head->next);
    // small calculation: using backtracking.
    return merge(mergeHead, head);

    /*let, n = no. of total horizontal nodes
        m = total vertical nodes(child nodes) for each horizontal node
        S:O(n), for recursive stack space
        T:(n)[for calling recursive flatten list function] * O(2*m)[for merge function] = T:O(2*n*m)
        */
}

int main()
{

    return 0;
}