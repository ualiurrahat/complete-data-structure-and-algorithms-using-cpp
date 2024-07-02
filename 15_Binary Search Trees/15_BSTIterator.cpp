/*
You are given a class named as BSTIterator that represents an iterator over inorder traversal of a binary search tree. You need to implement the following things as follows:

1. BSTIterator(Node root) - It is a parameterized constructor in which you are given the root of the Binary search tree. It will be called whenever an object of BSTIterator is created.

2. next() - This member function will return the next smallest element in the in-order traversal of the binary search tree. You need to implement this function.

3. hasNext() - This function will return true if there exists the next smallest element in the traversal else it will return false. You need to implement this function
The binary search tree has ‘N’ nodes you need to print the inorder traversal of the tree using the iterator.
*/
#include <iostream>
#include <stack>
using namespace std;

// TreeNode class
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class BSTiterator
{
private:
    // take a stack to store all the nodes
    stack<TreeNode<int> *> myStack;

public:
    BSTiterator(TreeNode<int> *root)
    {
        // insert all the left side nodes
        // in stack by using pushAll functions
        pushAll(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int> *topNode = myStack.top();
        // pop the element
        myStack.pop();
        // now insert all the right side nodes
        // of topNode in the stack
        pushAll(topNode->right);
        return topNode->data;
    }

    bool hasNext()
    {
        // write your code here
        return !myStack.empty();
    }

private:
    // function to insert all the left side nodes
    // inside the stack whenever the constructor
    // function is called i.e. an object is initialized
    void pushAll(TreeNode<int> *node)
    {
        while (node)
        {
            myStack.push(node);
            node = node->left;
        }
    }
};