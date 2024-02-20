#include <bits/stdc++.h>
using namespace std;

void insertionSortRecursive(int a[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return;
    }
    // recursive call
    insertionSortRecursive(a, n - 1);
    // small calculation
    // store the last element.
    int lastElement = a[n - 1];
    int j = n - 2;

    // move elements of a[0...j] that are greater than last element
    while (j >= 0 && a[j] > lastElement)
    {
        a[j + 1] = a[j];
        j--;
    }
    // place the last element in its correct position
    a[j + 1] = lastElement;
}
int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    cout << "Enter array elements : ";
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
    insertionSortRecursive(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}