#include <bits/stdc++.h>
using namespace std;

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

// morris traversal inorder function
vector<int> morrisInorder(BinaryTreeNode<int> *root)
{
    vector<int> inorder;
    BinaryTreeNode<int> *curr = root;
    // moris traversal in inorder fashion
    while (curr)
    {
        // case 1: if left is null, then print root
        // and go to right
        if (curr->left == nullptr)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            // case 2: left is not null
            // find the right most guy of the
            // current's node's left subtree
            BinaryTreeNode<int> *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            // case 2.1: if previous's right is null
            // appoint curr as right
            if (prev->right == nullptr)
            {
                prev->right = curr;
                // go to the left of current node
                curr = curr->left;
            }
            else
            {
                // previous's right is curr.
                // but curr is visited already
                // so cross the connection
                prev->right = nullptr;
                // insert current on the vector
                inorder.push_back(curr->data);
                // go to the right node
                curr = curr->right;
            }
        }
    }
    return inorder;
    // T:O(N), S:O(1)
}
// morris traversal preorder function
vector<int> morrisPreorder(BinaryTreeNode<int> *root)
{
    vector<int> preorder;
    BinaryTreeNode<int> *curr = root;
    // moris traversal in inorder fashion
    while (curr)
    {
        // case 1: if left is null, then print root
        // and go to right
        if (curr->left == nullptr)
        {
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            // case 2: left is not null
            // find the right most guy of the
            // current's node's left subtree
            BinaryTreeNode<int> *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            // case 2.1: if previous's right is null
            // appoint curr as right
            if (prev->right == nullptr)
            {
                prev->right = curr;
                preorder.push_back(curr->data);
                // go to the left of current node
                curr = curr->left;
            }
            else
            {

                prev->right = nullptr;
                // insert current on the vector

                // go to the right node
                curr = curr->right;
            }
        }
    }
    return preorder;
    // T:O(N), S:O(1)
}
int main()
{

    return 0;
}