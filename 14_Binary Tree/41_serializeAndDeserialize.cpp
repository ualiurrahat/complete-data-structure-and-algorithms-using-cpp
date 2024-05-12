/*You have been given a binary tree of integers. You are supposed to serialize and deserialize (refer to notes) the given binary tree.

You can choose any algorithm to serialize/deserialize the given binary tree. You only have to ensure that the serialized string can be deserialized to the original binary tree.

Note :
Serialization is the process of translating a data structure or object state into a format that can be stored or transmitted (for example, across a computer network) and reconstructed later. The opposite operation, that is, extracting a data structure from stored information, is deserialization.*/

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

string serializeTree(BinaryTreeNode<int> *root)
{
    // Edge case: If the tree is empty, return an empty string
    if (root == nullptr)
    {
        return "";
    }

    string s = "";                  // Initialize an empty string to store serialized tree
    queue<BinaryTreeNode<int> *> q; // Create a queue for level order traversal
    q.push(root);                   // Push the root node to the queue

    // Level order traversal
    while (!q.empty())
    {
        BinaryTreeNode<int> *currNode = q.front(); // Get the front element of the queue
        q.pop();                                   // Remove the front element from the queue

        // Serialize the current node's value or mark as null if it's nullptr
        if (currNode == nullptr)
        {
            s.append("#,"); // Append '#' to indicate a null node
        }
        else
        {
            s.append(to_string(currNode->data) + ','); // Append the node's value followed by a comma
            q.push(currNode->left);                    // Push the left child of the current node to the queue
            q.push(currNode->right);                   // Push the right child of the current node to the queue
        }
    }
    return s; // Return the serialized tree string
    // T:O(N), S:O(N)
}

BinaryTreeNode<int> *deserializeTree(string &serialized)
{
    // Edge case: If the serialized string is empty, return nullptr
    if (serialized.size() == 0)
    {
        return nullptr;
    }

    string str;                                                     // Temporary string to hold serialized node values
    stringstream s(serialized);                                     // Create a stringstream to parse the serialized string
    getline(s, str, ',');                                           // Get the first token from the serialized string
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(stoi(str)); // Create the root node from the first token
    queue<BinaryTreeNode<int> *> q;                                 // Create a queue for level order traversal
    q.push(root);                                                   // Push the root node to the queue

    // Level order traversal to deserialize the tree
    while (!q.empty())
    {
        BinaryTreeNode<int> *node = q.front(); // Get the front element of the queue
        q.pop();                               // Remove the front element from the queue

        // Deserialize the left child of the current node
        getline(s, str, ','); // Get the next token from the serialized string
        if (str == "#")
        {
            node->left = nullptr; // Set left child as nullptr if the token is '#'
        }
        else
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(stoi(str)); // Create a new node with the token value
            node->left = leftNode;                                              // Set the left child of the current node
            q.push(leftNode);                                                   // Push the left child to the queue for further processing
        }

        // Deserialize the right child of the current node
        getline(s, str, ','); // Get the next token from the serialized string
        if (str == "#")
        {
            node->right = nullptr; // Set right child as nullptr if the token is '#'
        }
        else
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(stoi(str)); // Create a new node with the token value
            node->right = rightNode;                                             // Set the right child of the current node
            q.push(rightNode);                                                   // Push the right child to the queue for further processing
        }
    }
    return root; // Return the root node of the deserialized tree
                 // T:O(N), S:O(N)
}

int main()
{

    return 0;
}