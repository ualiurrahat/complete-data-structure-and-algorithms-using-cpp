#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    // every tree node will contain a data and its children
    // data to store value
    T data;
    // vector array pointer to store children of the node.
    vector<TreeNode<T> *> children;
    // vector is for containing all children of a node
    // if parent contains T type data, children must have T type data only.
    // so, vector is taking pointers of TreeNode which contains T type data

    // constructor:
    TreeNode(T data)
    {
        this->data = data;
    }

    // deleting tree using destructor
    // when we use 'delete' keyword, destructor is called
    // if we don't write our destructor and called delete for root
    // default destructor will delete only root but not its children
    // so we are deleting children first with the help of recursive call
    // inside the destructor.
    ~TreeNode()
    {

        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};