/*the 23 no. codes was taught by coding ninjas.
this is the problem solution from coding ninjas website
..............
You are given a binary tree with ‘N’ number of nodes and a node ‘X’. Your task is to print the path from the root node to the given node ‘X’.
A binary tree is a hierarchical data structure in which each node has at most two children.
*/
/*
You have been given a Binary Tree having 'n' nodes.
A Symmetric tree is a binary tree whose mirror image is the same as the original tree.
Find out whether the given tree is symmetric or not.
*/

#include <bits/stdc++.h>
// inluding binary tree header file
#include "01_BinaryTreeNode.h"

using namespace std;

// function to print binary tree
void printBinaryTree(BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " : ";
    // printing root's left subtree
    if (root->left != nullptr) // if(root->left) also same
    {
        cout << "L" << root->left->data << " ";
    }
    // printing root's right subtree
    if (root->right != nullptr)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    // recursively calling for left and right sub tree
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}
// function to take user input for creating binary tree
// function will stop taking further input
// and will return a null pointer if -1 is given as input
BinaryTreeNode<int> *takeInput()
{
    // for root node
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;
    // condition for null node
    if (rootData == -1)
    {
        return nullptr;
    }
    // creating root node
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    // user input for left and right child of root node
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    // connecting root with child
    root->left = leftChild;
    root->right = rightChild;

    // returning root;
    return root;
}

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
// function to count total nodes in binary tree.
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
// function to print tree in pre-order
// pre-order: node left right
void preOrder(BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// function to print tree in post-order
// post-order:  left right node
void postOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
// function to print in In-order form
// inorder: left node right
void inOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    // first left child
    inOrder(root->left);
    // then node itself
    cout << root->data << " ";
    // then right child
    inOrder(root->right);
}

// function to create tree from a vector array
BinaryTreeNode<int> *createTree(vector<int> &arr)
{

    // edge case
    if (arr.size() == 0)
    {
        return nullptr;
    }
    // create root node
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[0]);
    // queue to store nodes
    queue<BinaryTreeNode<int> *> pendingNodes;
    // insert root node to the queue
    pendingNodes.push(root);
    int i = 1;
    int n = arr.size();
    while (pendingNodes.size() != 0 && i < n)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        // creat left child  node for front
        BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(arr[i]);
        // attach leftChild node as front's left child
        front->left = leftChild;
        // inseft leftChild to the queue
        pendingNodes.push(leftChild);
        // update value of i
        i++;

        // create right child for front node
        if (i < n)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(arr[i]);
            front->right = rightChild;
            pendingNodes.push(rightChild);
            i++;
        }
    }
    return root;
}
// function that stores the inorder traversal in a vector
// inorder: left,root,right
void inorderTraversal(vector<int> &v, BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(v, root->left);
    v.push_back(root->data);
    inorderTraversal(v, root->right);
}

// function that stores preorder traversal in a vector
// preorder: root,left,right
void preorderTraversal(vector<int> &v, BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    v.push_back(root->data);
    preorderTraversal(v, root->left);
    preorderTraversal(v, root->right);
}
// function that stores postorder traversal in a vector
// post order: left,right,root
void postorderTraversal(vector<int> &v, BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    postorderTraversal(v, root->left);
    postorderTraversal(v, root->right);
    v.push_back(root->data);
}
// function that stores inorder,preorder,post-order traversal
// in a 2d vector
void treeTraversals(BinaryTreeNode<int> *root, vector<vector<int>> &v)

{
    // edge case
    if (root == nullptr)
        return;
    // Initialize vectors if not initialized
    if (v.size() < 3)
        v.resize(3);
    // pre-order traversal
    v[1].push_back(root->data);
    // inorder traversal
    treeTraversals(root->left, v);

    v[0].push_back(root->data);
    // post-order traversal
    treeTraversals(root->right, v);

    v[2].push_back(root->data);

    return;
}
// function to return inorder,preorder,post-order traversal
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)

