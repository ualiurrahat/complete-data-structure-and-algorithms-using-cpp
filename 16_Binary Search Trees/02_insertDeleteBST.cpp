// here, we will create a BST using the BST class
//  that we created in the header file.
#include "01_binarySearchTreeNode.h"
int main()
{
    BST r;
    cout << "1st bst: " << endl;
    r.insert(18);
    r.insert(1);
    r.insert(5);
    r.insert(8);
    r.insert(20);

    r.printBST();
    cout << "2nd  bst: " << endl;
    r.deleteData(18);
    r.deleteData(100);
    r.printBST();

    return 0;
}