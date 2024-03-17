// check if BST class is working properly
#include <bits/stdc++.h>
#include "13_1_BSTclass.cpp"

using namespace std;

int main()
{
    BST r;
    r.insert(18);
    r.insert(1);
    r.insert(5);
    r.insert(8);
    r.insert(20);

    r.printBST();

    r.deleteData(18);
    r.deleteData(100);
    r.printBST();

        return 0;
}