/*You are given a binary tree consisting of 'n' nodes.
Convert the given binary tree into a linked list where the linked list nodes follow the same order as the pre-order traversal of the given binary tree.

Use the right pointer of the binary tree as the “next” pointer for the linked list and set the left pointer to NULL.

Use these nodes only. Do not create extra nodes.
*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

// Helper function to flatten the binary tree into a linked list
// It takes the current node and a reference to the previous node
void flattenBinaryTreeHelper(TreeNode<int> *node, TreeNode<int> *&prev)
{
    // Base case: if the current node is null, return
    if (node == nullptr)
    {
        return;
    }

    // Recursively flatten the right subtree
    flattenBinaryTreeHelper(node->right, prev);
    // Recursively flatten the left subtree
    flattenBinaryTreeHelper(node->left, prev);

    // Set the right pointer of the current node to the previous node
    node->right = prev;
    // Set the left pointer of the current node to null
    node->left = nullptr;
    // Update the previous node to be the current node
    prev = node;
    // T:O(N), S:O(N)
}

// Solution One: Just use recursive traversal
void flattenBinaryTreeSolutionOne(TreeNode<int> *root)
{
    // Initialize the previous node as null
    TreeNode<int> *prev = nullptr;
    // Call the helper function with the root node and the previous node
    flattenBinaryTreeHelper(root, prev);
}
// Solution two : use a stack
void flattenBinaryTreeSolutionTwo(TreeNode<int> *root)
{
    if (!root)
        return;
    stack<TreeNode<int> *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode<int> *curr = s.top();
        s.pop();
        if (curr->right)
        {
            s.push(curr->right);
        }
        if (curr->left)
        {
            s.push(curr->left);
        }
        if (!s.empty())
        {
            curr->right = s.top();
        }
        curr->left = nullptr;
    }
    // T:O(N),S(N)
}
// solution 3: best solution using morris traversal
void flattenBinaryTreeOptimal(TreeNode<int> *root)
{
    TreeNode<int> *curr = root;
    // performing morris traversal
    while (curr != NULL)
    {
        // for each node, check if its left sub-tree exists
        if (curr->left)
        {
            // left subtree exists
            // now go thruogh all its right sub-tree untill NULL is found
            TreeNode<int> *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            // assign pred with current's right subtree
            pred->right = curr->right;
            // make current's right subtree as its left-subtree
            curr->right = curr->left;
            // current's left subtree has to be null
            curr->left = NULL;
        }
        // current node has no left subtree
        // move on to the next node
        curr = curr->right;
    }
    // T:O(N), S:O(1)
    // morris traversal optimized space complexity.
}
int main()
{

    return 0;
}