/* in this questions, you need to find the kth largest and smallest element
in a given BST.*/

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

// class for linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
// function to create a sorted linked list from a given binary search tree (BST)
// function will return the head of the linked list
// This is a recursive approach

Node *BSTtoSortedLLBrute(BinaryTreeNode<int> *root)
{
    // base case: if the root is null, return null
    if (root == nullptr)
    {
        return nullptr;
    }

    // head of linked list will be the root of the BST
    Node *head = new Node(root->data);

    // recursively create linked list nodes from the left subtree of the BST
    Node *leftPart = BSTtoSortedLLBrute(root->left);

    // recursively create linked list nodes from the right subtree of the BST
    Node *rightPart = BSTtoSortedLLBrute(root->right);

    // next node of head would be the right part from the BST
    head->next = rightPart;

    // now we need to add the left part from the BST before the head node
    if (leftPart != nullptr)
    {
        // traverse to the last node of the left part
        Node *temp = leftPart;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        // temp is the last node before the head node
        // connect it with the head node
        temp->next = head;
        // now head will be the first node, i.e., the left part
        head = leftPart;
    }

    return head;
    // T:O(n)+O(n)[for while loop in case of skew tree] = O(2n)
    // S:O(n)
}
// function to create a sorted linked list from a given binary search tree (BST)
// function will return the head and tail of the linked list
// This is a recursive approach

pair<Node *, Node *> BSTtoSortedLLPair(BinaryTreeNode<int> *root)
{
    // base case: if the root is null, return null for both head and tail
    if (root == nullptr)
    {
        return {nullptr, nullptr};
    }

    // recursively create linked list nodes from the left subtree of the BST
    pair<Node *, Node *> leftPart = BSTtoSortedLLPair(root->left);

    // create a new node for the current root data
    Node *head = new Node(root->data);

    // if left part exists, connect the tail of left part with the head
    if (leftPart.first != nullptr)
    {
        leftPart.second->next = head;
    }

    // recursively create linked list nodes from the right subtree of the BST
    pair<Node *, Node *> rightPart = BSTtoSortedLLPair(root->right);

    // if right part exists, connect the head with the right part's head
    if (rightPart.first != nullptr)
    {
        head->next = rightPart.first;
    }

    // return head of the list and tail of the list
    // if left part exists, return its head, otherwise return head of the current node
    Node *listHead = (leftPart.first != nullptr) ? leftPart.first : head;
    // if right part exists, return its tail, otherwise return tail of the current node
    Node *listTail = (rightPart.second != nullptr) ? rightPart.second : head;

    return {listHead, listTail};
    // T:O(n),
    // S:O(n)
}

// better function to create a sorted linked list from a given binary search tree (BST)
// function will return the head of the linked list
Node *BSTtoSortedLLBetter(BinaryTreeNode<int> *root)
{
    // call the utility function to get the head and tail of the list
    pair<Node *, Node *> result = BSTtoSortedLLPair(root);
    // return the head of the list
    return result.first;
}

