/*You have been given a Binary Search Tree and a target value.
You need to find out whether there exists a pair of node values in the BST,
 such that their sum is equal to the target value.

A binary search tree (BST), also called an ordered or sorted binary tree,
 is a rooted binary tree whose internal nodes each store a value greater than
  all the values keys in the node's left subtree and less than those in its right subtree.

Follow Up:
Can you solve this in O(N) time, and O(H) space complexity?
*/

#include <bits/stdc++.h>
using namespace std;

// Tree node class
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
// function to find BST elements in inorder form
// inorder form gives sorted arrangement of the BST elements

void inorder(BinaryTreeNode<int> *root, vector<int> &in)
{
    // inorder: left->root->right

    // base case
    if (root == NULL)
    {
        return;
    }
    // recursive call on left sub-tree
    inorder(root->left, in);
    // push the root node to the in array
    in.push_back(root->data);
    // recursive call on right subtree
    inorder(root->right, in);
}

// brute force solution
bool twoSumInBSTBrute(BinaryTreeNode<int> *root, int target)
{
    // array to store BST elements in inorder form
    vector<int> inorderValue;
    inorder(root, inorderValue);

    // two pointer approach to find pair with target sum
    int i = 0, j = inorderValue.size() - 1;
    while (i < j)
    {
        int sum = inorderValue[i] + inorderValue[j];
        if (sum == target)
        {
            return true;
        }
        // if sum is less than target, increase i
        else if (sum < target)
        {
            i++;
        }
        // sum is greater than target, decrease j
        else
        {
            j--;
        }
    }
    // no such pair having sum equals to k
    return false;
    // T:O(N)+O(N)
    // S:O(N)
}

// optimal approach
// using the next and before iterator
// from BST iterator

// BST iterator class
class BSTIterator
{
private:
    stack<BinaryTreeNode<int> *> myStack;
    // reverse--> true == before
    // reverse--> false == next
    bool reverse = true;

public:
    BSTIterator(BinaryTreeNode<int> *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }
    // return whether we have a next smallest number
    bool hasNext()
    {
        return !myStack.empty();
    }
    // return the next smallest number
    int next()
    {
        BinaryTreeNode<int> *topNode = myStack.top();
        myStack.pop();
        if (!reverse)
        {
            pushAll(topNode->right);
        }
        else
        {
            pushAll(topNode->left);
        }
        return topNode->data;
    }

private:
    void pushAll(BinaryTreeNode<int> *node)
    {
        while (node)
        {
            myStack.push(node);
            if (reverse == true)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }
};
bool twoSumInBSTOptimal(BinaryTreeNode<int> *root, int target)
{
    // Write your code here
    if (root == nullptr)
    {
        return false;
    }
    // for next iterator
    BSTIterator l(root, false);
    // for before iterator
    BSTIterator r(root, true);
    int i = l.next();
    int j = r.next();
    while (i < j)
    {
        if (i + j == target)
        {
            return true;
        }
        else if (i + j < target)
        {
            i = l.next();
        }
        else
        {
            j = r.next();
        }
    }
    return false;
    // T:O(N)
    // S:O(H)*2
}