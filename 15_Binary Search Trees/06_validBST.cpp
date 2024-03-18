// to check if a given BT is a BST or not

#include "01_binarySearchTreeNode.h"
BinaryTreeNode<int> *findNode(BinaryTreeNode<int> *root, int data)
{

    // if root is null
    if (root == nullptr)
    {
        return nullptr;
    }
    // if data is equal to root data
    if (data == root->data)
    {
        return root;
    }
    // if data is greater than root data
    else if (data > root->data)
    {
        return findNode(root->right, data);
    }
    else
    {
        // data is less than root data
        return findNode(root->left, data);
    }
    // T:O(logN), S:O(1)
}
// take input function level wise
// for Binary Tree Input
// returns nullptr if -1 is given as nodeData
BinaryTreeNode<int> *takeInputLevelWise()
{
    // for root node
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    // check for null node
    if (rootData == -1)
    {
        return nullptr;
    }
    // creating root node
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    // queue for tree nodes.
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        // left child input of front node
        int leftChildData;
        cout << "Enter left child data of " << front->data << endl;
        cin >> leftChildData;
        // check for null node i.e. -1 as value
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }

        // right child input of front node
        int rightChildData;
        cout << "Enter right child data of " << front->data << endl;
        cin >> rightChildData;
        // check for null node i.e. -1 as value
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            pendingNodes.push(rightChild);
            front->right = rightChild;
        }
    }

    // returning root
    return root;
}

// function to print
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
void printBetweenK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    // base case
    if (root == nullptr)
    {
        return;
    }
    // if root data lies between the range
    // print the data
    if (root->data >= k1 && root->data <= k2)
    {
        cout << root->data << " ";
    }
    // data is greater than given initial value
    // recursive call on left subtree
    if (root->data > k1)
    {
        printBetweenK1K2(root->left, k1, k2);
    }
    // recursive call on right subtree
    // when data is <= to the given final value
    if (root->data <= k2)
    {
        printBetweenK1K2(root->right, k1, k2);
    }
    // T:O(logN), S:O(1)
}
// function to find minimum data of a node

int minimum(BinaryTreeNode<int> *root)
{
    // base case
    // if root is null , then min is +ve infinity
    if (root == nullptr)
    {
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
    // T:O(n), S:O(1)
}

// function to find maximum data of a node
int maximum(BinaryTreeNode<int> *root)
{
    // base case
    // if root is null , then max is -ve infinity
    if (root == nullptr)
    {
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
    // T:O(N), S:O(1)
}
// brute force solution to check if a given BT is BST or not
bool isBSTBrute(BinaryTreeNode<int> *root)
{
    // base case
    if (root == nullptr)
    {
        return true;
    }

    // to be a BST, root value has to be
    // greater than max value left side
    // lesset or equal to minimum value on the rigth side

    // finding maximum value on left subtree
    int leftMax = maximum(root->left);
    // finding minimum value on right subtree
    int rightMin = minimum(root->right);

    // recursive call to check if left and right
    // subtree are also BST or not.

    bool isLeftBST = isBSTBrute(root->left);
    bool isRightBST = isBSTBrute(root->right);
    // conditions to be BST
    // rootData > leftMax && <= rightMin, left part is BST and right part is BST
    bool output = (root->data > leftMax) && (root->data <= rightMin) && isLeftBST && isRightBST;
    return output;
    // time complexity
    // for balanced BST:
    // T(n) = 2T(n/2) + kn
    // [T[n/2] is for isBST(root->right) and another T[n/2] for isBST(root->right)]
    // kn is to find rigthMin & leftMax
    // so, for balanced BST, T(n) = O(nlogn)
    // for, unbalnced BST, T(n) = T(n-1)
    // [cause, whole BST will be either left or right side and isBST(root->left) or isBST(root->right) would be null]
    // so, T(n) = O(n^2) in this case`
    // T: O(n * height)
}
// better solution to check if given
// BT is BST or not.
// better approach: we will create a class.
// that will have 3 attributes.
// min value,max value and bool value to check if it is BST.
// then, will write a function that would return
// object of that class.

// BST class
class isBSTReturn
{
public:
    int maximum;
    int minimum;
    bool isBST;
};

// better function to check BST
// will return an isBSTReturn obj having value of max,min and isBST
isBSTReturn isBSTBetter(BinaryTreeNode<int> *root)
{
    // base case
    if (root == nullptr)
    {
        isBSTReturn output;
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        output.isBST = true;
        return output;
    }

    // recursion call on left side of the root
    isBSTReturn leftOutput = isBSTBetter(root->left);
    isBSTReturn rightOutput = isBSTBetter(root->right);

    // value for final object
    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && (leftOutput.isBST) && (rightOutput.isBST);

    isBSTReturn output;
    output.maximum = maximum;
    output.minimum = minimum;
    output.isBST = isBSTFinal;
    return output;
    // T:O(n)
}
int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    // 10 8 12 6 9 11 13 -1 -1 -1 -1 -1 -1 -1 -1

    BinaryTreeNode<int> *root = takeInputLevelWise();
    // cout << isBSTBrute(root) << endl;
    // will print 1 if BST, otherwise 0.

    isBSTReturn checkBST = isBSTBetter(root);
    cout << checkBST.isBST << endl;
    delete root;

    return 0;
}