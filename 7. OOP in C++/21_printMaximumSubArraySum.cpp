/*
in previous problem, we found the maximum subarray sum
for a given array. Now in this problem, we need to
print the subarry that has the maximum sub
ex: a[] = {-2,-3,4,-1,-2,1,5,-3}
ans = {4,-1,-2,1,5}
*/

#include <bits/stdc++.h>
using namespace std;

// optimal solution: using Kadane's alogrithm
void printMaximumSubArraySum(int arr[], int n)
{
    // initially taking lowest int as the maximum subarray sum
    int maxSum = INT_MIN;
    // to store sum of the current subarray
    int currSum = 0;
    // starting and ending index for max subarray sum
    int ansStart = -1;
    int ansEnd = -1;
    // to point out starting position
    // of max subarray sum
    int start;
    // loop to traverse whole array
    for (int i = 0; i < n; i++)
    {
        // subarray will start when currSum is 0
        if (currSum == 0)
        {
            start = i;
        }
        currSum += arr[i];
        // compare maxSum with currSum and update
        if (currSum > maxSum)
        {
            maxSum = currSum;
            ansStart = start;
            ansEnd = i;
        }

        // if currSum is negative, reassign value zero
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    // now printing the maximum subarray sum
    cout << "Printing the maximum subarray sum portion:" << endl;
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    cout << endl;
    // printing maximum sub array sum
    printMaximumSubArraySum(arr, n);

    return 0;
}