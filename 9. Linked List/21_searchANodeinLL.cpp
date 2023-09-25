#include <bits/stdc++.h>
#include "2_linkedListClass.cpp"

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
// function to merge two sorted linked list
// takes two sorted LL as parameters.
// it returns the head of the sorted LL
Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    // to sotre head and tail of the sorted LL
    Node *finalHead = NULL;
    Node *finalTail = NULL;

    // traversing each LL and sorting nodes
    while (head1 != NULL && head2 != NULL)
    {
        // when head1 has lesser value than head2
        if (head1->data < head2->data)
        {
            // if finalHead is null.
            // means it is the first node of merged LL
            if (finalHead == NULL)
            {
                // assign node to head and tail of merged LL
                finalHead = head1;
                finalTail = head1;
                // move to next node in the LL1
                head1 = head1->next;
            }
            // now head is already there in the merged LL
            // so need to add this node as a tail.
            else
            {
                // add the node as next tail of the merged LL
                finalTail->next = head1;
                // update the tail
                finalTail = finalTail->next;
                // move to next node in the LL1
                head1 = head1->next;
            }
        }
        // head2 value is lesser than head1
        else
        {
            // if finalHead is null.
            // means it is the first node of merged LL
            if (finalHead == NULL)
            {
                // assign head and tail node of the merged LL
                finalHead = head2;
                finalTail = head2;
                // move to the next node of LL2
                head2 = head2->next;
            }
            // now head is already there in the merged LL
            // so need to add this node as a tail.
            else
            {
                // add the node as tail's next of the merged LL
                finalTail->next = head2;
                // update tail
                finalTail = finalTail->next;
                // move to the next node of the LL2
                head2 = head2->next;
            }
        }
    }

    // if LL1 gets exhaused, need to continue sorting with LL2
    while (head2 != NULL)
    {
        // add current node as tail's next of the merged LL
        finalTail->next = head2;
        // update tail
        finalTail = finalTail->next;
        // move to the next node of the LL2
        head2 = head2->next;
    }

    // if LL2 gets exhausted, need to continue sorting LL1
    while (head1 != NULL)
    {
        // add current node as tail's next of the merged LL
        finalTail->next = head1;
        // update tail
        finalTail = finalTail->next;
        // move to the next node of the LL1
        head1 = head1->next;
    }
    // returns the head of the merged LL
    return finalHead;
}
// T:(N1+N2), N1 = size of LL1, N2 = size of LL2
//......................

// sort a linked list using merge sort
Node *mergeSort(Node *head)
{
    // base case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // find the mid node of the LL
    Node *mid = midPointBetter(head);
    // dividing whole LL into two parts for merge sorting
    // first part: from head to mid
    // second part: from mid->next to last node.
    Node *a = head;
    Node *b = mid->next;

    mid->next = nullptr;
    // this is important.Assigning null to the mid->next,
    // we are disconnecting the LL from head to end.
    // and dividing LL into two parts will be successul only after that

    // 2.recursively sort
    a = mergeSort(a);
    b = mergeSort(b);

    // 3. merge a and b
    Node *c = mergeTwoSortedLL(a, b);
    return c;
}

// function to reverse a linked list : brute force approch
Node *reverseLLBrute(Node *head)
{
    // 1. base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // 2. recursive call
    Node *smallAns = reverseLLBrute(head->next);

    // 3. small Calculation : traverse the list
    // and go to the last node. to add the head node
    // as next of the last node.

    // pointer for LL traversal
    Node *temp = smallAns;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // add head as next of temp node
    temp->next = head;
    //  now head is the last node of ther reversed LL
    // head->next has to be null
    head->next = NULL;
    // return the reversed list
    return smallAns;
}
// T:O(N^2)

//..................
// class for reverseLL to get better  time complexity
// this will return an object
// having head and tail property
class Pair
{
public:
    Node *head;
    Node *tail;
};

// better function to get head and tail of a reverse LL
// but this function returns an object of pair class
// T:O(N)
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
    // creating ans is must.
    // smallAns is not returning reversed list properly.
    // so we created Pair ans to upgrade and correctly form the reversed LL
    // ex: at reverseLL2(3->4->null)
    // smallAns.head = 4
    // smallAns.tail = 4
    // but tail actual should be 3
    // so ans.tail = head .. here ans becomes ans.head =4, ans.tail = 3 which is correct
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    // returning the ans pair containing head and tail of LL
    return ans;
}

// function to get the reversed LL from reverseLL2() function
// previous function was returning a pair
// this function gets the reversed LL head and returns
// the head Node pointer
Node *reverseLLBetter(Node *head)
{
    return reverseLL2(head).head;
}
// T:O(N)
//...............

// best function to reverse a LL recursively
// the main conern is to find the tail and attach head as tail's next
// guess what?? - tail is head->next in the original LL
Node *reverseLLBest(Node *head)
{
    // 1. base case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // 2. recursive call
    Node *smallAns = reverseLLBest(head->next);

    // 3.small calculation
    // tail is the head->next in the original LL
    // ex: LL = 1->2->3->4-> null, reversed = 4->3->2->
    // now tail is 2 and head->next == 2
    Node *tail = head->next;
    // now head should be tail->next
    // ex: reversed = 4->3->2->(need to add 1)
    // so tail->next = head(head is 1 in the original LL)
    tail->next = head;
    // assign null to head's next
    head->next = nullptr;
    // returning small reversed LL
    return smallAns;
}
// T:O(N)
// .................

// reversing LL iteratively
Node *reverseLLIteratively(Node *head)
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
// T:O(N)
//.................

// function to search a particular node with key as value
// if it exists, function returns 1
// otherwise -1

int searchNodeIteratively(Node *head, int key)
{
    while (head != nullptr)
    {
        if (head->data == key)
        {

            return 1;
        }
        else
        {
            head = head->next;
        }
    }

    return -1;
}

// search a node in recursive way
int searchNodeRecursively(Node *head, int key)
{
    if (head == nullptr)
    {

        return -1;
    }
    if (head->data == key)
    {

        return 1;
    }
    return searchNodeRecursively(head->next, key);
}
int main()
{
    // take a user input LL
    Node *head = takeInputBetter();
    printLinkedList(head);

    // reversing the  linked list
    head = reverseLLIteratively(head);
    printLinkedList(head);

    // checking if 1,5,8 exists in the list or not
    cout << searchNodeIteratively(head, 5) << endl;
    cout << searchNodeIteratively(head, 8) << endl;
    cout << searchNodeRecursively(head, 1) << endl;

    return 0;
}
