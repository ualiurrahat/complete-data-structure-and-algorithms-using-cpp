// Selection Sort
// selects the minimum element in each iteration
// and arrange them sorting order

#include <bits/stdc++.h>
using namespace std;

// selection sort function takes an array and its size as input
void selectionSort(int a[], int n)
{
    // traverse the whole array
    for (int i = 0; i < n - 1; i++)
    {
        // to store the index of the minimum value.
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            // condition to find minimum element
            // if found, update the minIndex
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        // if minIndex is changed, then swap elements
        if (minIndex != i)
        {
            swap(a[i], a[minIndex]);
        }
    }
}
// T: O(N^2) in best,worst, average case.

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
    selectionSort(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}