#include <bits/stdc++.h>
// inluding binary tree header file
#include "01_binaryTreeNode.h"

using namespace std;

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;

    // printing root,left,right nodes data
    cout << "root: " << root->data << endl;
    cout << "left child: " << root->left->data << endl;
    cout << "right child: " << root->right->data << endl;

    // delete tree
    delete root;

    return 0;
}