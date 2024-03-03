#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
  T data;
  BinaryTreeNode *left;
  BinaryTreeNode *right;

  // constructor
  BinaryTreeNode(int data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }

  // destructor
  ~BinaryTreeNode()
  {
    delete left;
    delete right;
  }
};

void print(BinaryTreeNode<int> *root)
{
  if (root == nullptr)
    return;

  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);

  while (!pendingNodes.empty())
  {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();

    cout << front->data << ": ";
    if (front->left != nullptr)
    {
      cout << "L" << front->left->data << " ";
      pendingNodes.push(front->left);
    }
    if (front->right != nullptr)
    {
      cout << "R" << front->right->data;
      pendingNodes.push(front->right);
    }
    cout << endl;
  }
}

BinaryTreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter root data: " << endl;
  cin >> rootData;
  if (rootData == -1)
  {
    return nullptr;
  }
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);

  while (!pendingNodes.empty())
  {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();

    int leftChildData;
    cout << "Enter left child of " << front->data << " : " << endl;
    cin >> leftChildData;
    if (leftChildData != -1)
    {
      BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
      front->left = leftChild;
      pendingNodes.push(leftChild);
    }
    int rightChildData;
    cout << "Enter rigth child of " << front->data << " : " << endl;
    cin >> rightChildData;
    if (rightChildData != -1)
    {
      BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
      front->right = rightChild;
      pendingNodes.push(rightChild);
    }
  }
  return root;
}

int countNodes(BinaryTreeNode<int> *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  int ans = 1;
  int countLeftNodes = countNodes(root->left);
  int countRightNodes = countNodes(root->right);
  return ans + countLeftNodes + countRightNodes;
}

void inOrder(BinaryTreeNode<int> *root)
{
  if (root == nullptr)
  {
    return;
  }
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
  if (inS > inE)
  {
    return nullptr;
  }
  int rootData = pre[preS];
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

  int rootIndex = -1;
  for (int i = inS; i <= inE; i++)
  {
    if (in[i] == rootData)
    {
      rootIndex = i;
      break;
    }
  }
  int lInS = inS;
  int lInE = rootIndex - 1;
  int rInS = rootIndex + 1;
  int rInE = inE;
  int lpreS = preS + 1;
  int lpreE = lInE - lInS + lpreS;
  int rPreS = lpreE + 1;
  int rPreE = preE;

  root->left = buildTreeHelper(in, pre, lInS, lInE, lpreS, lpreE);
  root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
  return root;
}
BinaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{
  return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

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
BinaryTreeNode<int> *buildTree2(int *in, int *post, int size)
{
  return buildTreeHelper2(in, post, 0, size - 1, 0, size - 1);
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
  int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
  int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
  int post[] = {4, 5, 2, 8, 9, 6, 7, 3, 1};

  BinaryTreeNode<int>* root = buildTree2(in,post,9);
  print(root);

  return 0;
}