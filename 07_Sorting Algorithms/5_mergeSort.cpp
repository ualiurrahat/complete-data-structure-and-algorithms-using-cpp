/*
merge sort uses divide & conquer algorithm
divides the given array into two parts
sort them
and merge them
whole array is thus sorted
*/
#include <bits/stdc++.h>
using namespace std;

// funciton to merge two sorted arrays
void merge(int arr[], int low, int mid, int high)
{

    int i = low;
    int j = mid + 1;
    int k = low;
    // take an array to store elements in sorted order
    int b[high + 1];
    // compare elements from low to mid and mid to high indexes
    //  and store them in b array
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    // in case left part is exhausted but right part has elements to sort
    if (i > mid)
    {
        while (j <= high)
        {
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    // case when right part is exhausted but left part is not
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            k++;
            i++;
        }
    }
    // now copy b array in a
    for (k = low; k <= high; k++)
    {
        arr[k] = b[k];
    }
}
// merge sort funciton
// takes an array,lowest index, and last index
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // find mid index
        int mid = low + (high - low) / 2;
        // recursive call
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        // merge sorted parts
        merge(arr, low, mid, high);
    }
}

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
    // calling quickSort funciton to sort the array
    mergeSort(arr, 0, size - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}