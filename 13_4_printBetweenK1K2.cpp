// print a BST within a limit. within numbers from k1 to k2.

#include <bits/stdc++.h>
#include "13_1_BSTclass.cpp"

using namespace std;

// function to search an element
// existing in the BST or not
BinaryTreeNode<int> *findNode(BinaryTreeNode<int> *root, int data)
{

    // if root is null
    if (root == nullptr)
    {
        return nullptr;
    }
    // if data is equal to root data
    if (data == root->data)
    {
        return root;
    }
    // if data is greater than root data
    else if (data > root->data)
    {
        return findNode(root->right, data);
    }
    else
    {
        // data is less than root data
        return findNode(root->left, data);
    }
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

// function to print
void printTree(BinaryTreeNode<int> *root)
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
    printTree(root->left);
    printTree(root->right);
}
// function to print beween a range.
void printBetweenK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->data >= k1 && root->data <= k2)
    {
        cout << root->data << endl;
    }
    if (root->data > k1)
    {
        printBetweenK1K2(root->left, k1, k2);
    }
    if (root->data <= k2)
    {
        printBetweenK1K2(root->right, k1, k2);
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    printBetweenK1K2(root, 20, 70);
    delete root;

    return 0;
}