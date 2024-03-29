#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    // constructor
    TreeNode(T data)
    {
        this->data = data;
    }
    // destrutor
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
void printTree(TreeNode<int> *root)
{
    // print root node data
    cout << root->data << ": ";
    // print children node data of the root node
    for (int i = 0; i < root->children.size(); i++)
    {
        if (i == root->children.size() - 1)
        {
            cout << root->children[i]->data;
        }
        else
        {
            cout << root->children[i]->data << ", ";
        }
    }
    // going to new line for moving on to next node
    cout << endl;
    // reucursive call on children nodes
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data : ";
    cin >> rootData;

    // creating root node
    TreeNode<int> *root = new TreeNode<int>(rootData);
    // total no. of children of root node
    int n;
    cout << "enter total no. of children of " << rootData << " : ";
    cin >> n;
    // recursive call to create children nodes
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;

    // creating root node
    TreeNode<int> *root = new TreeNode<int>(rootData);

    // take a queue to take and store nodes
    // levelwise
    queue<TreeNode<int> *> pendingNodes;

    // push root node to the queue
    pendingNodes.push(root);

    // take level wise tree input
    // for contructing tree from user
    while (pendingNodes.size() != 0)
    {
        // take the front node from the queue
        TreeNode<int> *front = pendingNodes.front();
        // pop out the front node from queue
        pendingNodes.pop();

        // take user input for front nodes children
        int numChild;
        cout << "Enter total no. of children of " << front->data << " : ";
        cin >> numChild;

        // loop to take front node's children node data
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << " th child data of " << front->data << " : ";
            cin >> childData;

            // create child node
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            // attach child node as front node's children node
            front->children.push_back(childNode);
            // push child node to the queue
            pendingNodes.push(childNode);
        }
        }
    return root;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    printTree(root);

    return 0;
}