{
    vector<vector<int>> ans;
    // Initialize vectors if not initialized
    ans.resize(3);
    // edge case
    if (root == nullptr)
    {
        return ans;
    }
    treeTraversals(root, ans);
    return ans;
}
// function that returns iterative pre-order traversal of binary tree
vector<int> iterativePreOrderTraversal(BinaryTreeNode<int> *root)
{
    // to store iterative order
    vector<int> ans;
    // edge case
    if (root == nullptr)
    {
        return ans;
    }
    // take a stack to store nodes in iterative order
    stack<BinaryTreeNode<int> *> st;
    // insert root node in the stack
    st.push(root);
    while (!st.empty())
    {
        // take out top element from stack
        BinaryTreeNode<int> *rootNode = st.top();
        // insert node data in the ans vector
        ans.push_back(rootNode->data);
        // pop out the top element from stack
        st.pop();
        // now push right and left node of root node
        // in the stack. as stack follows FILO method,
        // that is why pushing right node before left one
        // in the stack
        if (rootNode->right != nullptr)
        {
            st.push(rootNode->right);
        }
        if (rootNode->left != nullptr)
        {
            st.push(rootNode->left);
        }
    }
    return ans;
    // T:O(n), S:O(n)
}
// function that returns inorder traversal of binary tree
// using iterative approach.
vector<int> iterativeInorderTraversal(BinaryTreeNode<int> *root)
{
    // to store elements in inorder
    vector<int> ans;
    // edge case
    if (root == nullptr)
    {
        return ans;
    }
    // take a stack and a temporary node
    stack<BinaryTreeNode<int> *> st;
    BinaryTreeNode<int> *node = root;

    // store nodes in the stack and push nodes data
    // in the vector in inorder fashion
    while (true)
    {
        // if node is not null, then insert it in the stack
        // and update node to its left node
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        // in case of node is null
        else
        {
            // if stack is empty, means all nodes have been traversed
            // just break the loop
            if (st.empty())
            {
                break;
            }
            // take top node from the stack
            node = st.top();
            // pop out the top node
            st.pop();

            // now push the node data to the vector
            ans.push_back(node->data);
            // update node to its right node
            node = node->right;
        }
    }
    return ans;
    // T:O(n), S:O(n)
}
// function that returns post order traversal
// uses two stacks and iterative approach
vector<int> iterativePostOrderTraversalOne(BinaryTreeNode<int> *root)
{
    vector<int> ans; // Vector to store the elements in post-order traversal

    // Edge case: if the tree is empty
    if (root == nullptr)
    {
        return ans; // Return empty vector
    }

    stack<BinaryTreeNode<int> *> st1, st2; // Two stacks for iterative traversal
    st1.push(root);                        // Push the root node to the first stack

    // Traverse the tree in a pre-order manner
    while (!st1.empty())
    {
        root = st1.top(); // Get the top element of the first stack
        st1.pop();        // Pop the top element

        st2.push(root); // Push the element to the second stack

        // Push the left child to the first stack if exists
        if (root->left)
        {
            st1.push(root->left);
        }

        // Push the right child to the first stack if exists
        if (root->right)
        {
            st1.push(root->right);
        }
    }

    // Pop elements from the second stack to form the post-order traversal
    while (!st2.empty())
    {
        int val = st2.top()->data; // Get the data of the top element of the second stack
        st2.pop();                 // Pop the top element
        ans.push_back(val);        // Push the data to the result vector
    }

    return ans; // Return the post-order traversal
    // Time Complexity: O(n), where n is the number of nodes in the binary tree
    // Space Complexity: O(n) for the two stacks, where n is the number of nodes in the binary tree
}
// post order traversal in iterative way
// using only one stack here
vector<int> iterativePostOrderTraversalTwo(BinaryTreeNode<int> *root)
{
    vector<int> ans; // to store elements in post order traversal.
    // edge case: if root is empty
    if (root == nullptr)
    {
        return ans; // return empty vector
    }
    stack<BinaryTreeNode<int> *> st; // stack for iterativer traversal

    //  temporary nodes to traverse the whole tree
    BinaryTreeNode<int> *curr = root;
    BinaryTreeNode<int> *temp = root;
    // traverse the tree
    while (curr != nullptr || !st.empty())
    {
        // if curr is not empty, insert node in the stack
        if (curr != nullptr)
        {
            st.push(curr);
            // move to the left child
            curr = curr->left;
        }
        // in case curr is empty
        else
        {
            // move to the right child of top node from stack
            temp = st.top()->right;
            // if temp is empty
            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                // push temp node data to the ans vector
                ans.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return ans;
    // T:O(2N), N[for inserting element in stack] + N[inside while loo]
    // S:O(N)
}
// here is a function that use only one traversal
// and returns preorder,inorder,postorder traversal
// v[0]---> preorder, v[1]-->inorder,v[2]-->postorder
void allIterativeTraversal(BinaryTreeNode<int> *root, vector<vector<int>> &v)
{
    // edge case
    if (root == nullptr)
    {
        return;
    }
    // take a stack of pair of node and an integer number
    stack<pair<BinaryTreeNode<int> *, int>> st;
    // push root node with integer value 1 in the stack
    st.push({root, 1});

    while (!st.empty())
    {
        // take out the top element
        auto it = st.top();
        // pop the element
        st.pop();

        // this is part of preorder
        // increment int value 1 to 2
        // push the curretn node with value increased.
        // push the left side of the tree in the stack
        if (it.second == 1)
        {
            // push in the preorder
            v[0].push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != nullptr)
            {
                st.push({it.first->left, 1});
            }
        }
        // this is part of inorder
        // increment int value 2 to 3
        // push the current node with value increases
        // push the right side tree to the stack
        else if (it.second == 2)
        {
            v[1].push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != nullptr)
            {
                st.push({it.first->right, 1});
            }
        }
        // this is part of postorder
        // no need to push back again
        else
        {
            v[2].push_back(it.first->data);
        }
    }
    return;
    // T:O(3*N), S:(4*n)
}

