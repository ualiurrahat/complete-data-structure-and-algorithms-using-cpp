/*
quick sort uses partitional logic.
it chooses a pivot element and place it to its right position
then using recursive call it sorts elements of left and right part
of the pivot element
*/

#include <bits/stdc++.h>
using namespace std;

// funciton to perform partional logic
// it finds the right place for pivot element
// and returns its index
// takes the array, lowest and highest index as input

int partition(int a[], int low, int high)
{
    // take the lowes index element as pivot
    int pivot = a[low];
    int i = low;
    int j = high;
    // loop to find right place for pivot
    while (i < j)
    {
        // shift i to right untill greater value than pivot is not found
        while (a[i] <= pivot && i <= high-1)
        {
            i++;
        }
        // shift j to left untill smaller value than pivot is not found
        while (a[j] > pivot && j >= low+1)
        {
            j--;
        }
        // to check if whole is traversed
        if (i < j)
        {
            // j contains lower value than pivot
            // i contains higher one that pivot
            // swap them
            swap(a[i], a[j]);
        }
    }
    // now whole array is traversed.
    // j is the right position for pivot.
    // swap them
    swap(a[j], a[low]);
    // return pivot index i.e. j
    return j;
}
// function to perform quick sort
// takes the array, lowest and highest index as input
void quickSort(int a[], int low, int high)
{
    // edge case
    if (low < high)
    {
        // find index of pivot using partional logic function
        int pivot = partition(a, low, high);
        // now pivot index has the sorted element
        // sort the elements appearing before and after pivot
        // performing recursive call
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}
// T:O(NlogN -> best case
// when pivot index divides the array equally in two halves for each call
// T:O(N^2) -> worst case
// when the input is sorted array
// pivot is always the first element.
// avg case -> T:O(NlogN)
// S:O(N)
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
    quickSort(arr, 0, size - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}