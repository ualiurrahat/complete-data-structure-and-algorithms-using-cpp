// check BST function
// optimized code

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

// function to find minimum data node in a BST
// T: O(n)
int minimum(BinaryTreeNode<int> *root)
{
    // base case
    // if root is null , then min is +ve infinity
    if (root == nullptr)
    {
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

// function to find maximum data node in a BST
// T: O(n)
int maximum(BinaryTreeNode<int> *root)
{
    // base case
    // if root is null , then max is -ve infinity
    if (root == nullptr)
    {
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
// function to check BST
// T: O(n * height)
bool isBST(BinaryTreeNode<int> *root)
{
    // base case
    if (root == nullptr)
    {
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    // conditions to be BST
    // rootData > leftMax && <= rightMin, left part BST and right part BST
    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

// BST class
class isBSTReturn
{
public:
    int maximum;
    int minimum;
    bool isBST;
};

// function to check BST
// better code: T:O(n)
// will return an isBSTReturn obj having value of max,min and isBST
isBSTReturn isBST2(BinaryTreeNode<int> *root)
{
    // base case
    if (root == nullptr)
    {
        isBSTReturn output;
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        output.isBST = true;
        return output;
    }

    // recursion call on left side of the root
    isBSTReturn leftOutput = isBST2(root->left);
    isBSTReturn rightOutput = isBST2(root->right);

    // value for final object
    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && (leftOutput.isBST) && (rightOutput.isBST);

    isBSTReturn output;
    output.maximum = maximum;
    output.minimum = minimum;
    output.isBST = isBSTFinal;
    return output;
}

int main()
{ // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    // 10 8 12 6 9 11 13 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();

    // will print 1 if BST, otherwise 0.
    isBSTReturn checkBST = isBST2(root);
    cout << checkBST.isBST << endl;
    delete root;

    return 0;
}