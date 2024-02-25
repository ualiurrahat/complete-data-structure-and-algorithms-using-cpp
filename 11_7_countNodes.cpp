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
        // with the help of recursion
        ans = ans + countNodes(root->children[i]);
    }
    return ans;
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

    // delete tree
    delete root;

    return 0;
}