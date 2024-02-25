// count total number of nodes in a tree

#include <bits/stdc++.h>
#include "11_2_treeClass.cpp"

using namespace std;

// function to take tree as user input

TreeNode<int> *takeInputLevelWise()
{
    // var for root
    int rootData;
    cout << "Enter root data :" << endl;
    cin >> rootData;

    // creating root node
    TreeNode<int> *root = new TreeNode<int>(rootData);

    // creating queues to push each node
    queue<TreeNode<int> *> pendingNodes;
    // pushing root node in the queue
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        // front node of the queue
        TreeNode<int> *front = pendingNodes.front();
        // popping the front from the pendingNodes
        pendingNodes.pop();
        // asking user to input total nummber of child of root
        int totalChild;
        cout << "Enter number of children of " << front->data << ":" << endl;
        cin >> totalChild;
        // loop to create nodes for roots child
        for (int i = 0; i < totalChild; i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << front->data << " : " << endl;
            cin >> childData;
            // creating nodes for childData
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            // adding childNode as roots child
            front->children.push_back(childNode);
            // adding childNode in the queue.
            // to take childNode's child later.
            pendingNodes.push(childNode);
        }
    }
    return root;
}

// TreeNode<int> *takeInput()
// {
//     int rootData;
//     cout << "Enter data: " << endl;
//     cin >> rootData;

//     // creating root node of tree
//     TreeNode<int> *root = new TreeNode<int>(rootData);

//     // var for root's total children
//     int n;
//     cout << "Enter total num of children of " << rootData << endl;
//     cin >> n;

//     // taking all children input for each noders.
//     // starting from rootNode.
//     for (int i = 0; i < n; i++)
//     {
//         TreeNode<int> *child = takeInput();
//         // connecting child nodes with their parent node
//         root->children.push_back(child);
//     }

//     // return root of the tree
//     return root;
// }

// funciton to print tree
// void printTree(TreeNode<int> *root)
// {
//     // edge case
//     if (root == nullptr)
//     {
//         return;
//     }
//     cout << root->data << ": ";
//     //printing children of root node first  and then other nodes
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         cout << root->children[i]->data << " ,";
//     }
//     cout << endl;

//     // recursively calling all other nodes a
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         printTree(root->children[i]);
//     }
// }

void printTreeLevelWise(TreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }

    // creating queue to push TreeNodes.
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        // printing root node's value
        cout << front->data << " : ";
        // loop to print root node's children
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ", ";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

// function to count nodes of a tree
int countNodes(TreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return 0;
    }
    int ans = 1;

    // traversing all children of root node
    for (int i = 0; i < root->children.size(); i++)
    {
        // counting node of each trees of children tree
        // adding them to find total number of nodes
        ans = ans + countNodes(root->children[i]);
    }
    return ans;
}

// print at level k: height of a node
void printAtLevelK(TreeNode<int> *root, int k)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    // base case
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int countLeafNodes(TreeNode<int> *root)
{
    int ans = 0;
    if (root->children.size() == 0)
    {
        ans = 1;
        return ans;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        ans = ans + countLeafNodes(root->children[i]);
    }
    return ans;
}

// print tree in pre-order
// first root than all child of first child, then go to second child

void preOrder(TreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

int main()
{
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    // userInput for tree
    TreeNode<int> *root = takeInputLevelWise();

    // printing tree in pre-order
    preOrder(root);

    // delete tree
    delete root;

    return 0;
}