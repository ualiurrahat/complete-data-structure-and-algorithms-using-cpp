/*
you are given an array where each element is appeared twice except one.
Find the element that appears only once.
ex: a[] = {1,1,2,2,3,4,4,5,5}
output = 3
*/

#include <bits/stdc++.h>
using namespace std;

// brute force approach
int findSingleElementBrute(int arr[], int n)
{
    // loop for selecting an element
    for (int i = 0; i < n; i++)
    {
        int num = arr[i]; // selected element
        int count = 1;
        // linear search to find occurrence of the selected element
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num && j != i)
            {
                count++;
            }
        }
        // if the occurrence is 1, return answer
        if (count == 1)
        {
            return num;
        }
    }
    // this line will never execute if the array contains a single element
    return -1;
}
// T:O(n), S:O(1)

// better approach 1: using hash array
// Note: this is not applicable if array contains negative or very large numbers
int findSingleElementBetterOne(int arr[], int n)
{
    // find the maximum element
    int maxi = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxi = max(arr[i], maxi);
    }
    // declare hash array of size maxi + 1
    int hash[maxi + 1] = {0};
    // hash the given array
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // find the single element and return the answer
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
        {
            return arr[i];
        }
    }
    // this line will never execute if the array contains a single element
    return -1;
}
// T:O(n) + O(n) + O(n)
// S: (max element + 1) for hash array

// better approach 2 : use map
int findSingleElementBetterTwo(int arr[], int n)
{
    // take a map for hashing
    map<int, int> hash;
    // now hash the given array
    for (int i = 0; i < n; i++) // O(n)
    {
        hash[arr[i]]++; // logM, here, M = size of map, total = T(n*logm)
    }
    // find the single element and return the ans.
    for (auto it : hash) // O(m), m = map size
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    // this line will never execute if the array contains a single element
    return -1;
}
// T:O(NlogM) + O(M), N = array size, M = map size
//  S:O(M), since every element appears twice except one element, so M = (N/2) + 1 here.

// optimal approach: using XOR property
// for any number n: 1) n ^ 0 = n 2) n ^ n = 0
int findSingleElementOptimal(int arr[], int n)
{
    int xorr = 0;
    // xor all the element
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}
// T:O(N), S:O(1)

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
    // cout << "sigle element in the array is: " << findSingleElementBrute(arr, n) << endl;
    // cout << "sigle element in the array is: " << findSingleElementBetterOne(arr, n) << endl;
    // cout << "sigle element in the array is: " << findSingleElementBetterTwo(arr, n) << endl;
    cout << "sigle element in the array is: " << findSingleElementOptimal(arr, n) << endl;
    return 0;
}