/*
You have been given a Binary Search Tree of 'N' nodes,
where exactly two nodes of the same tree were swapped by mistake.
Your task is to restore or fix the BST,
without changing its structure and return the root of the corrected BST.
Note:
Given BST will not contain duplicates.
*/
#include <bits/stdc++.h>
using namespace std;

// tree node class
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// optimal approach coded on leetcode
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
class Solution
{
private:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *last;
    TreeNode *middle;

public:
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        if (prev != NULL && (root->data < prev->data))
        {
            // in case of first violation
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            // in case of second violation
            else
                // mark this node as last
                last = root;
        }
        // mark the current node as prev node
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        first = NULL;
        last = NULL;
        middle = NULL;
        prev = NULL;
        inorder(root);
        if (first && last)
        {
            swap(first->data, last->data);
        }
        else if (first && middle)
        {
            swap(first->data, middle->data);
        }
    }
    // T:O(N)
    // S:O(1), not considering the recursive space.
};