#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    // Traverse through all elements except the last one,
    // because the last element will automatically be sorted.
    for (int i = n - 1; i > 1; i--)
    {
        // Flag to detect if any swapping happened in this iteration.
        // bool swapped = false;

        // Compare adjacent elements and push the largest element to the end.
        for (int j = i; j > 0; j--)
        {
            // If elements are in the wrong order, swap them.
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                // swapped = true;
            }
        }
        cout << "after one iteration: ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;

        // If no swaps occurred, the array is already sorted.
        // if (swapped == false)
        // {
        //     break;
        // }
    }
}
int main()
{
    int arr1[] = {30, 40, 50, 10, 20};
    int arr2[] = {30, 40, 50, 10, 20};
    int n = 5;

    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    bubbleSort(arr2, n);

    cout << "Array after sorting: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}