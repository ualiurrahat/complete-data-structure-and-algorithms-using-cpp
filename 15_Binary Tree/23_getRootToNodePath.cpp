/*You are given a binary tree with ‘N’ number of nodes and a node ‘X’. Your task is to print the path from the root node to the given node ‘X’.

A binary tree is a hierarchical data structure in which each node has at most two children.
// this is a binary tree problem. not a BST
// find the path from root to node in a BT
// ex:     4
//    2      6
//  1  3    5  7
// path from 4 to 7 : <4,6,7> or <7,6,4> in any form.
*/
/*You are given two binary trees with 'n' and 'm' nodes respectively.
You need to return true if the two trees are identical. Otherwise, return false.*/
#include <bits/stdc++.h>
// inluding binary tree header file
#include "01_binaryTreeNode.h"

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
int main()
{

    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    // 10 8 12 6 9 11 13 -1 -1 -1 -1 -1 -1 -1 -1

    BinaryTreeNode<int> *root = takeInputLevelWise();

    vector<int> *output = getRootToNodePath(root, 8);
    if (output == nullptr)
    {
        cout << "no path found" << endl;
    }
    else
    {
        for (int i = 0; i < output->size(); i++)
        {
            cout << output->at(i) << " ";
        }
        cout << endl;
    }

    delete output;
    delete root;

    return 0;
}
