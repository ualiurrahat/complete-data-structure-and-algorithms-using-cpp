// print tree

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

int main()
{

    //     1
    // 2       3

    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);

    // connecting root with node1 and node2
    root->children.push_back(node1);
    root->children.push_back(node2);

    // printing tree
    printTree(root);

    // delete tree
    delete root;

    return 0;
}