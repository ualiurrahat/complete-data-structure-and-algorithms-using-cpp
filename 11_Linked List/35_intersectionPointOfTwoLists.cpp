/*You are given two Singly Linked Lists of integers, which may have an intersection point.
Your task is to return the first intersection node. If there is no intersection, return NULL.
Example:-
The Linked Lists, where a1, a2, c1, c2, c3 is the first linked list and b1, b2, b3, c1, c2, c3 is the second linked list, merging at node c1.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
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
    // complexity: T:O(n), n = size of LL
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
// function to remove kth node from end of LL
Node *removeKthNodeBrute(Node *head, int K)
{

    // first find the length of the linked list
    int len = 0;
    Node *temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    // edge case: deleting head node
    if (len == K)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }
    // Nth node from end = len-N th node from start
    int res = len - K;
    // reassigning temp as head
    temp = head;
    while (--res)
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    return head;
    // T:O(len) + O(len-K) == T:O(2*len) at max.
}
// better function to delete kth node from end of list.
Node *removeKthNodeBetter(Node *head, int K)
{
    Node *fast = head;
    for (int i = 1; i <= K; i++)
    {
        fast = fast->next;
    }
    // edge case:if fast is null,means head needs to be deleted.
    if (fast == NULL)
    {
        Node *newhead = head->next;
        delete head;
        return newhead;
    }
    Node *slow = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *deletenode = slow->next;
    slow->next = slow->next->next;
    delete deletenode;

    return head;
    // O(len)
}
// function to check if list is palindrom: brute force
bool isPalindromeBrute(Node *head)
{
    // write your code here
    // step 1: store all node data in a stack
    stack<int> st;
    Node *temp = head;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    // step2: compare top element from stack with node data
    /// starting from head
    // if all node data == stack top, list is palindrome
    // otherwise not
    while (temp)
    {
        if (st.top() != temp->data)
        {
            return false;
        }
        // move to the next node in the list
        temp = temp->next;
        // pop stack top element
        st.pop();
    }
    return true;
    // T:O(n) + O(n) = O(2n)
    // S:O(n), for stack
}

// function to reverse linked list
Node *reverse(Node *head)
{
    // edge case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *newHead = reverse(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
// optimal soltution to check if list is palindrome
bool isPalindromeBetter(Node *head)
{
    // edge cae
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }
    // step1: find the middle of the list
    Node *slow = head;
    Node *fast = head;
    // traverse the list to find middle node
    // for even length list, fast->next->next will be null
    // and odd length list, fast->next will be null
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is the middle node(first middle node for even length list)
    // step2: reverse the list starting from slow->next node

    // step 3: now compare given list starting from head to slow node
    // with the reversed (2nd part we reversed) part of the list
    // if all values are same,then list is palindrome
    // otherwise not.
    // before returning ans, make sure to re-reverse the reversed list
    Node *first = head;
    Node *newHead = reverse(slow->next);
    Node *second = newHead;
    // loop to compare node data
    while (second)
    {
        // in case list is not palindrome
        if (first->data != second->data)
        {
            // re-reversing the 2nd part of list
            // so to return the list as it was given
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    // if code comes to this, that means list is palindrom
    // re-reversing list first
    reverse(newHead);
    return true;
    // T:O(2n), S:O(1)
}
// brute force funtion to add 1 to a LL
Node *addOneBrute(Node *head)
{
    // step 1: reverse given list.
    head = reverse(head);
    Node *temp = head;
    // initial carry is 1. since we are adding 1 to the list.
    int carry = 1;
    // traverse the list and add 1.
    while (temp)
    {
        temp->data = temp->data + carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            carry = 1;
            temp->data = 0;
        }
        temp = temp->next;
    }
    // if carry is non-zero, create newNode with carry value
    // this node is the head of the resultant list.
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        head = reverse(head);
        newNode->next = head;
        return newNode;
    }
    // carry is zero,reverse the list again and return.
    head = reverse(head);
    return head;
    // T:O(n) + O(n) + O(n) == O(3n), S:O(1)
}
// recursive helper function to add 1 in linked list
int helper(Node *temp)
{
    // edge case
    if (temp == nullptr)
    {
        return 1;
    }
    // recursive call
    int carry = helper(temp->next);
    // calculate carry and data value
    temp->data = temp->data + carry;
    // if data < 10, carry is 0. so returning 0.
    if (temp->data < 10)
    {
        return 0;
    }
    // when data > 10, data is 0 and carry 1. returning 1
    temp->data = 0;
    return 1;
}
// better approach to add 1 in linked list
Node *addOneBetter(Node *head)
{
    // getting carry value using recursive helper function.
    int carry = helper(head);
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
    // T:O(n),S:(1)
}
// brute force solution to delete middle node
Node *deleteMiddleBrute(Node *head)
{
    // edge case
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    // step 1: find the length of the list
    int n = 0;
    Node *temp = head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }
    // step 2: traverse up to the n/2 node
    int res = n / 2;
    temp = head;
    while (temp)
    {
        res--;
        if (res == 0)
        {
            Node *midNode = temp->next;
            temp->next = temp->next->next;
            delete midNode;
            break;
        }
        temp = temp->next;
    }
    return head;
    // T:O(n) + O(n/2) = O(1.5n)
    // S:O(1)
}
// optimal solution to delete middle node
Node *deleteMiddleOptimal(Node *head)
{
    // edge case
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    // take slow and fast pointer
    Node *slow = head;
    Node *fast = head;
    // skip the first traversal of slow and fast moves
    fast = fast->next->next;
    // traversal of both nodes slow and fast
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow->next is the middle node
    Node *middle = slow->next;
    // update the links
    slow->next = slow->next->next;
    // delete middle node
    delete middle;
    return head;
    // T:O(n/2)
    // S:O(1)
}
// brute force solution to find intersection point of 2 lists
Node *findIntersectionBrute(Node *firstHead, Node *secondHead)
{
    // step 1: save all nodes of either list 1 or list 2 in a map
    map<Node *, int> mpp;
    Node *temp = firstHead;
    // saving nodes of list 1 in map
    while (temp)
    {
        mpp[temp] = 1;
        // we assign all nodes value as 1.as value is not necessary.
        temp = temp->next;
    }
    temp = secondHead;
    // traversing list 2.
    while (temp)
    { // step 2: traverse list 2 and find if current node is in the map or not.
        if (mpp.find(temp) != mpp.end())
        {
            // node is found in the map. this is the first intersection point.
            // return the list
            return temp;
        }
        // move to the next node in the list 2
        temp = temp->next;
    }
    // no intersection point between the lists
    // so returning NULL
    return nullptr;
    // T:O(n1*logn) + O(n2*logn)
    // S:O(n1) or O(n2),depending whicl list we stored on the map.
}
// better approach to find intersection point
// collisionPoint function finds the intersect node
Node *collisionPoint(Node *temp1, Node *temp2, int d)
{
    // step1: move the temp2 node to the node from where
    // both lists are in the same length.
    while (d)
    {
        d--;
        temp2 = temp2->next;
    }
    // step2: traverse both lists untill they become equal
    // they will be equal either in the first intersection node
    // or, at null point in case no intersection node is there.
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1; // or temp2
}
Node *findIntersectionBetter(Node *firstHead, Node *secondHead)
{
    // step1: find the length of lists so that we can
    // travesre lists from equal points.
    int n1 = length(firstHead);
    int n2 = length(secondHead);
    // n1~n2 is the difference of distance between lists.
    if (n1 < n2)
    {
        // second list is the greaterl length list
        return collisionPoint(firstHead, secondHead, n2 - n1);
    }
    else
    {
        // first list is the greater one.
        return collisionPoint(secondHead, firstHead, n1 - n2);
    }
    // O(n1)+O(n2)(for finding length)+O(n2-n1)(collision first loop)+O(n1)(collision 2nd loop)
    // T:O(n1) + O(2*n2)
    // S:O(1)
    return nullptr;
}
// optimal approach to find intersection point
Node *findIntersectionOptimal(Node *firstHead, Node *secondHead)
{
    // edge case
    if (firstHead == NULL || secondHead == NULL)
    {
        return nullptr;
    }
    // temporary nodes to traverse the lists
    Node *t1 = firstHead;
    Node *t2 = secondHead;

    while (t1 != t2)
    {
        // move to next node in both lists
        t1 = t1->next;
        t2 = t2->next;
        // condition for colliding: nodes will be equal on colliding node
        // or either both become null. both will be null in case of
        // no intersection node. then return any of the two node
        if (t1 == t2)
        {
            return t1;
        }
        // when any of the node becomes null,
        // assign them to opposite list's head.
        if (t1 == nullptr)
        {
            t1 = secondHead;
        }
        if (t2 == nullptr)
        {
            t2 = firstHead;
        }
    }
    return t1; // or t2
    // T:O(n1+n2)
    //  S:O(1)
}
int main()
{
    Node *head1 = takeInputBetter();
    printLinkedList(head1);

    Node *head2 = takeInputBetter();
    printLinkedList(head2);

    Node *intersection = findIntersectionOptimal(head1, head2);
    if (intersection == NULL)
    {
        cout << "no intersection point between the lists";
    }
    else
    {
        cout << "intersected node found with data " << intersection->data << endl;
    }

    return 0;
}