vector<vector<int>> getAllIterativeTraversals(BinaryTreeNode<int> *root)
{
    vector<vector<int>> v(3);
    allIterativeTraversal(root, v);
    return v;
}
// helper function to binary tree build function
// assuming tree will have the same size for both pre and in form
// assuming tree has no duplicate member.
BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    // base case
    if (inS > inE)
    {
        // since both form has same size so, preS>preE not added in the condition.
        // cause inS gets bigger than inE, automaticcaly preS will be bigger than preE.
        return nullptr;
    }
    int rootData = pre[preS];
    // not pre[0] as we are working at a portion of the whole tree.

    //  searching rootIndex in inorder array
    int rootIndex = -1;
    // searching index of root in in-order form
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    // necessary var.
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    // lpreE - lpreS = lInE-lInS
    int lPreE = lInE - lInS + lPreS;

    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}
// function to construct a tree form given in-order and pre-order input.
// assuming tree will have the same size for both pre and in form
// assuming tree has no duplicate member.
BinaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}
// helper2 funciton to build tree from inorder and post-order form
BinaryTreeNode<int> *buildTreeHelper2(int *in, int *post, int inS, int inE, int postS, int postE)
{
    if (inS > inE)
    {
        return nullptr;
    }
    int rootData = post[postE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPostS = postS;
    int lPostE = lInE - lInS + lPostS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPostS = lPostE + 1;
    int rPostE = rInE - rInS + rPostS;

    root->left = buildTreeHelper2(in, post, lInS, lInE, lPostS, lPostE);
    root->right = buildTreeHelper2(in, post, rInS, rInE, rPostS, rPostE);

    return root;
}
// function to build tree from inorder and post order form
BinaryTreeNode<int> *buildTree2(int *in, int *post, int size)
{
    return buildTreeHelper2(in, post, 0, size - 1, 0, size - 1);
}
// function to find height of a tree
int height(BinaryTreeNode<int> *root)
{
    // base case
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
    // T:O(n), S:O(n)[stack space at worst case]
}
// function to find diameter of a binary tree
// diameter: longest distance between two node
// note: the path does not need to pass via root.
int diameterBrute(BinaryTreeNode<int> *root)
{
    // base case
    if (root == nullptr)
    {
        return 0;
    }
    // find height of left and right subtree
    int option1 = height(root->left) + height(root->right);
    // find diameter of left subtree
    int option2 = diameterBrute(root->left);
    // diameter of right sub tree
    int option3 = diameterBrute(root->right);

    // diameter of the tree would be max value of these.
    return max(option1, max(option2, option3));
    // T:O(n*height)
}
// function to get diameter and height together
// better approach to find diameter
// returns height and diameter of a binary tree as a pair object output
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    // base case
    if (root == nullptr)
    {
        pair<int, int> p;
        // first is height
        // second is diameter
        p.first = 0;
        p.second = 0;
        return p;
    }

    // hypothesis and recursive call
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    // calculation
    int height = 1 + max(lh, rh);
    int diameter = max((lh + rh), max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
// brute force solution to check if BT is balanced or not
bool isBalancedBTBrute(BinaryTreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    {
        return true;
    }
    // find height of left and right subtree
    int lh = height(root->left);
    int rh = height(root->right);

    // if difference between left and right height
    // is greater than 1, then it is not balanced.
    if (abs(lh - rh) > 1)
    {
        return false;
    }

    // recursive call to check if each left subtree
    // and right subtree is balanced or not
    bool left = isBalancedBTBrute(root->left);
    bool right = isBalancedBTBrute(root->right);

    // if either left or right subtree is false
    // than whole tree is unbalanced
    if (left == false || right == false)
    {
        return false;
    }
    // if code comes here, means each left and
    // right subtree is balanced, so the whole
    // tree is balanced. return true.
    return true;
    // T:O(n*n) = O(n^2) [n=for each node traversal, n= height of each node]
    // S:O(H); h = height of BT, recursvie stack space.
}
// function to find height to check for balanced binary tree
// function returns -1 if it tree is not balanced
int dfsheight(BinaryTreeNode<int> *root)
{
    // base case
    if (root == nullptr)
    {
        return true;
    }
    // find left subtree height
    int lh = dfsheight(root->left);
    // if lh is -1, simply return -1
    // as the whole tree is then unbalanced
    if (lh == -1)
    {
        return -1;
    }
    // find right subtree height
    int rh = dfsheight(root->right);
    // if rh is -1, simply return -1
    // as the whole tree is unbalanced then
    if (rh == -1)
    {
        return -1;
    }
    // if diffrence between lh and rh is > 1,
    // means tree is not balanced. so returning -1.
    if (abs(lh - rh) > 1)
    {
        return -1;
    }

    // in case of balanced tree, this function just returns the height
    return 1 + max(lh, rh);
    // T:O(N), S:O(n)[stack space]
}
bool isBalancedBTBetter(BinaryTreeNode<int> *root)
{
    // if dfsHeight is -1, then tree is unbalanced
    // function returns false.
    // otherwise returns tree, means tree is balanced.
    return dfsheight(root) != -1;
    // T:O(N), S:O(N)[stack space]
}

// helper function to find max path sum
// the function updates the max path sum value in a
// variable named maxi. It takes the reference of this var
// as a funciton input and updates it.
int maxPathDown(BinaryTreeNode<int> *root, int &maxi)
{
    // base case
    if (root == nullptr)
    {
        return 0;
    }
    // Do a simple tree traversal.
    // At each node, find  recursively its leftMaxPath and its   rightMaxPath.
    //  if any of the answer is less than zero, than we do not consider that path for max path sum
    // so updat value of left and right to 0,
    // in case the calculated value is a negative one
    int left = max(0, maxPathDown(root->left, maxi));
    int right = max(0, maxPathDown(root->right, maxi));
    // Calculate the maxPath through the node as val + (leftMaxPath + rightMaxPath) and update maxi accordingly.
    maxi = max(maxi, left + right + root->data);
    // Return the maxPath when node is not the curving point as val + max(leftMaxPath, rightMaxPath).
    return max(left, right) + root->data;
    // T:O(N), S:O(N)
}
// function for finding max path sum
int maxPathSum(BinaryTreeNode<int> *root)
{
    // initializing a maxi variable
    // to store our final answer
    int maxi = INT_MIN;
    // calling the maxPathDown function to find answer
    maxPathDown(root, maxi);
    // returning the max path sum
    return maxi;
    // T:O(N), S:O(N), this complexity is for maxPathDown funciton
}
// function to check if two trees are identical
bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    // base case
    // if any of the roots is null, just return
    // whether the roots are equal or not.
    if (root1 == nullptr || root2 == nullptr)
    {
        return (root1 == root2);
    }
    // recursive call on left and right sub tree
    // to check identicality
    bool leftPart = identicalTrees(root1->left, root2->left);
    bool rightPart = identicalTrees(root1->right, root2->right);

    // trees will be identical when both
    // left and right subtree are identical.
    return leftPart && rightPart;
    // T:O(N), S:O(N)[recursive stack space]
}
// Function to return a vector of pointers to the root node to the node with the given data
vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    // Base case: If root is null, return null (no path exists)
    if (root == nullptr)
    {
        return nullptr;
    }

    // If the current node's data matches the target data
    if (root->data == data)
    {
        // Create a new vector to store the path
        vector<int> *output = new vector<int>();
        // Add the current node's data to the path
        output->push_back(data);
        // Return the path vector
        return output;
    }

    // Recursively search in the left subtree
    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    // If the path exists in the left subtree
    if (leftOutput != nullptr)
    {
        // Add the current node's data to the path
        leftOutput->push_back(root->data);
        // Return the path vector
        return leftOutput;
    }

    // Recursively search in the right subtree
    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    // If the path exists in the right subtree
    if (rightOutput != nullptr)
    {
        // Add the current node's data to the path
        rightOutput->push_back(root->data);
        // Return the path vector
        return rightOutput;
    }
    else
    {
        // If the target data is not found in either subtree, return null
        return nullptr;
    }
    // T:O(N), S:O(N)
}
// function that returns zigzag traversal of binary tree
vector<vector<int>> zigzagLevelOrder(BinaryTreeNode<int> *root)
{
    // base case
    if (root == nullptr)
    {
        vector<vector<int>> ans;
        return ans;
    }
    // to store ans
    vector<vector<int>> ans;
    // queue to store the nodes
    queue<BinaryTreeNode<int> *> q;
    // to check travesal direction of the nodes
    bool leftToRight = true;
    q.push(root);

    while (!q.empty())
    {
        // total queue size
        int size = q.size();
        // to store each level nodes
        vector<int> temp(size);

        // loop for each level processing
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front = q.front();
            q.pop();

            // find right position of the nodes
            // from RightToLeft and vice versa traversal
            int index = leftToRight ? i : size - i - 1;
            // inserting node in the temporary array
            temp[index] = front->data;

            // include node childs in the queue
            if (front->left != nullptr)
            {
                q.push(front->left);
            }
            if (front->right != nullptr)
            {
                q.push(front->right);
            }
        }
        // change direction
        leftToRight = !leftToRight;
        // insert level wise temp array into ans array
        ans.push_back(temp);
    }

    return ans;
    // T:O(N), S:O(N)
}
// function to get left boundary nodes
void traverseLeft(BinaryTreeNode<int> *root, vector<int> &ans)
{
    // base case :discard and return in case of leaf nodes
    // or in case of empty node
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    // insert the node
    ans.push_back(root->data);
    // traverse left part first
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    // only  traverse right part when left part does not exist
    else
    {
        traverseLeft(root->right, ans);
    }
    // T:O(H)
}
// function to get leaf nodes of a tree
void traverseLeaf(BinaryTreeNode<int> *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // push leaf nodes
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    // push leaf nodes of left subtrees
    traverseLeaf(root->left, ans);
    // push leaf nodes of right subtrees
    traverseLeaf(root->right, ans);
    // T:O(N)
}
// function to get right boundary nodes of a BT
void traverseRight(BinaryTreeNode<int> *root, vector<int> &ans)
{
    // base case :discard and return in case of leaf nodes
    // or in case of empty node
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    // first go right subtrees
    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    // only if right subtree does not exist, go to left one and traverseLeft
    else
    {
        traverseRight(root->left, ans);
    }

    // push right subtree nodes in reverse order
    ans.push_back(root->data);
    // O(H)
}
// function to dispay the boundary traversal of a BT.
/*
Boundary Traversal includes:
1) nodes from the left boundaries excluding leaf child
2) all the leaf child
3)revered order right boundary nodes excluding leaf child

*/
vector<int> traverseBoundary(BinaryTreeNode<int> *root)
{
    vector<int> ans; // to store ans
    // base case
    if (root == NULL)
    {
        return ans;
    }
    // insert root node in the ans
    ans.push_back(root->data);
    // left boundary nodes
    traverseLeft(root->left, ans);

    // travaerse leaf nodes

    // collect  leaf nodes
    traverseLeaf(root, ans);

    // reverse right boundary nodes
    traverseRight(root->right, ans);

    // return ans
    return ans;
    // T:O(H)+O(H)+O(N) = O(2H*N) ~~ O(N)
    // S:O(N), stack space.
}
// function for vertical order traversal
vector<int> verticalOrderTraversal(BinaryTreeNode<int> *root)
{
    map<int, map<int, multiset<int>>> nodes;
    // first int-> horizontal distance
    // second int-> level
    // vector-> nodes in level wise

    queue<pair<BinaryTreeNode<int> *, pair<int, int>>> q;
    // first int -> horizontal distance
    // second int -> level

    // vector to store ans
    vector<int> ans;

    // base case
    if (root == NULL)
    {
        return ans;
    }
    // insert root node in the queue
    q.push(make_pair(root, make_pair(0, 0)));
    // root node is having 0 horizontal distance
    // and level is 0

    // loop for other nodes
    while (!q.empty())
    {
        // get the front node from the queue
        pair<BinaryTreeNode<int> *, pair<int, int>> temp = q.front();
        // deque front from the queue
        q.pop();

        // get node from the temp
        BinaryTreeNode<int> *frontNode = temp.first;
        // get horizontal distance
        int horizontalDistance = temp.second.first;
        // get level
        int level = temp.second.second;

        // insert the node with the corresponding level and horizontal distance
        // inside the nodes map
        nodes[horizontalDistance][level].insert(frontNode->data);

        // insert left child of node if it exists
        // for left child, horizontal distance decreases by 1 and level increases by 1
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(horizontalDistance - 1, level + 1)));
        }
        // insert right child of node if it exists
        // for right child, horizontal distance increases by 1 and level increases by 1
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(horizontalDistance + 1, level + 1)));
        }
    }

    // push the level wise nodes in the ans array
    for (auto i : nodes)
    {
        // nodes.first = int(distance)
        // nodes.second = map<int,vector>
        // so going for second option
        for (auto j : i.second)
        {
            // nodes.second = map<int,vector>
            // so going for second option for vector
            for (auto k : j.second)
            {
                // the vector list is the level wise nodes
                // push them in the ans array
                ans.push_back(k);
            }
        }
    }
    return ans;
    // T:O(NlogN)
    // S:O(N)
}
// function to get top view of BT
vector<int> getTopView(BinaryTreeNode<int> *root)
{
    vector<int> ans; // Result vector to store top view elements

    // Base case: if the tree is empty, return empty result
    if (root == nullptr)
    {
        return ans;
    }

    // Map to store the first node seen from each vertical line
    map<int, int> mpp; // Key: vertical line, Value: node data

    // Queue to perform level order traversal of the tree
    // Each element in the queue is a pair of TreeNode pointer and its corresponding vertical line
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0}); // Pushing the root node with vertical line 0

    // Level order traversal of the tree
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int> *node = it.first;
        int line = it.second;

        // If this vertical line is not yet mapped, then add the node data to the map
        if (mpp.find(line) == mpp.end())
        {
            mpp[line] = node->data;
        }

        // Enqueue left child with vertical line decremented by 1
        if (node->left)
        {
            q.push({node->left, line - 1});
        }

        // Enqueue right child with vertical line incremented by 1
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
    }

    // Extracting the top view elements from the map and storing them in the result vector
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }

    return ans; // Returning the top view elements
    // T:O(N)
    // S:O(2N)
}
// Function: bottomView
// Description: This function computes the bottom view of a binary tree.
// Parameters:
//   - root: Pointer to the root node of the binary tree.
// Return:
//   - A vector containing the bottom view of the binary tree.
//     The elements in the vector represent the node values visible from the bottom.
vector<int> bottomView(BinaryTreeNode<int> *root)
{
    // Initialize an empty vector to store the result
    vector<int> ans;

    // Check if the tree is empty
    if (root == nullptr)
    {
        return ans; // Return empty vector if the tree is empty
    }

    // Initialize a queue to perform level order traversal
    // Each element in the queue is a pair of TreeNode* and its horizontal distance
    queue<pair<BinaryTreeNode<int> *, int>> q;

    // Create a map to store the horizontal distance of each node from the root
    // and the corresponding node value
    map<int, int> mpp;

    // Push the root node along with its horizontal distance (0) into the queue
    q.push({root, 0});

    // Perform level order traversal
    while (!q.empty())
    {
        // Extract the front element from the queue
        auto it = q.front();
        q.pop();

        // Extract the TreeNode* and its horizontal distance from the pair
        BinaryTreeNode<int> *node = it.first;
        int line = it.second;

        // Update the map with the node value at its horizontal distance
        // This ensures that the latest node at each horizontal distance is stored
        mpp[line] = node->data;

        // Enqueue the left child with horizontal distance decreased by 1
        if (node->left)
        {
            q.push({node->left, line - 1});
        }

        // Enqueue the right child with horizontal distance increased by 1
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
    }

    // Traverse the map and store the bottom view nodes in the result vector
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }

    // Return the vector containing the bottom view of the binary tree
    return ans;
    // T:O(N), S:O(N)
}
// This function is a recursive helper function to traverse the binary tree and store the right view elements
// Parameters:
// - root: Pointer to the current node being visited
// - level: Current level of the node in the tree
// - res: Reference to the vector storing the right view elements
void solveRightView(BinaryTreeNode<int> *root, int level, vector<int> &res)
{
    // Base case: If the current node is null, return
    if (root == nullptr)
    {
        return;
    }

    // If the level matches the size of the result vector, it indicates the rightmost element at this level.
    // So, we append this node's data to the result vector.
    if (level == res.size())
    {
        res.push_back(root->data);
    }

    // Recursively traverse the right subtree first, then the left subtree, incrementing the level at each step.
    solveRightView(root->right, level + 1, res);
    solveRightView(root->left, level + 1, res);
}

