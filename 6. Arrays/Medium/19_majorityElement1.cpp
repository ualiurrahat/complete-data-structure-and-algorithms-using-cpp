/*You are given an array with n elements. find the element which appears
more than n/2 times. Consider array always has a majority element.
ex: a[] = {1,2,3,1,1,1,1,5}, n = 8
output = 1(1 appears 5 times which is more than n/2 = 8/2 = 4)
*/

#include <bits/stdc++.h>
using namespace std;

// brute force :
// traverse the whole array. count frequency of each number.
// if any number's frequency is greater than n/2, return the number
int majorityElementBrute(int arr[], int n)
{
    // outer loop to count frequency of all elements.
    for (int i = 0; i < n; i++)
    {
        // to store frequency
        int count = 0;
        // inner loop to count frequency of arr[i]
        for (int j = 0; j < n; j++)
        {
            // got arr[i] in the inner loop
            if (arr[i] == arr[j])
            {
                // update frequency
                count++;
            }
        }
        // if count is more than n/2, then arr[i] is
        // the majority element. check and return it
        if (count > n / 2)
        {
            return arr[i];
        }
    }
    // this line never gets executed if array always has a majority element.
}
// T:O(N^2)

// better approach: using hashing
// count frequency of each elements in the hashmap
// return the element whose frequency > (n/2)
int majorityElementBetter(int arr[], int n)
{
    // take a hashmap to store elements and its frequency
    map<int, int> mpp;
    // iterate array and insert them in the map
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    // iterate the map
    for (auto it : mpp)
    {
        // check if frequency > n/2
        if (it.second > n / 2)
        {
            // return the element
            return it.first;
        }
    }
    // this line is never executed if array
    // always contains a majority element
    return -1;
}
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
    // printing given array
    cout << "The given array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // cout << "majority element in the array is: " << majorityElementBrute(arr, n) << endl;
    cout << "majority element in the array is: " << majorityElementBetter(arr, n) << endl;

    return 0;
}