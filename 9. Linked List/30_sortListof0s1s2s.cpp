/*Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2.
 You need to sort the linked list in non-decreasing order and
  the return the head of the sorted list.


Example:
Given linked list is 1 -> 0 -> 2 -> 1 -> 2.
The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.
*/

#include <bits/stdc++.h>
using namespace std;

// Doubly LL class.
// each node has a data
// a next pointer to hold next node address
// a prev pointer to hold previous node address
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    // destructor
    ~Node()
    {
        int data = data;
        if (next != nullptr)
        {
            delete next;
            next = nullptr;
        }
        if (prev != nullptr)
        {
            delete prev;
            prev = nullptr;
        }
        cout << "memory free for node with data " << data << endl;
    }
};
// function to print Doubly LL
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "null" << endl;
}
// function to get length of a doubley LL
int length(Node *head)
{
    if (head == nullptr)
    {
        return 0;
    }
    int len = 0;
    while (head != nullptr)
    {

        head = head->next;
        len++;
    }
    return len;
}
// function to insert a node as head of the doubly LL
// takes head,tail nodes and data of the node that has to be added in the LL as parameters
// taking  references of head and tail to make changes in the head node of main() function
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // in case if head is null
    if (head == nullptr)
    {
        Node *temp = new Node(data);
        head = temp;
        // head null means tail is also null. updating tail
        tail = temp;
        return;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
// function to insert a node as tail of the doubly LL
// takes head,tail nodes and data of the node that has to be added in the LL as parameters
// taking  references of head and tail to make changes in the head node of main() function
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // if tail is null, means head is null too
    if (tail == nullptr)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
// function to insert a node at any given position of the doubly LL
// takes head,tail nodes and data of the node that has to be added in the LL
// and the postion where new node has to be placed as parameters
// taking  references of head and tail to make changes in the head node of main() function
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // in case of inserting at position 1 i.e. insert at head
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    // in case of position at any other place
    Node *temp = head;
    int i = 1;
    while (i < position - 1 && temp != nullptr)
    {
        temp = temp->next;
        i++;
    }
    // in case of inseting at last i.e. insert at tail
    if (temp != nullptr && temp->next == nullptr)
    {
        insertAtTail(head, tail, data);
        return;
    }
    // inseting at other positon except head and tail
    if (temp != nullptr)
    {
        Node *nodeToInsert = new Node(data);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }
}

// function to take input
Node *take_input()
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
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }
        // further input for nodes
        cin >> data;
    }
    // returning head of the linked list
    return head;
}