// This function initiates the process of printing the right view of a binary tree
// It calls the solve function to traverse the tree and store the right view elements in a vector
// Parameter:
// - root: Pointer to the root of the binary tree
// Return:
// - A vector containing the right view elements of the binary tree
vector<int> printRightView(BinaryTreeNode<int> *root)
{
    // Initialize an empty vector to store the right view elements
    vector<int> ans;
    // Call the solve function to traverse the binary tree and store the right view elements
    solveRightView(root, 0, ans);
    // Return the vector containing the right view elements
    return ans;
    // T:O(N),
    // S:O(H)
}
// This function recursively traverses a binary tree to find the left view elements.
// It stores the leftmost element at each level in the 'res' vector.
// Parameters:
// - root: Pointer to the current node being visited
// - level: Current level of the node in the tree
// - res: Reference to the vector storing the left view elements
void solveLeftView(BinaryTreeNode<int> *root, int level, vector<int> &res)
{
    // Base case: If the current node is null, return
    if (root == nullptr)
    {
        return;
    }

    // If the level matches the size of the result vector, it indicates the leftmost element at this level.
    // So, we append this node's data to the result vector.
    if (level == res.size())
    {
        res.push_back(root->data);
    }

    // Recursively traverse the left subtree first, then the right subtree, incrementing the level at each step.
    solveLeftView(root->left, level + 1, res);
    solveLeftView(root->right, level + 1, res);
}

