#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void print(Node *head)
{
    cout << head->data << " ";
    Node *temp = head->next;
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// take input for singly circular LL
Node *takeInput()
{
    // we can not ask size as linked list is dynamic
    // so will take input as linked list node
    // untill -1 is given.
    cout << "enter your linked list: " << endl;
    int data;
    cin >> data;
    Node *head = nullptr;
    Node *tail = nullptr;

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
            // link newNode with previos node
            tail->next = newNode;
            // update tail now
            tail = newNode;
            // or, tail = tail->next;
        }
        // further input for nodes
        cin >> data;
    }
    // attach tail with head;
    tail->next = head;
    // returning head of the linked list
    return head;
}

int length(Node *head)
{
    //  in case of empty node
    if (head == nullptr)
    {
        return 0;
    }
    Node *temp = head->next;
    int ans = 1;
    while (temp != head)
    {
        ans++;
        temp = temp->next;
    }
    return ans;
}

Node *insertNode(Node *head, int index, int data)
{
    // inserting in 0th index. means as a head of the LL
    if (index == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;

        // Node to traverse till the last node
        Node *temp = head->next;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        // attach temp with newNode
        temp->next = newNode;
        // update head
        head = newNode;
        return head;
    }
    // check for valid index
    int len = length(head);
    if (index >= len)
    {
        return head;
    }
    // insert at middle of the LL
    int i = 0;
    Node *temp = head;
    while (i < index - 1)
    {
        i++;
        temp = temp->next;
    }
    Node *newNode = new Node(data);
    Node *a = temp->next;
    temp->next = newNode;
    newNode->next = a;
    return head;
}

// delete node with ith index
Node *deleteNode(Node *head, int i)
{
    // deleting head node
    if (i == 0)
    {
        Node *temp = head;
        head = head->next;
        // traverse to find last node
        Node *last = head;
        while (last->next != temp)
        {
            last = last->next;
        }
        last->next = head;
        delete temp;
        return head;
    }
    // check for valid index
    int len = length(head);
    if (i >= len)
    {
        return head;
    }
    // deleting mid nodes
    int cnt = 1;
    Node *temp = head;
    while (cnt < i)
    {
        temp = temp->next;
        cnt++;
    }
    Node *a = temp->next;
    temp->next = head;
    delete a;
    return head;
}

// detect cycle in a linked list
// T:O(n), S:O(n)
bool detectCycle(Node *head)
{
    if (head == nullptr)
    {
        return false;
    }
    Node *temp = head;
    // map to store node and check if node is visited
    map<Node *, bool> visited;
    while (temp != nullptr)
    {
        // if temp is already visited, then there is cycle
        if (visited[temp] == true)
        {
            return true;
        }
        // mark temp as visited
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// detect cycle using floyd's formula
// T:O(n), S:O(1)
bool floydDetectCycle(Node *head)
{
    if(head == nullptr)
    {
        return false;
    }
    Node* slow = head;
    Node* fast = head;

    while(slow != nullptr && fast != nullptr)
    {
    // run fast as twice as slow
        fast = fast->next;
        // check if fast has become null
        if(fast != nullptr)
        {
            fast = fast->next;
        }
        // update slow
        slow = slow->next;
        // if slow and fast are same, then there is cycle
        if(fast == slow && fast != nullptr && slow != nullptr)
        {
            return true;
        }
    }
    // function comes out of the loop
    // so no loop is there
    return false;
}

int main()
{
    Node *head = takeInput();
    print(head);
    if (detectCycle(head))
    {
        cout << "cycle present" << endl;
    }
    else
    {
        cout << "no cycle there" << endl;
    }

    Node *a = new Node(10);
    Node *b = new Node(20);
    a->next = b;
    if (detectCycle(a))
    {
        cout << "cycle present" << endl;
    }
    else
    {
        cout << "no cycle there" << endl;
    }

     if (floydDetectCycle(head))
    {
        cout << "cycle present" << endl;
    }
    else
    {
        cout << "no cycle there" << endl;
    }

    if (floydDetectCycle(a))
    {
        cout << "cycle present" << endl;
    }
    else
    {
        cout << "no cycle there" << endl;
    }
    return 0;
}