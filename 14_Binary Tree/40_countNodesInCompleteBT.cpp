/*You are given the root of a complete binary tree, you need to calculate the number of nodes in the given complete binary tree.

A complete binary tree is a tree in which all the levels are completely filled except the last level. Nodes in the last level are as left as possible.*/
#include <bits/stdc++.h>
// inluding binary tree header file
#include "01_BinaryTreeNode.h"

using namespace std;
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
// helper function solution to find total nodes in a complete binary tree
void countHelper(BinaryTreeNode<int> *root, int &cnt)
{
    if (root == nullptr)
    {
        return;
    }
    cnt++;
    countHelper(root->left, cnt);
    countHelper(root->right, cnt);
}
// brute force solution
int countNodesBrute(BinaryTreeNode<int> *root)
{
    int cnt = 0;
    countHelper(root, cnt);
    return cnt;
    // S:O(height == logN)
    // T:O(N)
}
// to find left height of CBT
int findHeightLeft(BinaryTreeNode<int> *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->left;
    }
    return height;
}
// to find right height of CBT
int findHeightRight(BinaryTreeNode<int> *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->right;
    }
    return height;
}
// better solution
int countNodesBetter(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == nullptr)
    {
        return 0;
    }
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if (lh == rh)
    {
        return (1 << lh) - 1;
    }
    return 1 + countNodesBetter(root->left) + countNodesBetter(root->right);
    // T:O(logn*logn)
    // S:O(height == logn)
}
int main()
{
    // 1 2 3 4 5 7 6 -1 -1 -1 -1 -1 -1 -1 -1

    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBinaryTreeLevelWise(root);

    int totalNodes = countNodesBrute(root);
    cout << totalNodes << endl;
    delete root;

    return 0;
}