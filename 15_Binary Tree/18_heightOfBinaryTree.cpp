
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
int main()
{

    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBinaryTreeLevelWise(root);

    cout << "height: " << height(root) << endl;
    // delete tree
    delete root;

    return 0;
}
