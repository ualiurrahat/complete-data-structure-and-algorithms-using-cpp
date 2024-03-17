// Binary Search Tree : BST
// inspired from Binary Search
// for every node n in BST
// left subtrees of n is less than n
// right subtrees of n is greater than n
#include <iostream>
using namespace std;
// including file for binary tree node
#include "13_0_binaryTreeNodeClass.cpp"

class BST

{
private:
    // data of BST is private
    BinaryTreeNode<int> *root;

public:
    // constructor
    BST()
    {
        root = nullptr;
        // assigning root to null is important
        // otherwise, when we create an object
        // the root would point to garbage.
    }
    // destructor
    ~BST()
    {
        delete root;
    }

private:
    // private heleper delete function
    // takes root node and a data as inputs
    // deletes the node containing value equal as data given in input.
    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
    {
        // case 1 : when node is null
        if (node == nullptr)
        {
            return nullptr;
        }
        // case 2 :
        // data is greater than current node value
        // means data is in right side
        if (data > node->data)
        {
            // calling recursion on right side
            node->right = deleteData(data, node->right);
            return node;
        }
        // case 3:
        // data is less than node value
        // means data is in left side
        else if (data < node->data)
        {
            // calling recursion on left side
            node->left = deleteData(data, node->left);
            return node;
        }
        // case 4:
        // when node itself has the data that is to be deleted.
        else
        {
            // case i: when both left and right side of node are null
            // just delete the node and return null
            if (node->left == nullptr && node->right == nullptr)
            {
                // deleting node
                delete node;
                // returning null as BST is empty now
                return nullptr;
            }

            // case ii: if node has only right side
            // right node will become new root aka node
            // old node has to be deleted
            else if (node->left == nullptr)
            {
                // storing right part in temp node
                BinaryTreeNode<int> *temp = node->right;
                // assigning null to right side
                node->right = nullptr;
                // deleting old node
                delete node;
                // now right node is the  root. returning temp.
                return temp;
            }

            // case iii: if node has only left side
            // left node will become new root aka node
            // old node has to be deleted
            else if (node->right == nullptr)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }
            // case iv: when node has both left and right child
            // minimum data of right side would be new node data
            // will delete old node
            // will delete minimum data node from the right side.
            else
            {
                // storing minimum data node from right side
                BinaryTreeNode<int> *minNode = node->right;
                // loop to find minimu data node from right side
                while (minNode->left != nullptr)
                {
                    minNode = minNode->left;
                }
                // minimum node data from right side
                int rightMinData = minNode->data;
                // assign min right data as the node data
                node->data = rightMinData;
                // deleting right min data from right side
                // as it becomes the node data now
                node->right = deleteData(rightMinData, node->right);
                return node;
            }
        }
        // T:O(height)
    }
    // insert helper private function
    // root can be changed after inserting the element
    // so this can not be of void type

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        // when root is null
        if (node == nullptr)
        {
            // creating node with data
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        // if data is less than root value
        if (data < node->data)
        {
            // node has to be inserted on the left sub-tree
            // after insertion, node child of node has to be updated
            node->left = insert(data, node->left);
        }
        // if data is greater than node value
        else
        {
            // data will be inserted in the right part
            // so right child needs to be updated
            node->right = insert(data, node->right);
        }

        // returning the node
        return node;
        // T:O(height)
    }

    // private helper hasData function.
    // T: O(height)
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        // base case
        if (node == nullptr)
        {
            return false;
        }
        // if root is the ans.
        if (node->data == data)
        {
            return true;
        }
        // if data is left child or root
        else if (data < node->data)
        {
            return hasData(data, node->left);
        }
        // if data is right child of root.
        else
        {
            return hasData(data, node->right);
        }
        // funcition will return false if data is not in the BST.
    }

    // print helper printTree function
    // helper print function to print BST
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

public:
    // function to insert an element in the BST
    void insert(int data)
    {
        // using insert helper function to insert a data in the BST
        this->root = insert(data, this->root);
        // can also write like this-> root = insert(data,root);
    }

    // function to delete a data from BST
    void deleteData(int data)
    {
        // deleting nodes with data as value with the help of helper function
        root = deleteData(data, root);
    }

    // function to check if a data is in the BST or not
    bool hasData(int data)
    {
        // we can't run this function on BST
        // as it does not take any node in its parameter
        // so can't go left or right child of root node
        // soln: using private helper function to achieve the same
        return hasData(data, root);
    }
    // public function to print a BST
    void printBST()
    {
        printTree(root);
    }
};