// delete node index wise
Node *deleteNode(Node *head, int index)
{
    // deleting first index
    if (index == 0)
    {
        Node *temp = head;
        temp->next->prev = nullptr;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    // deleting mid indexed nodes
    int len = length(head);
    // in case indataid index is enquired
    if (index >= len)
    {
        return head;
    }
    int count = 1;
    Node *temp = head;
    while (count < index)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next != nullptr && index < len - 1)
    {
        Node *a = temp->next;
        temp->next = a->next;
        a->next->prev = temp;
        a->next = nullptr;
        a->prev = nullptr;
        delete a;
        return head;
    }
    // deleting last index
    if (index == len - 1)
    {
        Node *a = temp->next;
        a->prev = nullptr;
        temp->next = nullptr; // temp->next = null
        return head;
    }
}
// function to convert an array into a doubly linked list
Node *convertArrayIntoDLL(int arr[], int n)
{
    // Write your code here
    Node *head = new Node(arr[0]);
    Node *tail = new Node(arr[n - 1]);

    Node *temp = head;
    for (int i = 1; i < n - 1; i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
    }
    // to add last element of array into DLL
    if (n > 1)
    {
        temp->next = tail;
        tail->prev = temp;
    }

    return head;
}
// function to delete head node of DLL
Node *deleteHead(Node *head)
{
    // Write your code here.
    // edge case: when LL has one node only
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    head = temp->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

// to delete the last node of the LL
Node *deleteLastNode(Node *head)
{
    // Write your code here
    Node *temp = head;
    // case for only one node in the list
    if (temp->next == NULL)
    {
        delete temp;
        return NULL;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    temp->prev = NULL;
    delete temp;
    return head;
}
// function to reverse a doubly LL
// approach: take a stack. insert all the LL data into it.
// starting from head. and then fill all the stack data from top to bottom
// in the LL starting from head.
Node *reverseDoublyLLBruteForce(Node *head)
{
    // edge case: if head is null
    if (head == nullptr)
    {
        return head;
    }
    // take a stack to store data of LL nodes
    stack<int> st;
    // to traverse the LL
    Node *temp = head;
    // traverse and store LL data into stack
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    // now fill up the temp data into LL starting from head.
    temp = head;
    while (temp != nullptr)
    {
        temp->data = st.top();
        // update temp to go to next node
        temp = temp->next;
        // remove top element from stack
        st.pop();
    }
    // reversing is done. return the head
    return head;
}
// T:O(n)+(n) = O(2n)
// S:O(n)

// optimal approach to reverse DLL.
// method: a DLL node has 3 elements: data,nextP,prevP
// we reversed data in previous method.
// here we will reversed the prev,next linked.
// reverse means, next pointer becomes previous and vice versa.
Node *reverseDLLOptimal(Node *head)
{
    // for single node list
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // to track the previous node of each node in LL.
    Node *last = nullptr;
    // to traverse the list.
    Node *current = head;
    while (current != nullptr)
    {
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }
    // LL is reversed.update head of the reversed LL
    head = last->prev;
    return head;
}
// T:O(n)
// S:O(1)

// function to add two numbers in the LL
Node *addTwoNumbersInLL(Node *l1, Node *l2)
{
    // take a dummy node first
    Node *dummyNode = new Node(-1);
    // we will attach our sum node starting from dummy node
    Node *curr = dummyNode;
    // to store carry
    int carry = 0;
    Node *temp1 = l1;
    Node *temp2 = l2;
    // to traverse the given two lists.
    while (temp1 != nullptr || temp2 != nullptr)
    {
        int sum = carry;
        // take dataue from lists only if they are not nullptr.
        if (temp1)
        {
            sum = sum + temp1->data;
        }
        if (temp2)
        {
            sum = sum + temp2->data;
        }
        // creating node with dataue of sum of both lists.
        Node *newNode = new Node(sum % 10);
        // calculating carry
        carry = sum / 10;
        // attach newNode with the list
        curr->next = newNode;
        // update list
        curr = curr->next;
        // only go to next node if lists are not pointing to null
        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }
    // if carry is still left, make node with its dataue
    if (carry)
    {
        Node *newNode = new Node(carry);
        curr->next = newNode;
    }
    // head of resultant list is next pointer of dummyNode
    return dummyNode->next;
}
// brute force funciton to create odd even LL
// method:
// 1.traverse the list and insert all odd node data in an array
// 2. traverse the list and insert all even node data in the same array
// 3. insert from head node and assign node data from 0th index of the array.
Node *oddEvenListBruteForce(Node *head)
{
    // edge case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // to traverse the list.
    Node *temp = head;
    // to store all node's data
    vector<int> arr;
    // 1. traverse list and insert all odd node's data in the array.
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    // in case of odd length list,last node data is not added to the array.
    // check temp and insert the data in the array.
    if (temp)
    {
        arr.push_back(temp->data);
    }
    // for even nodes, start from head->next node.
    temp = head->next;
    // 2. traverse the list and insert all even node's data in the array.
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    // in case of even length node, last node data is not added to the array.
    // check temp and insert data in the array.
    if (temp)
    {
        arr.push_back(temp->data);
    }
    // updating temp to start traversing list from the start.
    temp = head;
    int i = 0;
    // traverse list and insert node data from 0th index of the array.
    while (temp)
    {
        // assign node data from array
        temp->data = arr[i];
        // update index of array
        i++;
        // go to next node in the list.
        temp = temp->next;
    }
    // returning the list.
    return head;
    // T:O(n/2) + O(n/2 ) + O(n) == O(2n)
    // S:O(n), for extra array space
}
// better function to create odd even linked list
Node *oddEvenListBetter(Node *head)
{
    // edge case
    if (head == NULL || head->next == NULL)
        return head;
    // take odd and even node
    Node *odd = head;
    Node *even = head->next;
    // storing even head node. we need to connect this with last odd node.
    Node *evenHead = head->next;
    // traverse list and change the links of nodes.
    while (even != NULL && even->next != NULL)
    {
        // change links of nodes.
        odd->next = odd->next->next;
        even->next = even->next->next;
        // move on to next odd and even node
        odd = odd->next;
        even = even->next;
    }
    // last odd node's next should be start from first even node
    // so add evenHead node as next of last odd node.
    odd->next = evenHead;
    return head;
    // O(n)
}

// function to sort list of 0,1,2s.
Node *sortListOfZeroesOnesTwosBruteForce(Node *head)
{
    // edge case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // to store total no. of 0,1,2 present in the list.
    int count0 = 0, count1 = 0, count2 = 0;
    Node *temp = head;
    // traverse the list and count total no. of 0,1,2s.
    while (temp != nullptr)
    {
        int num = temp->data;
        if (num == 0)
            count0++;
        else if (num == 1)
            count1++;
        else
            count2++;

        temp = temp->next;
    }
    temp = head;
    // now traverse and sort the list
    while (temp)
    {
        if (count0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}
// better function to sort list of 0,1,2s.
Node *sortListOfZeroesOnesBetter(Node *head)
{
    // edge case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // dummy head nodes
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    // nodes to keep track of 0s,1s,2s nodes
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    // temporary node to traverse the list
    Node *temp = head;
    // changing links between nodes in the given list
    // linking nodes of 0s,1s,2s seperately.
    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    // now zero is like: 0->0->..., one = 1->1->,,, and two = 2->2->.. and so on.
    // now needs to link up zero node with one and two node

    // connectiong zero's next with one node. if there is no 1 data node
    // in the list, then connecting with two's node
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    // head of the sorted list
    head = zeroHead->next;
    // deleting dummy heads
    // delete zeroHead;
    // delete oneHead;
    // delete twoHead;

    return head;
}
int main()
{
    // take user provided list
    cout << "Insert a linked list with only 0,1,2 as node value" << endl;
    Node *head = take_input();
    cout << "Input linked list: ";
    print(head);
    // head = sortListOfZeroesOnesTwosBruteForce(head);
    head = sortListOfZeroesOnesBetter(head);
    cout << "linked list after sorting: ";
    print(head);
    return 0;
}