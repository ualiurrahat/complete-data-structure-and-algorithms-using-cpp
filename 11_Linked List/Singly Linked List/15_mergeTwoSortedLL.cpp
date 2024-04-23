#include <bits/stdc++.h>
#include "02_linkedListClass.cpp"

using namespace std;

// function to take user input linked list
// returns head of the list
// so return type would be Node*
// the function takes input untill -1 is given as input
// means function terminates with -1 input
// we cant ask size as linked list is dynamic
// so will take input as linked list node
// untill -1 is given.

Node *takeInputBetter()
{

    cout << "Enter your data (enter -1 to exit): ";
    int data;
    // initialising head and tail node with null
    Node *head = nullptr;
    Node *tail = nullptr;

    cin >> data;
    while (data != -1)
    {
        // creating new node with user provided data
        Node *newNode = new Node(data);
        // if head is null, then assign newNode as head
        if (head == nullptr)
        {
            head = newNode;
            // for only one node, tail and head are same
            tail = newNode;
        }
        else
        {
            // assign new node as next of tail node
            tail->next = newNode;
            // update tail node
            tail = tail->next; // or, tail = newNode;
        }
        cout << "enter data (enter -1 to exit): ";
        cin >> data;
    }
    return head;
}
// complexity: T:O(n), n = size of LL
// function to print linked list
void printLinkedList(Node *head)
{
    // using a temp pointer as head is better
    // if there is chance of head pointer gets changed
    // ex: Node* temp = head;
    // here, we are sending a copy of head pointer address
    // so, no change is happening in main() function's head node
    while (head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "null" << endl;
}
// T:O(n), n = size of LL

// function to insert a node at any position.
// takes the head node, index i and data of new node as parameters.

Node *insertNode(Node *head, int i, int data)
{
    // creating new node with data
    Node *newNode = new Node(data);

    // condition to add new Node at first.
    // since new node becomes the first node.
    // head needs to be updated as new node.
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        // returning updated head
        return head;
    }

    // var count for finding right index
    // and temp node pointer to find the previous node of ith index.
    int count = 0;
    Node *temp = head;

    // loop to get the right positon to place newNode
    // loop checks two condition: value of i is valid or not
    // temp is not null pointer.
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    // adding newNode in the list
    // to add new node in the correct place,
    // temp must be valid, i.e. not null
    if (temp != nullptr)
    {
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
        // or, if we don't want to create node a
        // newNode->next = temp->next;
        // temp->next = newNode;
    }
    // returning head of the linked list.
    return head;
}
// T:O(1), for inserting node at first,
// T:O(n), for any other postion insertion.
//..................

