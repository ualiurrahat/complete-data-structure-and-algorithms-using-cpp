// here, we will overload cin and cout.
// cin >> head; will take LL input
// cout << head; will print LL
// we can do this too: cin >> head>>head2 and cout << head << head2;

#include <bits/stdc++.h>

using namespace std;

// class for creating nodes for linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        data = n;
        next = nullptr;
    }
};

// class for reverseLL in a better complexity
// this will return an object
// having head and tail property
class Pair
{
public:
    Node *head;
    Node *tail;
};

// to print the linked list
void print(Node *head)
{
    cout << "linked list: ";
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// take user given linked list as input
Node *takeInput()
{
    cout << "enter your linked list: ";
    int data;
    cin >> data;
    // pointer for head
    Node *head = nullptr;
    // pointer for tail
    // used to link new nodes with its previous nodes
    Node *tail = nullptr;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

// functon to insert node in linked list
// i = index in the list
// data = value of the node

Node *insertNode(Node *head, int i, int data)
{
    // if node is inserted at 0th index
    // then the newNode becomes the head
    Node *newNode = new Node(data);
    if (i == 0)
    {
        // linking newNode with previous head
        newNode->next = head;
        // newNode is head now. updating head node
        head = newNode;
        return head;
    }

    // if node is inserted any other postion except 0th index
    // we need to check if the position is valid
    // means index i does not exceed the length of linked list

    // var to travese through linked list
    int count = 0;
    Node *temp = head;

    // traversing linkedList to find the appropriate position
    // for newNode
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    // checking if the position is valid
    if (temp != nullptr)
    {
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }

    return head;
}

// delete any node from the linked list
// deleting ith index here

Node *deleteNode(Node *head, int i)
{
    Node *a;

    // deleting 0th index
    if (i == 0)
    {
        a = head;          // a needs to be deleted
        head = head->next; // updating head
        delete a;          // deleting old head
        return head;
    }

    // deleting any other indexed node
    int count = 0;
    Node *temp = head;

    // loop to traverse linked list
    // to find the ith nodes that needs to be deleted.
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr)
    {
        a = temp->next;    // a needs to be deleted
        Node *b = a->next; // b is the next node of the temp node
        temp->next = b;    // updating temp's next node as b
        delete a;          // deleting ith index node
    }
    return head;
}

// find lenght of linked list
// length = total num of nodes
int length(Node *head)
{
    int count = 1;
    while (head->next != nullptr)
    {
        head = head->next;
        count++;
    }
    return count;
}

// find mid nodes.
// if even nodes are in the list,
// will show first mid node here.

Node *midPoint(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    // conditions for odd and even lengh linked list
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is the mid node
    return slow;
}

// merge two sorted linked list
Node *mergeSortedTwoLL(Node *head1, Node *head2)
{
    Node *finalHead = NULL;
    Node *finalTail = NULL;

    // traversing each LL and sorting nodes
    // for merged LL
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (finalHead == NULL)
            {
                finalHead = head1;
                finalTail = head1;
                // updating LL1
                head1 = head1->next;
            }
            else
            {
                finalTail->next = head1;
                finalTail = finalTail->next;
                head1 = head1->next;
            }
        }
        else
        {
            if (finalHead == NULL)
            {
                finalHead = head2;
                finalTail = head2;
                // updating LL2
                head2 = head2->next;
            }
            else
            {
                finalTail->next = head2;
                finalTail = finalTail->next;
                head2 = head2->next;
            }
        }
    }

    // if LL1 gets emptied, need to continue sorting with LL2
    if (head1 == NULL)
    {
        while (head2 != NULL)
        {
            finalTail->next = head2;
            finalTail = finalTail->next;
            head2 = head2->next;
        }
    }

    // if LL2 gets emptied, need to continue sorting LL1
    if (head2 == NULL)
    {
        while (head1 != NULL)
        {
            finalTail->next = head1;
            finalTail = finalTail->next;
            head1 = head1->next;
        }
    }
    return finalHead;
}

// sort a linked list using merge sort

Node *mergeSort(Node *head)
{
    // base case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // recursive case
    // 1. mid point
    Node *mid = midPoint(head);
    // dividing whole LL into two parts for merge sorting
    Node *a = head;
    Node *b = mid->next;
    // this is important. we are disconnecting the LL from head to end.
    // and dividing LL into two parts will be successul only after that
    mid->next = nullptr;

    // 2.recursively sort
    a = mergeSort(a);
    b = mergeSort(b);

    // 3. merge a and b
    Node *c = mergeSortedTwoLL(a, b);
    return c;
}

// function to reverse a linked list
// complexity: O(N^2)
Node *reverseLL(Node *head)
{
    // 1. base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // 2. recursive call
    Node *smallAns = reverseLL(head->next);

    // 3. small Calculation

    // pointer for LL traversal
    Node *temp = smallAns;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // add head as next of temp node
    temp->next = head;
    //  head->next has to be null
    head->next = NULL;
    return smallAns;
}

// function to get head and tail of a reverse LL
// but this function returns an object of pair class
// complexity: O(n)
// better than reverseLL() function

Pair reverseLL2(Node *head)
{
    // 1. base case
    if (head == nullptr || head->next == nullptr)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLL2(head->next);
    smallAns.tail->next = head;
    head->next = nullptr;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

// function to get the reverse LL from reverseLL2() function
// this function gets the reversed LL head and returns it
// as Node pointer
Node *reverseLL_Better(Node *head)
{
    return reverseLL2(head).head;
}

// best function to reverse a LL recursively
// the main conern is to find the tail and attach head as tail's next
// guess what?? - tail is head->next in the original LL
Node *reverseLL_Best(Node *head)
{
    // 1. base case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // 2. recursive call
    Node *smallAns = reverseLL_Best(head->next);

    // 3.small calculation
    Node *tail = head->next;
    tail->next = head;
    head->next = nullptr;
    return smallAns;
}

// reversing LL iteratively
Node *reverseLL_Iteratively(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next;

    while (curr != nullptr) // LL: 1 2 3 4
    {
        next = curr->next; // 2 | 3 | 4 | null
        curr->next = prev; // 1->null | 2->1->null | 3->2->1->null | 4->3->2->1->null
        prev = curr;       // 1 | 2 | 3 | 4
        curr = next;       // 2 | 3 | 4 |  null
    }

    // prev is the head node of LL
    head = prev;
    return head;
}

// function to search a particular node with key as value
// if it exists, function returns true
// otherwise false

bool search_Node_Iteratively(Node *head, int key)
{
    while (head != nullptr)
    {
        if (head->data == key)
        {
            cout << "Node with " << key << " value exists" << endl;
            return true;
        }
        else
        {
            head = head->next;
        }
    }
    cout << "No node exists with value " << key << endl;
    return false;
}

// search a node in recursive way
bool search_Node_Recursively(Node *head, int key)
{
    if (head == nullptr)
    {
        cout << "No node exists with value " << key << endl;
        return false;
    }
    if (head->data == key)
    {
        cout << "Node with value " << key << " exists" << endl;
        return true;
    }
    return search_Node_Recursively(head->next, key);
}

// overloading cin operator
istream &operator>>(istream &is, Node *&head)
{
    head = takeInput();
    return is;
}
// overloading cout operator
ostream &operator<<(ostream &os, Node *head)
{
    print(head);
    return os;
}
int main()
{
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    // taking input with cin
    cin >> head1 >> head2;
    // printing LL with cout
    cout << head1 << head2;

    return 0;
}