/*Given an array of integers ‘ARR’ and an integer ‘X’, you are supposed to find the number of subarrays of 'ARR' which have bitwise XOR of the elements equal to 'X'.

Note:
An array ‘B’ is a subarray of an array ‘A’ if ‘B’ that can be obtained by deletion of, several elements(possibly none) from the start of ‘A’ and several elements(possibly none) from the end of ‘A’.
*/
#include <bits/stdc++.h>
using namespace std;

// brute force solution
int subarraysXorBrute(vector<int> &arr, int x)
{
    // array size
    int n = arr.size();
    // total no. of desired subarray
    int count = 0;
    // stpe 1: generate all the subarrays
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // step 2:calculate xor for current subarray
            int xorValue = 0;
            for (int k = i; k <= j; k++)
            {
                xorValue = xorValue ^ arr[k];
            }
            // step 3: check if xor value is given value
            if (xorValue == x)
            {
                // update count of sub arrays
                count++;
            }
        }
    }
    return count;
    // T:O(N^3)
    // S:O(1)
}
// better solution
int subarraysXorBetter(vector<int> &arr, int x)
{
    // array size
    int n = arr.size();
    // total no. of desired subarray
    int count = 0;
    // stpe 1: generate all the subarrays
    for (int i = 0; i < n; i++)
    {
        int xorValue = 0;
        for (int j = i; j < n; j++)
        {
            xorValue = xorValue ^ arr[j];
            if (xorValue == x)
            {
                count++;
            }
        }
    }
    return count;
    // T:O(N^2), S:O(1)
}
// optimal approach
int subarraysXorOptimal(vector<int> &arr, int x)
{
    // size of array
    int n = arr.size();
    // declaring the map
    map<int, int> mpp;
    int xr = 0;
    // setting the value of 0
    mpp[xr]++; // {0,1}
    // total no. of subarrays
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // prefix XOR till index i
        xr = xr ^ arr[i];
        // by formula, k = xr ^ x;
        int k = xr ^ x;
        // add the occurrences of xr ^ k
        // to the count
        count = count + mpp[k];
        // update the xr occurrences in the map
        mpp[xr]++;
    }
    return count;
    // T:O(N*logN)
    //  S:O(N), for map
}
int main()
{
    vector<int> v = {4, 2, 2, 6, 4};
    // given xor value
    int k = 6;
    // int count = subarraysXorBrute(v, k);
    // int count = subarraysXorBetter(v, k);
    int count = subarraysXorOptimal(v, k);
    cout << count << endl;

    return 0;
}