/*
you are given an array and a number k(only positive numbers). find the length of the longest sub-array
whose sum is equal to k.
ex: k = 3, a[] = {1,2,3,1,1,1}
output = 3
explanation: subaray with sum 3 are: [1,2],[3],[1,1,1]. so length of the longest is 3
sub-array: contiguous part of the array
here, a[] = {1,2,3,4,5},
{2,3},{2},{4,5} are sub-array since they are contiguous
but {1,3,5}, {2,4,}, {3,5} are not.
formula: for n numbers in an array, total sub-array can be formed is = (n*(n+1)) / 2
*/
#include <bits/stdc++.h>
using namespace std;

// brute force approach
int longestSubArrayWithSumKBrute(int a[], int n, int k)
{
    int length = 0;
    for (int i = 0; i < n; i++)
    { // starting index
        for (int j = i; j < n; j++)
        { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++)
            {
                s += a[K];
            }

            if (s == k)
                length = max(length, j - i + 1);
        }
    }
    return length;
}
// T:O(N^3), do not know why, but code is giving wrong output.
// brute force solution 2
int longestSubArrayWithSumKBrute2(int a[], int n, int k)
{
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + a[j];

            if (sum == k)
            {
                int currLength = j - i + 1;
                length = max(length, currLength);
            }
        }
    }

    return length;
}
// T:O(N^2)

// better approach: use hashmaping
int longestSubArrayWithSumKBetter(int arr[], int n, int k)
{
    // declaring a map to store the prefix sum and indices
    map<int, int> preSumMap;
    int maxLen = 0;
    int sum = 0;
    // traversing entire array
    for (int i = 0; i < n; i++)
    {
        // calculate sum of elements
        sum += arr[i];
        //  check if sum is equal to k
        if (sum == k)
        {
            // so, there is a subarray with sum k from index 0 to i.
            // Compare new length with previous max length
            maxLen = max(maxLen, i + 1);
        }
        // calculate sum - k
        int rem = sum - k;
        // check if rem is already exists in the hashmap
        if (preSumMap.find(rem) != preSumMap.end())
        {
            // rem exists.So found a subarray with sum k. alculate the length of the subarray
            int len = i - preSumMap[rem];
            // compare and update maxLen
            maxLen = max(len, maxLen);
        }
        // if sum does not exist in the hashmap, insert it with its index value.
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    // return the max length
    return maxLen;
}
// T:O(N*logN) for ordered ma, O(N) for unordered map but O(N^2) in worst case
// since, unordered map takes O(N) time for each insertion in the worst case

// S:O(N) for the map

// optimal approach
int longestSubArrayWithSumKOptimal(int a[], int n, int k)
{
    int maxLen = 0;
    // taking two pointers initially pointing index 0
    int left = 0, right = 0; // the sum is set to the first element initially
    int sum = a[0];
    // outer loop running until the right pointer crosses the last index
    while (right < n)
    {
        // another loop running until sum is greater than k
        while (left <= right && sum > k)
        {
            // removing elements from sum from first index
            sum -= a[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        // adding elements to find desired sum subarray
        if (right < n)
        {
            sum += a[right];
        }
    }
    return maxLen;
}
int main()
{
    int n; // size of array
    // taking array size from user
    cout << "Enter array size: ";
    cin >> n;
    // constructing array with size n
    int arr[n];
    // inserting elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "input array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int k; // sum
    cout << "Enter sum of the subarray: ";
    cin >> k;
    // cout << "length of longest subarray with sum " << k << " is : " << longestSubArrayWithSumKBrute(arr, n, k) << endl;
    // cout << "length of longest subarray with sum " << k << " is : " << longestSubArrayWithSumKBrute2(arr, n, k) << endl;
    // cout << "length of longest subarray with sum " << k << " is : " << longestSubArrayWithSumKBetter(arr, n, k) << endl;
    cout << "length of longest subarray with sum " << k << " is : " << longestSubArrayWithSumKOptimal(arr, n, k) << endl;

    return 0;
}