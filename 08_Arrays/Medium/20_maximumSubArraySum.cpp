/* for a given array, find out the maximum
sub-array sum. ex: a[] = {-2,-3,4,-1,-2,1,5,-3}
ans = 7. (the region:{4,-1,-2,1,5})
*/

#include <bits/stdc++.h>
using namespace std;

// brute force solution
int maximumSubArraySumBrute(int arr[], int n)
{
    // initially taking lowest int as the maximum subarray sum
    int maxSum = INT_MIN;
    // outer loop to traverse whole array
    for (int i = 0; i < n; i++)
    {
        // subarray:arr[i,...,j]
        for (int j = i; j < n; j++)
        {
            // sum of the current subarray
            int currSum = 0;
            // add elements in sub array
            for (int k = i; k <= j; k++)
            {
                currSum = currSum + arr[k];
            }
            // compare currSum and maxSum and update maxSum
            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}
// T:O(N^3), S:O(1)

// better solution
int maximumSubArraySumBetter(int arr[], int n)
{
    // initially taking lowest int as the maximum subarray sum
    int maxSum = INT_MIN;
    // outer loop to traverse whole array
    for (int i = 0; i < n; i++)
    {
        // sum of the current subarray
        int currSum = 0;
        // subarray:arr[i,...,j]
        for (int j = i; j < n; j++)
        {
            currSum += arr[j];
            // update maxSum
            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}
// T:O(N^2), S:O(1)

// optimal solution: using Kadane's alogrithm
int maximumSubArraySumOptimal(int arr[], int n)
{
    // initially taking lowest int as the maximum subarray sum
    int maxSum = INT_MIN;
    // to store sum of the current subarray
    int currSum = 0;
    // loop to traverse whole array
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        // update maxSum
        maxSum = max(currSum, maxSum);

        // if currSum is negative, reassign value zero
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}
// T:O(n), S:O(1)
int main()
{
    // size of array
    int n;
    cout << "Enter array size: ";
    cin >> n;
    // creating n size array
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << "maximum subarray sum :" << maximumSubArraySumBrute(arr, n) << endl;
    // cout << "maximum subarray sum :" << maximumSubArraySumBetter(arr, n) << endl;
    cout << "maximum subarray sum :" << maximumSubArraySumOptimal(arr, n) << endl;
    return 0;
}