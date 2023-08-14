/*
you are given an array and any number k. find the length of the longest sub-array
whose sum is equal to k.
ex: k = -7, a[] = {1,2,3,-10,1,1}
output = 4

*/
#include <bits/stdc++.h>
using namespace std;

// brute force solution
int longestSubArrayWithSumKBrute(int a[], int n, int k)
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
int longestSubArrayWithSumKOptimal(int arr[], int n, int k)
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
    cout << "length of longest subarray with sum " << k << " is : " << longestSubArrayWithSumKBrute(arr, n, k) << endl;

    cout << "length of longest subarray with sum " << k << " is : " << longestSubArrayWithSumKOptimal(arr, n, k) << endl;

    return 0;
}