// This function initiates the process of printing the left view of a binary tree.
// It calls the solveLeftView function to traverse the tree and store the left view elements in a vector.
// Parameter:
// - root: Pointer to the root of the binary tree
// Return:
// - A vector containing the left view elements of the binary tree
vector<int> printLeftView(BinaryTreeNode<int> *root)
{
    // Initialize an empty vector to store the left view elements
    vector<int> ans;
    // Call the solveLeftView function to traverse the binary tree and store the left view elements
    solveLeftView(root, 0, ans);
    // Return the vector containing the left view elements
    return ans;
    // T:O(N), S:O(H)
}
// Function: isSymmetricHelp
// Description: Recursively checks if a binary tree is symmetric by comparing corresponding nodes from left and right subtrees.
// Parameters:
//   - left: Pointer to the left subtree node
//   - right: Pointer to the right subtree node
// Returns:
//   - bool: Returns true if the binary tree rooted at the given nodes is symmetric, false otherwise.
bool isSymmetricHelp(BinaryTreeNode<int> *left, BinaryTreeNode<int> *right)
{
    // Base case: if either left or right node is NULL,
    // return true if both are NULL (symmetric), otherwise return false
    if (left == NULL || right == NULL)
    {
        return left == right;
    }

    // If data of current nodes doesn't match, the tree is not symmetric
    if (left->data != right->data)
    {
        return false;
    }

    // Recursively check symmetry of subtrees
    // by comparing nodes in mirror positions
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    // T:O(N),S:O(N)
}

