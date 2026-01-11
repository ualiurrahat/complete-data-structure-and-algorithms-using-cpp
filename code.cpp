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
int main()
{
    Node *head = takeInputBetter();

    printLL(head);
    // printLL(head);

    // cout << length(head) << endl;
    head = insertNodeRecursively(head, 99, 5);
    printLL(head);

    return 0;
}