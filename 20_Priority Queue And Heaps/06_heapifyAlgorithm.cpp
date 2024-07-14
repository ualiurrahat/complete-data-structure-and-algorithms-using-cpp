/*
heapify algorithm is the process by which a binary tree is reshaped
into a heap data structure.
- we can build min or max heap i.e. priority queue using heapify algorithm
- for a CBT of n sizes, the elemes starting from (n/2 +1)th to nth are nearly leaf nodes
so, they already follow the heap property.
So, for a given array of n sizes, if we want to convert it into a heap
we will have to perform the heapify algorithm from 0th index to upto (n/2)th index.

*/
/* PROBLEM STATEMENT
You are given an array 'ARR' of integers having 'N' elements. Your task is to convert the input array into a min-Binary Heap.
Note :
1. Input array follows 0 - based indexing.
2. After constructing the min-heap, the Left child of the 'i-th' node should be present at the (2*i + 1)-th index if it exists.
3. After constructing the min-heap, the Right child of the 'i-th' node should be present at the (2*i + 2)-th index if it exists.
4. Note that you do not need to create a tree, just update the array.*/

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
// function to create a min heap using the heapify algorithm
// takes an array as input.
// return the array in min heapify format.
vector<int> buildMinHeap(vector<int> &arr)
{
    // size of the array
    int n = arr.size();
    // every CBT of n sizes follows the heap properting
    // from (n/2)+1 th to nth elements
    // for 0 based indexing, they are elements
    // from index n/2 to index n-1.
    // so no need to perform heapify on those elements.
    // performing heapify from index n/2 -1 to upto the root index.
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return arr;
}
int main()
{
    vector<int> arr = {9, 3, 2, 6, 7};
    cout << "Given Vector: " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = buildMinHeap(arr);
    cout << "Vector after performing min heapify: " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}