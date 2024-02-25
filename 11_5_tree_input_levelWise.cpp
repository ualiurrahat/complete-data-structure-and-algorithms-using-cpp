// take user input as tree levelwise
// better than the previous function

#include <bits/stdc++.h>
#include "11_2_treeClass.cpp"

using namespace std;

// funciton to print tree
void printTree(TreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << ": ";
    //printing children of root node first  and then other nodes
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " , ";
    }
    cout << endl;

    // recursively calling all other nodes a
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
// takeInput function 1.
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;

    // creating root node of tree
    TreeNode<int> *root = new TreeNode<int>(rootData);

    // var for root's total children
    int n;
    cout << "Enter total num of children of " << rootData << endl;
    cin >> n;

    // taking all children input for each noders.
    // starting from rootNode.
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        // connecting child nodes with their parent node
        root->children.push_back(child);
    }

    // return root of the tree
    return root;
}

// function to take tree as user input
// takeInput() function 2
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
    // tree is complete. returning the node.
    return root;
}

int main()
{
    // userInput for tree
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> *root = takeInputLevelWise();
    // printing tree
    printTree(root);

    // delete tree
    delete root;

    return 0;
}