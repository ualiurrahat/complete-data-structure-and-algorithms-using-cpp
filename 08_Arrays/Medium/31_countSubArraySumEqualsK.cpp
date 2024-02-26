/*You are given an integer array 'arr' of size 'N' and an integer 'K'.

Your task is to find the total number of subarrays of the given array whose sum of elements is equal to k.

A subarray is defined as a contiguous block of elements in the array.

Example:
Input: ‘N’ = 4, ‘arr’ = [3, 1, 2, 4], 'K' = 6

Output: 2

Explanation: The subarrays that sum up to '6' are: [3, 1, 2], and [2, 4].*/

#include <bits/stdc++.h>
using namespace std;

// brute force solution
int countAllSubarraysWithGivenSumBrute(vector<int> &arr, int k)
{
    // size of the array
    int n = arr.size();
    // total subarrays
    int count = 0;
    // starting index i
    for (int i = 0; i < n; i++)
    {
        // ending index j
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            // calculate sum of subarrays from [i,...,j]
            for (int l = i; l <= j; l++)
            {
                sum += arr[l];
            }
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
    // T:O(n^3), S:O(1)
}
// better solution
int countAllSubarraysWithGivenSumBetter(vector<int> &arr, int k)
{
    // size of the array
    int n = arr.size();
    // total subarrays
    int count = 0;
    // starting index i
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        // ending index j
        for (int j = i; j < n; j++)
        {
            // calculate sum of subarrays from [i,...,j]
            sum += arr[j];
            // increase the count if sum equals to k
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
    // T:O(n^2), S:O(1)
}
// optimal solution
int countAllSubarraysWithGivenSumOptimal(vector<int> &arr, int k)
{
    // array size
    int n = arr.size();
    // hashmap to store prefix sum and its frequency
    unordered_map<int, int> mpp;
    int preSum = 0, count = 0;
    // setting 0 in the mpp;
    mpp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        // add current element in the prefix sum
        preSum += arr[i];
        // calculate preSum - k
        int remove = preSum - k;
        // add the no. of subarrays to be removed
        count += mpp[remove];
        // update the count of prefix sum in the map
        mpp[preSum] += 1;
    }
    return count;
    // S:O(n), for hashmap
    // T:O(n*mapTime),
    // T:O(n*1)[for unordered map,average time complexity]
    // T:O(n*n)[for unordered map,worst time complexity]
}
int main()
{
    vector<int> arr;
    int n;
    cout << "enter array size: ";
    cin >> n;

    cout << "enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int k;
    cout << "Enter sum of subarray : ";
    cin >> k;
    // int ans = countAllSubarraysWithGivenSumBrute(arr, k);
    // int ans = countAllSubarraysWithGivenSumBetter(arr, k);
    int ans = countAllSubarraysWithGivenSumOptimal(arr, k);
    cout << "No. of Subarrays with given sum " << k << " is " << ans << endl;
    return 0;
}