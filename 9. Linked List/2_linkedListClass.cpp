// creating linked list class
// each element is called node
// node has 2 properties: data and address of the next node

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
    // destructor
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};