// height of the tree
// null -> 0
// 1 -> height 1
//    1
// 2     3
// height: 2

//      1
//    2   3
//   5      7
//             9
// height: 4
// so height = 1 + max value from the child nodes.
#include <bits/stdc++.h>

using namespace std;

// class for tree node
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    // constructor
    TreeNode(T data)
    {
        this->data = data;
    }
};

// function to print tree
// brute force technique
void printTree(TreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

// function to take user input for tree
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter total children of " << rootData << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

// take user input level wise
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root of the Tree: ";
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter total children of " << front->data << endl;
        int totalChild;
        cin >> totalChild;

        for (int i = 0; i < totalChild; i++)
        {
            cout << "Enter " << i << "th child of " << front->data << endl;
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

// print level wise
void printTreeLevelWise(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ", ";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

// count total nodes in Tree
int countNodes(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int count = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        count = count + countNodes(root->children[i]);
    }
    return count;
}

// sum of nodes
int sumOfNodes(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum = sum + sumOfNodes(root->children[i]);
    }
    return sum;
}

// max data node
int maxNode(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int maxi = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        maxi = max(maxi, maxNode(root->children[i]));
    }
    return maxi;
}
// height of tree
// if root is null, height is 0.
// will recursively call all nodes
// and return 1 + max height of the nodes
int height(TreeNode<int> *root)
{
    // null case
    if (root == nullptr)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = max(ans, height(root->children[i]));
    }
    return ans + 1;
}

int main()
{
    // 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0
    // creating a general tree
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);

    // root->children.push_back(node1);
    // root->children.push_back(node2);

    // // printing tree
    // printTree(root);

    // cout << endl;
    // // creating tree with user input.
    // TreeNode<int> *root2 = takeInput();
    // // printing the root
    // printTree(root2);

    TreeNode<int> *root3 = takeInputLevelWise();
    printTreeLevelWise(root3);
    cout << "Total nodes: " << countNodes(root3) << endl;
    cout << "sum of nodes: " << sumOfNodes(root3) << endl;
    cout << "Max Node: " << maxNode(root3) << endl;
    cout << "Height: " << height(root3) << endl;

    // delete tree
    delete root3;

    return 0;
}
