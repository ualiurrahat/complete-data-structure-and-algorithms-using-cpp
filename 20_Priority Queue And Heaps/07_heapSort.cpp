#include <bits/stdc++.h>
using namespace std;

// function to implement heapify algo
// this is for min heap
// takes an array,its size and index i as parameter
// function performs so that index i maintians the heap condition
// within the array
void heapify(vector<int> &arr, int n, int i)
{
    // as we are gonna built min heap, so take i as smallest index
    int smallest = i;
    // index of left and right child
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

    // check min heap condition and update smallest index.
    if (leftIndex < n && arr[smallest] > arr[leftIndex])
    {
        smallest = leftIndex;
    }
    if (rightIndex < n && arr[smallest] > arr[rightIndex])
    {
        smallest = rightIndex;
    }

    // if smallest index is changed, means heapify has been done
    if (smallest != i)
    {
        // swap the numbers
        swap(arr[smallest], arr[i]);
        // perform heapify at smallest index
        heapify(arr, n, smallest);
    }
    // T:O(logN)
}
// Function to perform heap sort
vector<int> heapSort(vector<int> &arr)
{
    // Get the size of the array
    int n = arr.size();

    // Build the min-heap (heapify each node starting from the last non-leaf node)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Vector to store sorted elements
    vector<int> ans;

    // Extract elements from the heap one by one
    while (!arr.empty())
    {
        // Add the root of the heap (minimum element) to the sorted vector
        ans.push_back(arr[0]);

        // Swap the root with the last element
        swap(arr[0], arr[arr.size() - 1]);

        // Remove the last element (which is now the root)
        arr.pop_back();

        // Heapify the reduced heap
        heapify(arr, arr.size(), 0);
    }

    // Return the sorted vector
    return ans;
    // T:O(nlogn)
    // S:O(N),for storing the answer, but algo needed only O(1) space.
}

int main()
{
    vector<int> arr = {18, 1, 8, 5, 20, 25};
    cout << "Given vector: " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> ans = heapSort(arr);
    cout << "Sorted vector: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}