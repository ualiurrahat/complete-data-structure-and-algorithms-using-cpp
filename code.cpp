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
int main()
{
    TreeNode<int> *root = takeInput();

    printTree(root);

    return 0;
}