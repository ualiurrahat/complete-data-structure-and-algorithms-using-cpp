// sort an array using recursion.
#include <iostream>

using namespace std;

bool isSorted(int a[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return true;
    }
    // small calculation: condition to check sorted or not
    if (a[0] > a[1])
    {
        return false;
    }
    // recursive call
    bool isSmallerSorted = isSorted(a + 1, n - 1);

    return isSmallerSorted;
    /*return isSmallerSorted is equivalent to....
    if(isSmallerSorted)
    {
        return true;
    }
    else
    {
        return false;
    }
    */
}

// check what is the difference between the first and second function
// funciton 1 does check condition first and then perform recursion
// function 2 first does recursive call then compare sorted or not.

bool isSorted2(int a[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return true;
    }
    // recursive call
    bool isSmallerSorted = isSorted(a + 1, n - 1);

    // check if the array from the last that we traverse through recursion is sorted or not
    if (!isSmallerSorted)
    {
        // array is not sorted in the recursive part
        // so no point in checking the first two element
        // as even if arr[0],arr[1] are sorted, still whole array is unsorted.
        // returning false as array is not sorted.
        return false;
    }
    // condition to check sorted or not
    if (a[0] > a[1])
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{

    int a[] = {2, 3, 4, 5, 6};
    int n = 5;
    cout << isSorted(a, n) << endl;
    cout << isSorted2(a, n) << endl;

    int b[] = {2, 3, 5, 4, 6};

    cout << isSorted(b, n) << endl;
    cout << isSorted2(b, n) << endl;

    return 0;
}