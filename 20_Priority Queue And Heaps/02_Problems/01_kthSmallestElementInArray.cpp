/*You are given an array of integers 'ARR' of size 'N' and another integer 'K'.
Your task is to find and return 'K'th smallest value present in the array.
Note: All the elements in the array are distinct.
Example
If 'N' is 5 and 'K' is 3 and the array is 7, 2, 6, 1, 9

Sorting the array we get 1, 2, 6, 7, 9

Hence the 3rd smallest number is 6.*/

#include <bits/stdc++.h>
using namespace std;

// brute force solution
// takes two parameters: input array
// and int k representing to find out kth smallest element
int kthSmallestBrute(int k, vector<int> Arr)
{

    // step 1: sort the array
    sort(Arr.begin(), Arr.end());
    // step 2: return the number
    return Arr[k - 1];
    // T:O(NlogN)
    // S:O(1)
}
// optimal solution
int kthSmallestOptimal(int k, vector<int> Arr)
{

    // step 1: create a min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = Arr.size();
    // insert all elements inside min heap
    for (int i = 0; i < Arr.size(); i++)
    {
        pq.push(Arr[i]);
    }
    // step 2: pop out k-1 elements from heap
    int f = k - 1;

    while (f > 0)
    {
        pq.pop();
        f--;
    }
    // step 3: top heap element is the kth smallest one
    return pq.top();
    // T:O(nlogn+(k-1)logn)
    // S:O(n), for heap
}
int main()
{
    vector<int> v = {18, 1, 8, 5, 20, 13, 14, 71, 52, 69, 13, 18, 24};
    int k = 4;
    // int ans = kthSmallestBrute(k, v);
    int ans = kthSmallestOptimal(k, v); // 13
    cout << k << "th smallest element: " << ans << endl;
    return 0;
}