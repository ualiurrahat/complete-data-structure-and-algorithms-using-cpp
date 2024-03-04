/*You have been given a Binary Tree of 'N'
nodes, where the nodes have integer values.
Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.

*/
/*
Given an array 'arr' that contains 7 integers representing the values of nodes in a binary tree. This represents level order. The first element of the array represents the value of the root node.
Your objective is to construct a binary tree using the remaining 6 elements of the array, creating nodes for each of these values and return root node.
For example:
arr = [11, 22, 3, 54, 15, 23, 21]
*/

#include <bits/stdc++.h>
// inluding binary tree header file
#include "01_binaryTreeNode.h"

using namespace std;

// function to print binary tree
void printBinaryTree(BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " : ";
    // printing root's left subtree
    if (root->left != nullptr) // if(root->left) also same
    {
        cout << "L" << root->left->data << " ";
    }
    // printing root's right subtree
    if (root->right != nullptr)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    // recursively calling for left and right sub tree
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}
// function to take user input for creating binary tree
// function will stop taking further input
// and will return a null pointer if -1 is given as input
BinaryTreeNode<int> *takeInput()
{
    // for root node
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;
    // condition for null node
    if (rootData == -1)
    {
        return nullptr;
    }
    // creating root node
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    // user input for left and right child of root node
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    // connecting root with child
    root->left = leftChild;
    root->right = rightChild;

    // returning root;
    return root;
}

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
// function to count total nodes in binary tree.
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
// function to print tree in pre-order
// pre-order: node left right
void preOrder(BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// function to print tree in post-order
// post-order:  left right node
void postOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
// function to print in In-order form
// inorder: left node right
void inOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    // first left child
    inOrder(root->left);
    // then node itself
    cout << root->data << " ";
    // then right child
    inOrder(root->right);
}

// function to create tree from a vector array
BinaryTreeNode<int> *createTree(vector<int> &arr)
{

    // edge case
    if (arr.size() == 0)
    {
        return nullptr;
    }
    // create root node
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[0]);
    // queue to store nodes
    queue<BinaryTreeNode<int> *> pendingNodes;
    // insert root node to the queue
    pendingNodes.push(root);
    int i = 1;
    int n = arr.size();
    while (pendingNodes.size() != 0 && i < n)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        // creat left child  node for front
        BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(arr[i]);
        // attach leftChild node as front's left child
        front->left = leftChild;
        // inseft leftChild to the queue
        pendingNodes.push(leftChild);
        // update value of i
        i++;

        // create right child for front node
        if (i < n)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(arr[i]);
            front->right = rightChild;
            pendingNodes.push(rightChild);
            i++;
        }
    }
    return root;
}
// function that stores the inorder traversal in a vector
// inorder: left,root,right
void inorderTraversal(vector<int> &v, BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(v, root->left);
    v.push_back(root->data);
    inorderTraversal(v, root->right);
}

// function that stores preorder traversal in a vector
// preorder: root,left,right
void preorderTraversal(vector<int> &v, BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    v.push_back(root->data);
    preorderTraversal(v, root->left);
    preorderTraversal(v, root->right);
}
// function that stores postorder traversal in a vector
// post order: left,right,root
void postorderTraversal(vector<int> &v, BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    postorderTraversal(v, root->left);
    postorderTraversal(v, root->right);
    v.push_back(root->data);
}
// function that stores inorder,preorder,post-order traversal
// in a 2d vector
void treeTraversals(BinaryTreeNode<int> *root, vector<vector<int>> &v)

{
    // edge case
    if (root == nullptr)
        return;
    // Initialize vectors if not initialized
    if (v.size() < 3)
        v.resize(3);
    // pre-order traversal
    v[1].push_back(root->data);
    // inorder traversal
    treeTraversals(root->left, v);

    v[0].push_back(root->data);
    // post-order traversal
    treeTraversals(root->right, v);

    v[2].push_back(root->data);

    return;
}
// function to return inorder,preorder,post-order traversal
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)

{
    vector<vector<int>> ans;
    // Initialize vectors if not initialized
    ans.resize(3);
    // edge case
    if (root == nullptr)
    {
        return ans;
    }
    treeTraversals(root, ans);
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBinaryTreeLevelWise(root);
    vector<vector<int>> ans = getTreeTraversal(root);

    cout << "Inorder: ";
    for (auto num : ans[0])
    {
        cout << num << " ";
    }
    cout << endl;
    cout << "PreOrder: ";
    for (auto num : ans[1])
    {
        cout << num << " ";
    }
    cout << endl;
    cout << "PostOrder: ";
    for (auto num : ans[2])
    {
        cout << num << " ";
    }
    cout << endl;

    // delete tree
    delete root;

    return 0;
}
