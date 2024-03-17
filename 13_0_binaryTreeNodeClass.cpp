// to make Binary Search Tree(BST), we need to create binary tree node
// so here is the class of binary tree node
// binary tree: max child two for each node
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
        delete left;
        delete right;
    }
};
