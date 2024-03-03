#include <bits/stdc++.h>
// inluding binary tree class file
#include "12_0_binaryTreeClass.cpp"

using namespace std;

// function to print binary tree
void printBinaryTree(BinaryTreeNode<int> *root)
{
    // base case
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " : ";
    // printing root's left child
    if (root->left != nullptr) // if(root->left) also same
    {
        cout << "L" << root->left->data << " ";
    }
    // printing root's right child
    if (root->right != nullptr)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    // recursively calling left and right child of all other nodes
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

// function to print level wise
// better print function
void printBinaryTreeLevelWise(BinaryTreeNode<int> *root)
{
    // edge case. if user put nullptr as root.
    if (root == nullptr)
    {
        return;
    }

    // queue to store nodes.
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
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

// function to take user input for binary tree
// function will stop taking further input if -1 is given
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
    // creating root node with rootData as value
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

// take input function level wise
// better function
// returns nullptr if -1 is given as nodeData
BinaryTreeNode<int> *takeInputLevelWise()
{
    // for root node
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    // check for null node
    if (rootData == -1)
    {
        return nullptr;
    }
    // creating root node
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    // queue for tree nodes.
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        // left child input of front node
        int leftChildData;
        cout << "Enter left child data of " << front->data << endl;
        cin >> leftChildData;
        // check for null node i.e. -1 as value
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }

        // right child input of front node
        int rightChildData;
        cout << "Enter right child data of " << front->data << endl;
        cin >> rightChildData;
        // check for null node i.e. -1 as value
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            pendingNodes.push(rightChild);
            front->right = rightChild;
        }
    }

    // returning root
    return root;
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

int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();

    printBinaryTreeLevelWise(root);

    cout << "Total node: " << countNodes(root) << endl;

    // delete tree
    delete root;

    return 0;
}