/*
find the maximum consecutive 1's in the given array
ex: a[] ={1,1,0,1,1,1,0,1,1}
output = 3
*/

#include <bits/stdc++.h>
using namespace std;

// function to find maximum consective one in an array
// takes two parameters: an array, and its size.
int maxConsecutiveOnes(int arr[], int n)
{
    // to store answer
    int maxi = 0;
    // to store current total consecutive ones
    int current = 0;
    // iterate entire array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            current++;
            maxi = max(maxi, current);
        }
        else
        {
            current = 0;
        }
    }
    return maxi;
}
// T:O(n)
// S:O(1)
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
    cout << "maximum consecutive one: " << maxConsecutiveOnes(arr, n) << endl;
    return 0;
}