/*You have a binary tree of 'N' unique nodes and a Start node from where the tree will start to burn. Given that the Start node will always exist in the tree, your task is to print the time (in minutes) that it will take to burn the whole tree.



It is given that it takes 1 minute for the fire to travel from the burning node to its adjacent node and burn down the adjacent node.



For Example :
For the given binary tree: [1, 2, 3, -1, -1, 4, 5, -1, -1, -1, -1]
Start Node: 3

    1
   / \
  2   3
     / \
    4   5

Output: 2

Explanation :
In the zeroth minute, Node 3 will start to burn.

After one minute, Nodes (1, 4, 5) that are adjacent to 3 will burn completely.

After two minutes, the only remaining Node 2 will be burnt and there will be no nodes remaining in the binary tree.

So, the whole tree will burn in 2 minutes.*/
#include <bits/stdc++.h>
// inluding binary tree header file
#include "01_BinaryTreeNode.h"

using namespace std;
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
// This function creates a mapping of each node to its parent node in the binary tree.
// It also returns the pointer to the node with the value equal to 'target'.
BinaryTreeNode<int> *createParentMapping(BinaryTreeNode<int> *root, map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &nodeToParent, int target)
{
    BinaryTreeNode<int> *res = NULL;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    // Root node has no parent, so it's mapped to NULL.
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        // If the current node's data matches the target value, store it in 'res'.
        if (front->data == target)
        {
            res = front;
        }

        // If the current node has a left child, map it to the current node and enqueue it.
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        // If the current node has a right child, map it to the current node and enqueue it.
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }

    // Return the pointer to the node with the target value.
    return res;
}

// This function calculates the minimum time required to burn the binary tree
// starting from the 'root' node, given the mapping of each node to its parent.
int burnTree(BinaryTreeNode<int> *root, map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &nodeToParent)
{
    // Create a map to keep track of visited nodes.
    map<BinaryTreeNode<int> *, bool> visited;
    queue<BinaryTreeNode<int> *> q;

    q.push(root);
    visited[root] = true;

    int ans = 0; // Initialize the answer to 0.

    while (!q.empty())
    {
        int size = q.size();
        bool flag = false; // Flag to track if any node was burnt in this iteration.

        for (int i = 0; i < size; i++)
        {
            // Process neighboring nodes.
            BinaryTreeNode<int> *front = q.front();
            q.pop();

            // If the left child exists and hasn't been visited, enqueue it and mark it as visited.
            if (front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }

            // If the right child exists and hasn't been visited, enqueue it and mark it as visited.
            if (front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }

            // If the parent of the current node exists and hasn't been visited,
            // enqueue it and mark it as visited.
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }

        // If any node was burnt in this iteration, increment the answer.
        if (flag)
        {
            ans++;
        }
    }

    // Return the minimum time required to burn the tree.
    return ans;
}

// This function calculates the minimum time required to burn the binary tree
// starting from the node with value 'start'.
int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    // Algorithm steps:
    // Step 1: Create node-to-parent mapping.
    // Step 2: Find the target node.
    // Step 3: Return minimum time.

    // Create a mapping of child nodes to their parent nodes.
    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> nodeToParent;
    // Get the pointer to the node with the target value and create the node-to-parent mapping.
    BinaryTreeNode<int> *targetNode = createParentMapping(root, nodeToParent, start);
    // Calculate the minimum time required to burn the tree starting from the target node.
    int ans = burnTree(targetNode, nodeToParent);

    return ans; // Return the minimum time.
}

int main()
{
    // 3 5 1 6 2 0 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBinaryTreeLevelWise(root);

    int start = 2;
    int time = timeToBurnTree(root, start);
    cout << "Time to burn tree =  " << time << endl;
    delete root;

    return 0;
}