// function to find ceil in a BST
int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Initialize ceil to -1 since it's the default value if x is greater than all elements in the BST.
    int ceil = -1;
    // Traverse the BST until node is null.
    while (node)
    {
        // If x is found, return x.
        if (node->data == x)
        {
            return x;
        }
        // If x is greater than the current node's data, move to the right subtree.
        if (x > node->data)
        {
            node = node->right;
        }
        // If x is smaller than the current node's data, update ceil and move to the left subtree.
        else
        {
            ceil = node->data; // Update ceil to the current node's data since it could potentially be the ceil.
            node = node->left;
        }
    }
    // Return the ceil value.
    return ceil;
    // T:O(logn), S:O(1)
}
// Function to find the floor value in a Binary Search Tree (BST).
int findFloor(BinaryTreeNode<int> *node, int x)
{
    // Initialize floor to -1 since it's the default value if x is smaller than all elements in the BST.
    int floor = -1;

    // Traverse the BST until node is null.
    while (node)
    {
        // If x is found, return x as the floor.
        if (node->data == x)
        {
            return x;
        }

        // If x is smaller than the current node's data, move to the left subtree.
        if (x < node->data)
        {
            node = node->left;
        }
        // If x is greater than the current node's data, update floor and move to the right subtree.
        else
        {
            floor = node->data; // Update floor to the current node's data since it could potentially be the floor.
            node = node->right;
        }
    }

    // Return the floor value.
    return floor;
    // T:O(logN), S:O(1)
}
// funiction to find inorder traversal of a BST
void inorder(BinaryTreeNode<int> *root, vector<int> &in)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    // recursive call to the left subtree
    inorder(root->left, in);
    // push the current element to the vector
    in.push_back(root->data);
    // recursive call to the right subtree
    inorder(root->right, in);
    return;
    // T:O(N),S:(1)
}
// brute force solution to find kth largest smallest elements.
// step 1: find inorder traversal of the BST
// an inorder traversal always provides BST elements in a sorted order
// then inorder's kth element == kth smallest
// inorder's n-kth element = kth largest(assuming total elements  == n)
pair<int, int> findKthBrute(BinaryTreeNode<int> *root, int k)
{
    // vector to store elements of the BST
    vector<int> arr;
    // perform inorder traversal
    // to populate the vector
    inorder(root, arr);
    // calculate kth
    // largest and smallest element
    int kthSmallest = arr[k - 1];
    int kthLargest = arr[arr.size() - k];
    // returning a pair containing
    // kth largest and smallest elements
    return make_pair(kthSmallest, kthLargest);
    // T:O(N), S:(N)[for vector]
}
// optimal solution to fine kth smallest element
/*Step 1: Perform inorder traversal from the root node. At every visited node,
increment a counter variable to keep track of visited nodes.
 Inorder Traversal: left subtree,current node, then right subtree.
Step 2: When the counter reaches K, store the value of the current node as the Kth smallest.
Step 3: Return this value as the Kth smallest.*/
// Helper function to perform inorder
// traversal to find Kth smallest element
void inorder(BinaryTreeNode<int> *node, int &counter, int k, int &kSmallest)
{
    if (!node || counter >= k)
        return;

    // Traverse left subtree
    inorder(node->left, counter, k, kSmallest);

    // Increment counter after visiting left subtree
    counter++;

    // Check if current node is the Kth smallest
    if (counter == k)
    {
        kSmallest = node->data;
        return;
    }

    // Traverse right subtree if
    // Kth smallest is not found yet
    inorder(node->right, counter, k, kSmallest);
}
// optimal solution to find kth largest element
/*Step 1: Perform reverse inorder traversal from the root node.
 At every visited node, increment a counter variable to keep track of visited nodes.
Traversal:right subtree,current node, then left subtree.
Step 2: When the counter reaches K, store the value of the current node as the Kth smallest.*/
// Helper function to perform reverse inorder
// traversal to find Kth largest element
void reverseInorder(BinaryTreeNode<int> *node, int &counter, int k, int &kLargest)
{
    if (!node || counter >= k)
        return;

    // Traverse right subtree
    reverseInorder(node->right, counter, k, kLargest);

    // Increment counter after
    // visiting right subtree
    counter++;

    // Check if current node
    // is the Kth largest
    if (counter == k)
    {
        kLargest = node->data;
        return;
    }

    // Traverse left subtree if
    // Kth largest is not found yet
    reverseInorder(node->left, counter, k, kLargest);
}
// optimal funciton to find kth largest,smallest element
pair<int, int> findKthOptimal(BinaryTreeNode<int> *root, int k)
{
    int kSmallest = INT_MIN, kLargest = INT_MIN;
    // Counter to track visited nodes
    int counter = 0;

    // Find Kth smallest element
    // (perform inorder traversal)
    inorder(root, counter, k, kSmallest); // T:O(K)

    // Reset counter for Kth largest element
    counter = 0;
    // Find Kth largest element
    // (perform reverse inorder traversal)
    reverseInorder(root, counter, k, kLargest); // T:O(K)

    return make_pair(kSmallest, kLargest);
    // T:O(K)
    // S:O(1)
}
int main()
{

    // 10 8 12 6 9 11 13 -1 -1 -1 -1 -1 -1 -1 -1

    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    int k = 3;
    // pair<int, int> ans = findKthBrute(root, k);
    pair<int, int> ans = findKthOptimal(root, k);
    cout << "Kth smallest : " << ans.first << endl;
    cout << "Kth largest : " << ans.second << endl;
    delete root;

    return 0;
}