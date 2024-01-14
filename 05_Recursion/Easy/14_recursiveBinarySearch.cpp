/*
binary search: a sorting algorithm in a limited search space.
it is implemented in a sorted array to find an element.
for each iteration, it halves the search space.
it returns the index of the element if it is present
in the array. otherwise returns -1.
*/

#include <iostream>
using namespace std;

// recursive binary search
int recursiveBinarySearch(int arr[], int low, int high, int val)
{
    // base case
    if (low > high)
    {
        return -1;
    }
    // int mid = (low + high) / 2; it can cause int overflow
    int mid = low + (high - low) / 2;
    int index;
    if (arr[mid] == val)
    {
        return mid;
    }
    else if (arr[mid] > val)
    {
        index = recursiveBinarySearch(arr, low, mid - 1, val);
    }
    else
    {
        index = recursiveBinarySearch(arr, mid + 1, high, val);
    }
    return index;
}
// T:O(logN)
int main()
{

    int a[] = {10, 20, 30, 40, 50};
    int b[] = {5, 15, 35, 77, 95, 133, 420};
    int c[] = {100, 150, 300, 600, 900};

    cout << "index of 30 in array a is: " << recursiveBinarySearch(a, 0, 5 - 1, 30) << endl;
    cout << "index of 133 in array b is: " << recursiveBinarySearch(b, 0, 7 - 1, 133) << endl;
    cout << "index of 1000 in array a is: " << recursiveBinarySearch(c, 0, 5 - 1, 1000) << endl;
    return 0;
}