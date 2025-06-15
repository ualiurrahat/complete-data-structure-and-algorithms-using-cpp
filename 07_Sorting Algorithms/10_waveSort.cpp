/*
Problem:
Convert an unsorted array into a wave-form array such that:
arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] ...

Approach (O(N) time):
We iterate over the array in steps of 2 and ensure:
- For every even index i, arr[i] is greater than or equal to its neighbors.

Steps:
1. At index i:
   - If arr[i] < arr[i-1], swap(i, i-1)
   - If arr[i] < arr[i+1], swap(i, i+1)
This ensures local wave property without needing to sort the array.

No sorting is used — runs in linear time.
*/

#include <iostream>
#include <vector>
using namespace std;

// O(N) wave sort without sorting
vector<int> waveFormArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i += 2)
    {
        // Check left neighbor
        if (i > 0 && arr[i] < arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
        }

        // Check right neighbor
        if (i < n - 1 && arr[i] < arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    return arr;

    // T:O(N), S:O(1)
}

int main()
{
    vector<int> arr = {4, 3, 5, 2, 3, 1, 2};
    int n = arr.size();

    vector<int> result = waveFormArray(arr, n);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
