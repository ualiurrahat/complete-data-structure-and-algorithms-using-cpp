// depth of a tree is 0 at root node
// then it increases by 1 for each level.
// so basically, depth is one value less than tree's height
// ex:
/*   1    -- height:1, depth: 0
   2   3   - height:2, depth: 1
 4        5 - height: 3, depth: 2



*/

#include <bits/stdc++.h>
#include "04_treeNode.h"

using namespace std;

// funciton to print tree
void printTree(TreeNode<int> *root)
{
    // edge case

    if (root == nullptr)
    {
        return;
    }
    // first print root data
    cout << root->data << ": ";
    // printing all children of the root node
    for (int i = 0; i < root->children.size(); i++)
    {
        if (i == root->children.size() - 1)
        {
            cout << root->children[i]->data;
        }
        else
        {
            cout << root->children[i]->data << " , ";
        }
    }
    cout << endl;
    // recursively calling each children of nodes
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
// function to take tree as user input
// brute force technique
// not handling the part when user gives nullptr as input
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;

    // creating root node
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n; // root's total children
    cout << "Enter total num of children of " << rootData << endl;
    cin >> n;

    // recursive call to take input for all children  nodes.
    // starting from rootNode's children.
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        // connecting child nodes with their parent node
        root->children.push_back(child);
    }

    // return root of the tree
    return root;
}
// function to take tree level wise as user input

TreeNode<int> *takeInputLevelWise()
{
    // root node's data
    int rootData;
    cout << "Enter root data :" << endl;
    cin >> rootData;

    // creating root node
    TreeNode<int> *root = new TreeNode<int>(rootData);
    // take a queue to take and store nodes
    // levelwise
    queue<TreeNode<int> *> pendingNodes;
    // pushing root node in the queue
    pendingNodes.push(root);
    // take level wise tree input
    // for contructing tree from user
    while (pendingNodes.size() != 0)
    {
        // take the front node from the queue
        TreeNode<int> *front = pendingNodes.front();
        // pop out the front from the pendingNodes
        pendingNodes.pop();
        // pop out the front node from queue
        int totalChild;
        cout << "Enter number of children of " << front->data << ":" << endl;
        cin >> totalChild;
        // loop to take user input data
        // to create front node's children nodes
        for (int i = 0; i < totalChild; i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << front->data << " : " << endl;
            cin >> childData;
            // create child node
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            // attach child node as front node's children node
            front->children.push_back(childNode);
            // push child node to the queue
            pendingNodes.push(childNode);
        }
    }
    // tree is complete. returning the node.
    return root;
}
// print tree at level wise

void printTreeLevelWise(TreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }

    // take a queue to store the tree nodes.
    queue<TreeNode<int> *> pendingNodes;
    // push root node to the queue
    pendingNodes.push(root);

    // store remaining nodes in the queue
    // and print them levelwise.
    while (pendingNodes.size() != 0)
    {
        // front node from the queue
        TreeNode<int> *front = pendingNodes.front();
        // pop out the node from the queue
        pendingNodes.pop();

        // print front node.
        cout << front->data << " : ";
        // loop to print front node's children
        for (int i = 0; i < front->children.size(); i++)
        {
            // print current child node
            cout << front->children[i]->data << ", ";
            // push the current child node in the queue.
            pendingNodes.push(front->children[i]);
        }
        // printing of the current level is done.
        // go to new line to print next level.
        cout << endl;
    }
}
// function to count total no.of nodes of a tree
int countNodes(TreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return 0;
    }
    int ans = 1;

    // recursive calling and traversing all children of root node
    // current node returns its total no. of children.
    for (int i = 0; i < root->children.size(); i++)
    {
        // counting total children nodes of each nodes.
        // adding them to find total number of nodes
        // with the help of recursion
        ans = ans + countNodes(root->children[i]);
    }
    return ans;
}
// function to find sum of nodes
int sumOfNodes(TreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return 0;
    }
    int sum = root->data;

    // recursive call on children
    for (int i = 0; i < root->children.size(); i++)
    {

        sum = sum + sumOfNodes(root->children[i]);
    }
    return sum;
}
// function to find node with maximum data
int maxNode(TreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return 0;
    }
    int val = root->data;

    // recursive call on children
    for (int i = 0; i < root->children.size(); i++)
    {

        int currVal = maxNode(root->children[i]);
        val = max(val, currVal);
    }
    return val;
}
// height of tree
// if root is null, height is 0.
// will recursively call all nodes
// and return 1 + max height of the nodes
int heightOfTree(TreeNode<int> *root)
{
    // null case
    if (root == nullptr)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = max(ans, heightOfTree(root->children[i]));
    }
    return ans + 1;
}
// function to fine depth of a tree
int depthOfTree(TreeNode<int> *root)
{
    return heightOfTree(root) - 1;
}
int main()
{

    // 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0
    // userInput for tree
    TreeNode<int> *root = takeInputLevelWise();
    // printing tree
    printTreeLevelWise(root);

    // counting nodes
    int total_node = countNodes(root);
    cout << "Total node = " << total_node << endl;

    int sum = sumOfNodes(root);
    cout << "Sum of nodes is : " << sum << endl;

    int maxi = maxNode(root);
    cout << "The maximum value of node: " << maxi << endl;

    int height = heightOfTree(root);
    cout << "height : " << height << endl;

    int depth = depthOfTree(root);
    cout << "depth: " << depth << endl;

    // delete tree
    delete root;

    return 0;
}