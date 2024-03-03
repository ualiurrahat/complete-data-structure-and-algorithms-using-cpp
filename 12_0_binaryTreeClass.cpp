// binary tree: Binary Tree is a tree data structure
// which have at max two child

// Node:
//   1           1
// 2       and     2
// both are same in generic trees.
// but they are different in binary trees.
// 2 is left child in first case
// and right child in second case.
template <typename T>
class BinaryTreeNode
{
public:
    // to store data
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    // destructor to delete entire binary tree
    ~BinaryTreeNode()
    {
        // for only one node, left and right will be NULL.
        // so delete will be called upon NULL.
        // this works fine also.
        // computer just ignores "delet null" command
        delete left;
        delete right;
    }
};
