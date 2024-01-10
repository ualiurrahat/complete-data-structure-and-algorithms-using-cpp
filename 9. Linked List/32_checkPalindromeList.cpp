/*
You are given a Singly Linked List of integers. You have to return true if the linked list is palindrome, else return false.
A Linked List is a palindrome if it reads the same from left to right and from right to left.
Example:
The lists (1 -> 2 -> 1), (3 -> 4 -> 4-> 3), and (1) are palindromes, while the lists (1 -> 2 -> 3) and (3 -> 4) are not.
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
int main()
{
    Node *head = takeInputBetter(); // 1 2 3 4 5 6 -1
    printLinkedList(head);

    string result = isPalindromeBetter(head) ? "Palindrome" : "Not palindrome";
    cout << result << endl;

    return 0;
}