// function to insert node at any position recursively.
Node *insertNodeRecursively(Node *head, int i, int data)
{
    // edge case
    // for null head, nothing can be added.
    // just return the head.
    if (head == nullptr)
    {
        return head;
    }
    // 1. base case
    // when i = 0,
    // create new node with data as value,attach it with head
    // update the head and return
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    // 2. recursive call
    Node *smallHead = insertNodeRecursively(head->next, i - 1, data);
    // 3. small calculation
    head->next = smallHead;
    return head;
}
// function to delete a node from the list at any index
// takes the head node and index  i as paramter.
// returns head node
Node *deleteNode(Node *head, int i)
{
    // to store the deleted node
    Node *a;
    int count = 0;
    Node *temp = head;
    // case 1: deleting head node
    if (i == 0)
    {
        a = head;
        // updating head
        head = head->next;
        // deleting old head
        delete a;
        // returning updated head.
        return head;
    }

    // case 2: deleting any other node except head node
    // loop for finding the node that has to be deleted
    while (temp != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    // delete operation will be valid if
    // index i is valid, hence temp is not null.
    if (temp != nullptr)
    {
        a = temp->next;
        Node *b = a->next;
        temp->next = b;
        delete a;
    }
    // returning head after performing deletion
    return head;
}
// T:O(1), for deleting head node
// T:O(n), for deleting any other node.
//..............................

// function to delete a node from the list recursively.
Node *deleteNodeRecursively(Node *head, int i)
{
    // edge case: for null head
    // just return the head
    if (head == nullptr)
    {
        return head;
    }
    // 1. base case: if index i = 0;
    // means, we need to delete the head node
    if (i == 0)
    {
        // storing the head node.
        Node *temp = head;
        // updating head node
        head = head->next;
        // deleting previous head node
        delete temp;
        // returning the head.
        return head;
    }
    // 2. recursive call.
    Node *smallHead = deleteNodeRecursively(head->next, i - 1);
    // 3. small calculation
    head->next = smallHead;
    // returning head node after performing deletion.
    return head;
}
// find lenght of linked list
// length = total num of nodes
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
// T:O(N)
//............

// recursive function to find length
int lengthRecursively(Node *head)
{
    // edge case
    if (head == nullptr)
    {
        return 0;
    }
    // base case
    if (head->next == nullptr)
    {
        return 1;
    }
    // recursive call
    int smallLength = lengthRecursively(head->next);
    // small calculation
    return smallLength + 1;
}

// find mid node of the LL
// for even length,there will be two mid nodes.
// this function returns the first mid node.
// NOTE: using length to find out mid node is not good practice
// solution: use the slow and fast pointer method(next code function) to do so.
Node *midPoint(Node *head)
{
    // find length of LL
    int len = length(head);
    // mid node is the (len-1)/2 th node.
    len = (len - 1) / 2;
    int count = 0;
    // to store mid node
    Node *temp = head;
    while (count != len)
    {
        temp = temp->next;
        count++;
    }
    // return the mid node
    return temp;
}
// better function to find mid node
// using slow and fast pointers.
Node *midPointBetter(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;

    // conditions for odd and even lengh linked list
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // code for second mid node in case of even length LL
    // if(fast->next == nullptr)
    //       return slow->next;

    // slow is the mid node
    return slow;
}
// function to convert vector array into LL
Node *convertArrayIntoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        Node *tail = new Node(arr[i]);
        temp->next = tail;
        temp = temp->next;
    }
    return head;
}
// brute force solution to merge two sorted LL
Node *mergeTwoSortedLLBrute(Node *head1, Node *head2)
{
    // step 1: take an array and insert all nodes data from both lists.
    vector<int> arr;
    Node *temp1 = head1;
    // inserting node's data from list 1
    while (temp1 != NULL) // O(n1)
    {
        arr.push_back(temp1->data);
        temp1 = temp1->next;
    }
    // inserting node's data from list 2
    Node *temp2 = head2;
    while (temp2 != NULL) // O(n2)
    {
        arr.push_back(temp2->data);
        temp2 = temp2->next;
    }
    // step 2: sort the array.
    sort(arr.begin(), arr.end());               // o(NlogN), here N = n1+n2
                                                // step 3: now convert the array into a linked list.
                                                // this will be the sorted list
    Node *sortedHead = convertArrayIntoLL(arr); // O(N)
    return sortedHead;
    // T:O(n1) + O(n2) + O(NlogN) + O(N)
    // S:O(N)+O(N), for array and answer linked list = O(2N)
}
// optimal solution to merge two sorted linked list
// here, we will use dummy pointer and two pointers approach
// will not create any new node, but will change the links between the existing nodes.
// it returns the head of the sorted LL
Node *mergeTwoSortedLLOptimal(Node *head1, Node *head2)
{
    // creating a dummy node with data as -1.
    // this node's next will be head of sorted LL
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    // temporary node to traverse both lists
    Node *t1 = head1;
    Node *t2 = head2;

    // traversing each LL and sorting nodes
    while (t1 != NULL && t2 != NULL)
    {
        // when t1 node's data is lesser than t2's
        if (t1->data < t2->data)
        {
            // link t1 as temp's next
            temp->next = t1;
            // update temp
            temp = t1;
            // go to next node in list 1
            t1 = t1->next;
        }
        // now t2 node's data is smaller
        else
        {
            // link temp's next with t2
            temp->next = t2;
            // update temp
            temp = t2;
            // go to next node in list 2
            t2 = t2->next;
        }
    }
    // the loop will be terminated when either t1 or t2 becomes null.

    // case when t2 is exhausted and t1 is left
    if (t1 != NULL)
    {
        // attach temp with the remaining part of t1
        temp->next = t1;
    }
    // case when t1 is exhausted, and t2 is left
    else
    {
        // attch temp with remaining part of t2
        temp->next = t2;
    }
    // dummy's next is the head of sorted LL
    return dummyNode->next;
    // S:O(1), no extra space used
    // T:O(N=n1+n2)
}

int main()
{
    // first sorted LL
    cout << "Enter the first sorted LL:" << endl;
    Node *head1 = takeInputBetter();
    printLinkedList(head1);
    // second sorted LL
    cout << "Enter the second sorted LL:" << endl;
    Node *head2 = takeInputBetter();
    printLinkedList(head2);
    cout << "The merged sorted LL: ";
    // Node *head3 = mergeTwoSortedLLBrute(head1, head2);
    Node *mergedHead = mergeTwoSortedLLOptimal(head1, head2);
    printLinkedList(mergedHead);

    return 0;
}