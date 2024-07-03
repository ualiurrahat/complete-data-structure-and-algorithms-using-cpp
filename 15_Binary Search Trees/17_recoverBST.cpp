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

// to get inorder traversal of BST
void inorder(TreeNode *root, vector<int> &in)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
    // T:O(N)
}
// to iterate over BST and assign correct values
void solve(TreeNode *root, vector<int> &in, int &i)
{
    if (root == nullptr || i >= in.size())
    {
        return;
    }
    solve(root->left, in, i);
    if (in[i] != root->data)
    {
        swap(root->data, in[i]);
    }
    i++;
    solve(root->right, in, i);
    // T:O(N)
}
// brute force approach.
TreeNode *FixBST(TreeNode *root)
{
    // Write your code here.
    // step1: get the inorder traversal of the given corrupted BST
    vector<int> v;
    inorder(root, v);
    // step2: sort the elements stored in the vector
    sort(v.begin(), v.end());
    // step 3: iterate over the BST and fixed it
    int i = 0;
    solve(root, v, i);
    return root;
    // T:O(N)+O(NlogN)+O(N) = O(2N+NlogN)
    // S:O(N)
}

// optimal approach coded on leetcode
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
        if (prev != NULL && (root->val < prev->val))
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
            swap(first->val, last->val);
        }
        else if (first && middle)
        {
            swap(first->val, middle->val);
        }
    }
    // T:O(N)
    // S:O(1), not considering the recursive space.
};