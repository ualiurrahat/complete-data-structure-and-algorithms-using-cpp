/*
You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to return the size of the largest subtree of the binary tree which is also a BST.
A binary search tree (BST) is a binary tree data structure which has the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.

*/

#include <bits/stdc++.h>
using namespace std;

// Tree node class
template <typename T>
class BinaryTreeNode
{
public:
    // to store data
    T data;
    // left and right child nodes
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    // constructor
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    // destructor to delete entire binary tree
    ~BinaryTreeNode()
    {
        // for only one node, left and right will be NULL.
        // so delete will be called upon NULL.
        // this works fine also.
        delete left;
        delete right;
    }
};

// brute force solution
class BSTobject
{
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

BSTobject solve(BinaryTreeNode<int> *root, int &ans)
{
    // base case
    if (root == nullptr)
    {
        BSTobject ob;
        ob.mini = INT_MAX;
        ob.maxi = INT_MIN;
        ob.isBST = true;
        ob.size = 0;
        return ob;
    }
    // left & right part recursive call
    BSTobject left = solve(root->left, ans);
    BSTobject right = solve(root->right, ans);

    // current node
    BSTobject curr;
    curr.mini = min(root->data, left.mini);
    curr.maxi = max(root->data, right.maxi);
    curr.size = left.size + right.size + 1;

    curr.isBST = (left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini);

    // update ans
    if (curr.isBST)
    {
        ans = max(ans, curr.size);
    }
    return curr;
}
// brute force solution to find largest BST size in a BT
int largestBSTBrute(BinaryTreeNode<int> *root)
{
    int maxSize = 0;
    BSTobject ob = solve(root, maxSize);
    return maxSize;
    // T:O(N^2)
    // S:O(1), not considering the stack space.
}

// here comes the optimal solution
class NodeValue
{
public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
NodeValue largestBSTHelper(BinaryTreeNode<int> *root)
{
    // an empty tree is a BST of size 0
    if (root == nullptr)
    {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }
    // get values from left and right subtrees of current tree
    auto left = largestBSTHelper(root->left);
    auto right = largestBSTHelper(root->right);
    // if current node is greater than left in max
    // and smaller than min in right, then it is a BST
    if (left.maxNode < root->data && root->data < right.minNode)
    {
        // it is a BST
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode),
                         left.maxSize + right.maxSize + 1);
    }
    // otherwise return [-inf,inf] so that parent can't be a valid BST
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
// optimal function to find largest BST
int largestBSTOptimal(BinaryTreeNode<int> *root)
{
    // Write your code here.
    return largestBSTHelper(root).maxSize;
    // T:O(N)
    // S:O(1), not considerting recursive stack space
}