/*You have been given a sorted array of length ‘N’. You need to construct a balanced binary search tree from the array. If there can be more than one possible tree, then you can return any.

Note:
1. A balanced binary tree is a binary tree structure in which the left and right subtrees of every node differ in height by no more than 1.

2. A binary search tree is a binary tree data structure, with the following properties
    a. The left subtree of any node contains nodes with value less than the node’s value.
    b. The right subtree of any node contains nodes with values equal to or greater than the node’s value.
    c. Right, and left subtrees are also binary search trees.
 */
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
// optimal function to check if a given BT
// is a BST or not

// top to bottom apporach
bool isBSTOptimal(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    // base case
    if (root == nullptr)
    {
        return true;
    }
    // check validity condtion to be BST
    // in the root data
    if (root->data < min || root->data > max)
    {
        return false;
    }
    // recursion call on left and right side of root node
    // to check if they are BST respectively
    bool leftOutput = isBSTOptimal(root->left, min, root->data - 1);
    bool rightOutput = isBSTOptimal(root->right, root->data, max);

    // tree will be BST if both left and right part are BST too.
    return leftOutput && rightOutput;
    // T:O(height)
}
// function to create a BST from a sorted array
// it takes the sorted array,starting and ending index as inputs.
// Function to create a Binary Search Tree (BST) from a sorted array
// Returns:
//   - BinaryTreeNode<int>*: Pointer to the root of the constructed BST
BinaryTreeNode<int> *BSTFromSortedArray(int a[], int start_index, int end_index)
{
    // Base case: If the start index is greater than the end index,
    // it means there are no elements in the current subarray, so return nullptr
    if (start_index > end_index)
    {
        return nullptr;
    }

    // Base case: If the start index is equal to the end index,
    // it means there is only one element in the current subarray,
    // so create a node for that element and return its pointer
    if (start_index == end_index)
    {
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(a[start_index]);
        return root;
    }

    // Since the array is sorted, the middle element of the current subarray (a[mid]) will be the root.
    int mid = (start_index + end_index) / 2;

    // Creating a node for the root with the value of the middle element
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(a[mid]);

    // Recursively construct the left subtree from the elements before the middle element
    root->left = BSTFromSortedArray(a, start_index, mid - 1);

    // Recursively construct the right subtree from the elements after the middle element
    root->right = BSTFromSortedArray(a, mid + 1, end_index);

    // Return the pointer to the root of the constructed BST
    return root;
    // T:O(N),
    // S:O(N)
}

int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    // 10 8 12 6 9 11 13 -1 -1 -1 -1 -1 -1 -1 -1

    int a[] = {1, 2, 3, 4, 5, 6, 7};
    BinaryTreeNode<int> *root = BSTFromSortedArray(a, 0, 6);
    printTree(root);
    delete root;

    return 0;
}