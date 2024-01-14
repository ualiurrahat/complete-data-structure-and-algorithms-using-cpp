#include <bits/stdc++.h>

using namespace std;

void bubbleSortRecursive(int a[], int n)
{
    // base case- already sorted
    if (n == 0 || n == 1)
    {
        return;
    }

    // small calculation- placing the last element to its right postion
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            swapped = true;
            swap(a[i], a[i + 1]);
        }
    }
    // if swapped remains false, means array already sorted
    if (swapped == false)
    {
        return;
    }

    // recursive call- place all the other n-1 largest elements to their right place
    bubbleSortRecursive(a, n - 1);
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
    bubbleSortRecursive(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}