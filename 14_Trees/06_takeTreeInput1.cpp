// here, we will code the function for user given tree as input.
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
int main()
{

    // userInput for tree
    TreeNode<int> *root = takeInput();
    // printing tree
    printTree(root);

    // delete tree
    delete root;

    return 0;
}