// user input function for tree
// brute force technique

#include <bits/stdc++.h>
#include "11_2_treeClass.cpp"

using namespace std;

// funciton to print tree
void printTree(TreeNode<int> *root)
{
    // edge case
    // this is not base case.
    // base case is implicitly done by the for loop here.
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << ": ";
    //printing all children of the root node
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ,";
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

    // var for root's total children
    int n;
    cout << "Enter total num of children of " << rootData << endl;
    cin >> n;

    // taking all children input for each node.
    // starting from rootNode.
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