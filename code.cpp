#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~Node()
    {
        next = nullptr;
    }
};

void printLL(Node *head)
{
    if (head == NULL)
    {
        cout << "Head is empty!!" << endl;
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << " NULL" << endl;
}

Node *takeInput()
{
    int data;
    Node *head = NULL;
    cout << "Enter Data: ";
    while (true)
    {
        cin >> data;
        if (data == -1)
        {
            break;
        }
        else
        {
            Node *newNode = new Node(data);
            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                Node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }
    return head;
}

Node *takeInputBetter()
{
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    cout << "Enter Data: ";
    while (true)
    {
        cin >> data;
        if (data == -1)
        {
            break;
        }
        else
        {
            Node *newNode = new Node(data);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    return head;
}

int length(Node *head)
{
    if (head == nullptr)
    {
        return 0;
    }
    int ans = 0;
    while (head)
    {
        ans++;
        head = head->next;
    }
    return ans;
}
Node *insertNodeRecursively(Node *head, int data, int i)
{
    // base case
    if (head == NULL)
    {
        return head;
    }
    // small calculation
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    // recursive call
    Node *smallList = insertNodeRecursively(head->next, data, i - 1);
    head->next = smallList;
    return head;
}

int lengthRecursively(Node *head)
{
    // base case
    if (head == nullptr)
    {
        return 0;
    }

    int smallLength = lengthRecursively(head->next);
    return smallLength + 1;
}

Node *deleteNode(Node *head, int i)
{
    // case 1: deleting head node
    if (i == 0)
    {
        // case 1.1: if LL has only one node
        // then we need to return nullptr after head is deleted
        if (head->next == nullptr)
        {
            return nullptr;
        }
        // case 1.2: delete head and return the rest of the LL
        Node *a = head;
        head = head->next;
        delete a;
        return head;
    }

    // case 2: deleting any other node except the head node
    int cnt = 0;
    Node *temp = head;

    while (temp != NULL && cnt < i - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp != NULL)
    {
        Node *a = temp->next;
        temp->next = a->next;
        delete a;
        return head;
    }
    return head;
}

Node *deleteNodeRecursively(Node *head, int i)
{
    // edge case
    if (head == NULL)
    {
        return head;
    }
    // base case
    if (i == 0)
    {
        Node *a = head;
        head = head->next;
        delete a;
        return head;
    }
    // smallCalculation
    if (i == 1)
    {
        Node *a = head->next;
        head->next = a->next;
        delete a;
        return head;
    }
    // recursive call
    Node *smallList = deleteNodeRecursively(head->next, i - 1);

    // small calculation: attach current head to the remaing list.
    head->next = smallList;

    return head;
}
int main()
{
    Node *head = takeInputBetter();

    printLL(head);
    // printLL(head);

    // cout << length(head) << endl;
    // head = insertNodeRecursively(head, 99, 5);
    // printLL(head);
    // cout << "length: " << lengthRecursively(head);

    head = deleteNode(head, 14);
    printLL(head);

    return 0;
}