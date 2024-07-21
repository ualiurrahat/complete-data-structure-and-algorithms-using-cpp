/*You are given an array consisting of 'N' distinct positive integers and a number 'K'. Your task is to find the kth largest element in the array.
Example:
Consider the array {2,1,5,6,3,8} and 'K' = 3, the sorted array will be {8, 6, 5, 3, 2, 1}, and the 3rd largest element will be 5.
Note:
1) Kth largest element in an array is the kth element of the array when sorted in non-increasing order.
2) All the elements of the array are pairwise distinct.
*/

#include <bits/stdc++.h>
using namespace std;

// brute force solution
int kthLargestBrute(vector<int> &arr, int K)
{
    // step 1: sort the array
    sort(arr.begin(), arr.end());
    // now (size-k)th element is the kth largest
    return arr[arr.size() - K];
    // T:O(nlogN)
    // S:O(1)
}
int kthLargest(vector<int> &arr, int K)
{
    // step 1: create a max heap
    priority_queue<int> pq;
    // insert all elements in the heap
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }
    // step2: pop first first k-1 elements from the heap
    int f = K - 1;
    while (f)
    {
        pq.pop();
        f--;
    }
    // step 3: top of heap is the kth largest
    return pq.top();
    // T:O(nlogn + (k-1)logn)
    // S:O(logn) for creating max heap
}
int main()
{
    vector<int> v = {18, 1, 8, 5, 20, 13, 14, 71, 52, 69, 13, 18, 24};
    int k = 4; // find kth largest element
    int ans = kthLargestBrute(v, k);
    // int ans = kthSmallestOptimal(k, v);
    cout << k << "th smallest element: " << ans << endl;

    return 0;
}