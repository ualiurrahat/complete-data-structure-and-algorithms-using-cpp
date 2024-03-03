#include <bits/stdc++.h>
// inluding binary tree header file
#include "01_binaryTreeNode.h"

using namespace std;

// function to print binary tree
void printBinaryTree(BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " : ";
    // printing root's left subtree
    if (root->left != nullptr) // if(root->left) also same
    {
        cout << "L" << root->left->data << " ";
    }
    // printing root's right subtree
    if (root->right != nullptr)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    // recursively calling for left and right sub tree
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}
// function to take user input for creating binary tree
// function will stop taking further input
// and will return a null pointer if -1 is given as input
BinaryTreeNode<int> *takeInput()
{
    // for root node
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;
    // condition for null node
    if (rootData == -1)
    {
        return nullptr;
    }
    // creating root node
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    // user input for left and right child of root node
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    // connecting root with child
    root->left = leftChild;
    root->right = rightChild;

    // returning root;
    return root;
}

// function to take user input as level wise
// for creating tree
// returns nullptr if -1 is given as nodeData
BinaryTreeNode<int> *takeInputLevelWise()
{
    // for root node
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    // if value is -1, return null pointer
    if (rootData == -1)
    {
        return nullptr;
    }
    // creating root node
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    // queue to store tree nodes.
    queue<BinaryTreeNode<int> *> pendingNodes;
    // push root node to the queue
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        // take out front node of the queue
        BinaryTreeNode<int> *front = pendingNodes.front();
        // pop the front node from queue
        pendingNodes.pop();

        // left child input of front node
        int leftChildData;
        cout << "Enter left child data of " << front->data << endl;
        cin >> leftChildData;
        // create left child node for all values except -1
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            // insert the node in the queue
            pendingNodes.push(leftChild);
            // attach the node as left child of front node.
            front->left = leftChild;
        }

        // right child input for front node
        int rightChildData;
        cout << "Enter right child data of " << front->data << endl;
        cin >> rightChildData;
        // create the node for all value except -1
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            // insert the node inside queue
            pendingNodes.push(rightChild);
            // attach the node as right child of front node.
            front->right = rightChild;
        }
    }

    // returning root
    return root;
}
// function to print binary tree level wise
void printBinaryTreeLevelWise(BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }

    // queue to store nodes.
    queue<BinaryTreeNode<int> *> pendingNodes;
    // insert root node to the queue.
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        // take out front node
        BinaryTreeNode<int> *front = pendingNodes.front();
        // pop the front node from queue.
        pendingNodes.pop();
        // print front node data
        cout << front->data << ": ";

        // printing left child
        if (front->left != nullptr)
        {
            cout << " L" << front->left->data << " ";
            // adding the node to the queue
            pendingNodes.push(front->left);
        }
        // printing right child
        if (front->right != nullptr)
        {
            cout << " R" << front->right->data;
            // adding the node to the queue
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
    return;
}
// function to count total nodes in binary tree.
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
// function to print tree in pre-order
// pre-order: node left right
void preOrder(BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();

    printBinaryTreeLevelWise(root);

    // cout << "total no. of nodes: " << countNodes(root) << endl;
    cout << "Pre Order traversal: ";
    preOrder(root);
    // delete tree
    delete root;

    return 0;
}