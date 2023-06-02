/*
insetion sort: divide the array into two parts:
sorted and unsorted part
sorted part consisits of the first element only at the beginning
then elements from unsorted part is compared within the sorted ones
and inserted within the sorted parts
thus whole array is sorted
*/

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n)
{
    // traversing the array from the 2nd element
    // basically traversing the unsorted part
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        // index of the last sorted element
        // from this index, we will compare temp to insert it
        // in the sorted part
        int j = i - 1;
        // condition to find right place for the temp in the sorted part
        while (j >= 0 && a[j] > temp)
        {
            // right shifting elements
            a[j + 1] = a[j];
            // reversely iterating sorted part. that's why decreasing j's value
            j--;
        }
        // insering the temp to its right position
        a[j + 1] = temp;
    }
}

// T:O(N^2), worst, avg case
// best case: T:O(N), when array is given in sorted order as input
// worst case: when input array is reversely sorted.
int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Given array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertionSort(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}