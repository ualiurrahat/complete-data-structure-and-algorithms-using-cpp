// you are given an array. convert its elements into a linked list
// ex: a[] = {18,1,8,5,20}
// output: list = 18->1->8->5->20
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

// brute force approach to sort a LL
Node *sortLLBrute(Node *head)
{
    // step1: store all node's data into a vector
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    // step2 : sort the vector
    sort(arr.begin(), arr.end());
    // step 3: assign node's data from vector sequentially
    // starting from vector's 0th index and start assigning from head node.
    temp = head;
    int i = 0;
    while (temp != NULL)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
    // S:O(n), for vector
    // T:O(n)+O(nlogn)+o(n)
}
// optimal approach to sort a LL
// using merge sort here.
Node *mergeSortLL(Node *head)
{
    // base case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // find the mid node of the LL
    // here, we need the first mid node in case of even lenght lists
    // the function midPointBetter here finds the first mid node
    Node *middleNode = midPointBetter(head);
    // dividing whole LL into two parts for merge sorting
    // first part: from head to mid
    // second part: from mid->next to last node.
    Node *leftHead = head;
    Node *rightHead = middleNode->next;

    // sepearting the first half of LL from 2nd half
    // this is important.Assigning null to the mid->next,
    // and dividing LL into two parts will be successul only after that
    middleNode->next = nullptr;

    // 2.recursively sort the both halves of LL
    leftHead = mergeSortLL(leftHead);
    rightHead = mergeSortLL(rightHead);
    // 3. merge both halves of LL
    Node *sortedHead = mergeTwoSortedLLOptimal(leftHead, rightHead);
    return sortedHead;
    // S:O(logn)for heights, O(n)for merging, and O(n/2) for middle node finding
    // S:O(logn *(n+n/2))
    // T:O(n), for recursive stack space.
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
    // T:O(N)
}

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
    // T:O(N)
}

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
    // T:O(N)
}
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
// function to convert array into LL
Node *convertArrayIntoLL(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *tail = new Node(arr[i]);
        temp->next = tail;
        temp = tail;
    }
    return head;
}
int main()
{
    // take size of user input array
    int n;
    cout << "array size: ";
    cin >> n;
    // creating array of size n
    int arr[n];
    // take array elements from user
    cout << "insert array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // converting array into LL
    Node *head = convertArrayIntoLL(arr, n);
    printLinkedList(head);

    return 0;
}