void childrenSumProperty(BinaryTreeNode<int> *root)
{
    // base case
    if (root == nullptr)
    {
        return;
    }
    int childData = 0; // to sum  up children node's data
    if (root->left)
    {
        childData += root->left->data;
    }
    if (root->right)
    {
        childData += root->right->data;
    }
    // update root's data if sum of child node data is larger.
    if (childData >= root->data)
    {
        root->data = childData;
    }
    else
    {
        // sum of child nodes data are lesser than actual root node.
        // assigning root node's data to the child nodes.
        if (root->left)
        {
            root->left->data = root->data;
        }
        else if (root->right)
        {
            root->right->data = root->data;
        }
    }

    // recursive call on left and right subtree.
    childrenSumProperty(root->left);
    childrenSumProperty(root->right);

    // backtracking part: going from down to upward nodes
    int tot = 0; // to sum child nodes value
    if (root->left)
    {
        tot += root->left->data;
    }
    if (root->right)
    {
        tot += root->right->data;
    }
    // if node is not leaf, then update root node's data
    if (root->left || root->right)
    {
        root->data = tot;
    }
    // T:O(N), S:O(N)
}