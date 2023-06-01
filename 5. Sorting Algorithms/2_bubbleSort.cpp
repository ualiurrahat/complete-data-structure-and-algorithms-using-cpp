// bubble sort finds out the ith largest element in the ith iteration
// so it sorts the array from right side to left side

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n)
{
    // travere the whole array
    for (int i = 0; i < n - 1; i++)
    {
        // flag to check if sorting is done
        // initial value is false
        bool swapped = false;
        // loop to compare each elements with themselves
        // and place the largest one to the end of the array
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                // swapping is possible. update swapped value
                swapped = true;
                swap(a[j + 1], a[j]);
            }
        }
        // if swapped value is still false,means no further sorting is required
        // so break the loop
        if (swapped == false)
        {
            break;
        }
    }
}
// T:O(N^2) avg case,worst case
// T:O(N) best case, when array is already sorted
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
    bubbleSort(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}