// Function: isSymmetric
// Description: Checks if a binary tree is symmetric.
// Parameters:
//   - root: Pointer to the root node of the binary tree
// Returns:
//   - bool: Returns true if the binary tree rooted at the given node is symmetric, false otherwise.
bool isSymmetric(BinaryTreeNode<int> *root)
{
    // If root is NULL or the tree has only one node (which is symmetric by definition),
    // return true
    return (root == NULL || isSymmetricHelp(root->left, root->right));
}
/**
 * @brief This function finds a path from a given node to the root in a binary tree.
 *
 * @param root Pointer to the root of the binary tree.
 * @param res Reference to a vector to store the path from node to root.
 * @param x The value of the node whose path needs to be found.
 * @return True if the path is found, false otherwise.
 */
bool getPath(BinaryTreeNode<int> *root, vector<int> &res, int x)
{
    // Base case: if the root is null, return false as there's no path.
    if (root == nullptr)
    {
        return false;
    }

    // Push the current node's value to the result vector.
    res.push_back(root->data);

    // If the current node's value matches the target value x, return true.
    if (root->data == x)
    {
        return true;
    }

    // Recursively search in the left and right subtrees for the target value.
    if (getPath(root->left, res, x) || getPath(root->right, res, x))
    {
        return true;
    }

    // If the target value is not found in the current subtree, pop the last element
    // from the result vector and return false.
    res.pop_back();
    return false;
}

/**
 * @brief This function returns a path from a given node to the root in a binary tree.
 *
 * @param root Pointer to the root of the binary tree.
 * @param x The value of the node whose path needs to be found.
 * @return A vector containing the path from node to root.
 */
vector<int> pathInATree(BinaryTreeNode<int> *root, int x)
{
    // Initialize an empty result vector.
    vector<int> res;

    // If the tree is empty, return the empty result vector.
    if (root == nullptr)
    {
        return res;
    }

    // Call the getPath function to find the path and return the result vector.
    getPath(root, res, x);
    return res;
    // T:O(N), S:O(H)
}

int main()
{

    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    // 10 8 12 6 9 11 13 -1 -1 -1 -1 -1 -1 -1 -1
    // 10 5 20 3 8 18 25 -1 -1 7 -1 -1 -1 -1 -1 -1 -1

    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBinaryTreeLevelWise(root);

    vector<int> road = pathInATree(root, 8);
    for (auto it : road)
    {
        cout << it << " ";
    }

    cout << endl;
    delete root;

    return 0;
}
