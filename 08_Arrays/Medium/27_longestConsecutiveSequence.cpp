/*There is an integer array ‘A’ of size ‘N’.
A sequence is successive when the adjacent elements of the sequence have a difference of 1.
You must return the length of the longest successive sequence.
Note:
You can reorder the array to form a sequence.
For example,
Input:
A = [5, 8, 3, 2, 1, 4], N = 6
Output:
5
Explanation:
The resultant sequence can be 1, 2, 3, 4, 5.
The length of the sequence is 5.*/
#include <bits/stdc++.h>
using namespace std;

// function to perform linear search
bool linearSearch(vector<int> &arr, int num)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}
// brute force solution to find longest consecutive elements
int longestSuccessiveElementsBrute(vector<int> &a)
{
    int n = a.size();
    int longest = 1;
    // step 1: loop to iterater through the given array
    for (int i = 0; i < n; i++)
    {
        // consider consecutive elements for each element
        // initially it will be 1.
        int count = 1;
        int x = a[i];
        // step 2: loop to find final consecutive element for element x

        while (linearSearch(a, x + 1) == true)
        {
            // 2.1: if we find x+1,x+2,.. through linear search
            // increasing count, and updating x by x+1
            // for searching existence of  censecutive elements.
            count++;
            x = x + 1;
        }
        // 2.2: found final consecutive element length for x
        // check if it is greater than the current longest value
        // then update it.
        longest = max(longest, count);
    }
    return longest;
    // T:O(n^2)
    // S:O(1)
}
// better solution
int longestSuccessiveElementsBetter(vector<int> &a)
{
    // to store length of longest consecutive sequence.
    int longest = 1;
    // to count length of the current sequence.
    int currentCount = 0;
    // to track the smallest element of the current sequence.
    int lastSmaller = INT_MIN;
    // step 1: sort the array
    sort(a.begin(), a.end());

    // step 2: traverse the array
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        // case 1: if a[i] is a consecutive element
        if (a[i] - 1 == lastSmaller)
        {
            // increase current length by 1
            currentCount++;
            // update last smaller element to the current element
            lastSmaller = a[i];
        }
        // case 2: a[i] is not a consecutive one.
        else if (a[i] != lastSmaller)
        {
            // this is a new sequence.
            // so start counting current length from 1
            currentCount = 1;
            // current element is the smallest one in this consecutive series
            lastSmaller = a[i];
        }
        // update longest
        longest = max(longest, currentCount);
    }
    return longest;
    // T:O(nlogn) + O(n)
    // S:O(1)
}
int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    vector<int> arr(size);
    cout << "enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    // int ans = longestSuccessiveElementsBrute(arr);
    int ans = longestSuccessiveElementsBetter(arr);
    cout << "longest sucessive elements length: " << ans << endl;

    return 0;
}