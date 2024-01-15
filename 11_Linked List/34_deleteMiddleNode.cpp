/*Given a singly linked list of 'N' nodes. Your task is to delete the middle node of this list and return the head of the modified list.
However, if the list has an even number of nodes, we delete the second middle node
Example:
If given linked list is 1->2->3->4 then it should be modified to 1->2->4.*/
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
int main()
{
    Node *head = takeInputBetter(); // 1 2 3 4 5 6 -1
    printLinkedList(head);

       // head = deleteMiddleBrute(head);
    head = deleteMiddleOptimal(head);
    printLinkedList(head);

    return 0;
}