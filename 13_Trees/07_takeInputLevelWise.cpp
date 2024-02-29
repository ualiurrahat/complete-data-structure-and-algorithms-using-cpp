
#include <bits/stdc++.h>
#include "04_treeNode.h"

using namespace std;

// funciton to print tree
void printTree(TreeNode<int> *root)
{
    // edge case

    if (root == nullptr)
    {
        return;
    }
    // first print root data
    cout << root->data << ": ";
    // printing all children of the root node
    for (int i = 0; i < root->children.size(); i++)
    {
        if (i == root->children.size() - 1)
        {
            cout << root->children[i]->data;
        }
        else
        {
            cout << root->children[i]->data << " , ";
        }
    }
    cout << endl;
    // recursively calling each children of nodes
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
// function to take tree as user input
// brute force technique
// not handling the part when user gives nullptr as input
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;

    // creating root node
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n; // root's total children
    cout << "Enter total num of children of " << rootData << endl;
    cin >> n;

    // recursive call to take input for all children  nodes.
    // starting from rootNode's children.
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        // connecting child nodes with their parent node
        root->children.push_back(child);
    }

    // return root of the tree
    return root;
}
// function to take tree level wise as user input

TreeNode<int> *takeInputLevelWise()
{
    // root node's data
    int rootData;
    cout << "Enter root data :" << endl;
    cin >> rootData;

    // creating root node
    TreeNode<int> *root = new TreeNode<int>(rootData);
    // take a queue to take and store nodes
    // levelwise
    queue<TreeNode<int> *> pendingNodes;
    // pushing root node in the queue
    pendingNodes.push(root);
    // take level wise tree input
    // for contructing tree from user
    while (pendingNodes.size() != 0)
    {
        // take the front node from the queue
        TreeNode<int> *front = pendingNodes.front();
        // pop out the front from the pendingNodes
        pendingNodes.pop();
        // pop out the front node from queue
        int totalChild;
        cout << "Enter number of children of " << front->data << ":" << endl;
        cin >> totalChild;
        // loop to take user input data
        // to create front node's children nodes
        for (int i = 0; i < totalChild; i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << front->data << " : " << endl;
            cin >> childData;
            // create child node
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            // attach child node as front node's children node
            front->children.push_back(childNode);
            // push child node to the queue
            pendingNodes.push(childNode);
        }
    }
    // tree is complete. returning the node.
    return root;
}
int main()
{

    // userInput for tree
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> *root = takeInputLevelWise();
    // printing tree
    printTree(root);

    // delete tree
    delete root;

    return 0;
}