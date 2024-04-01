/*
Remove the duplicates from a sorted array such that each element appears once.
Return the size of the new array
ex: arr[] = [1,2,2,2,3]
new array will be [1,2,3]
so ans is 3.
*/

#include <bits/stdc++.h>
using namespace std;

// brute force technique:
// 1. take a set container
// 2. insert all unique elements in that set
// 3. return the size of the set
int removeDuplicatesFromSortedArrayBrute(int arr[], int n)
{
    set<int> s;
    // O(n) for traversing
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]); // each operation, T = logn
    }
    // total T:O(n*logn)
    // S:O(n), for set s
    return s.size();
}

// optimal technique
// two pointer approach
// 1. use two pointer
// 2. compare seconde pointer element to firt one
// 3. if they are different, set the element to the first pointer index
// 4. update the index
// 5. return firt pointer index + 1

int removeDuplicatesFromSortedArrayOptimal(int arr[], int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}
int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    // constructing array with size n
    int arr[n];
    // inserting elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << removeDuplicatesFromSortedArrayBrute(arr, n) << endl;
    cout << removeDuplicatesFromSortedArrayOptimal(arr, n) << endl;
    return 0;
}