/*
rotate an array to the left by k times.
ex: a[] = [1,2,3,4,5], k = 2
output-> a[] = [3,4,5,1,2]
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// brtue force approach
void rotateArrayToLeftByKtimes(int arr[], int n, int k)
{
    // make sure k is alway less or equan than size of an array
    // ex: if array size is 5 and k = 12,
    // means k = k%n = 12% 5 = 2. so we need to shift 2 elements to the left.
    k = k % n;
    // 1. take a temporary array of size k
    // it will contain first k elements those are need to be shifted
    int temp[k];
    // copying first k elements to the temp array
    for (int i = 0; i < k; i++) // O(k)
    {
        temp[i] = arr[i];
    }
    // 2. shifting the remaining elements to the left side.
    for (int i = 0; i < n - k; i++) // O(n-k)
    {
        arr[i] = arr[i + k];
    }
    // 3. now copying the first k elements, i.e. temp array elements
    // to the right side of the given array.
    for (int i = 0; i < k; i++) // O(k)
    {
        arr[n - k + i] = temp[i];
    }
}
// T:O(k) + O(n-k) + O(k) = O(n-k+k+k) = O(n+k)
// S:O(k), for temp array

// function to reverse array elements within two indexes
void reverseArray(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
// optimal approach:
// lets try to avoid the extra space used in the previous algo.
// 1. first reverse first k elements of the array
// a[] = [1,2,3,4,5], after reversing -> a[] = [2,1,3,4,5]
// 2. then reverse remaing elements starting from kth index to last index
// a[] = [2,1,3,4,5] -----> a[] = [2,1,5,4,3]
// 3. now reverse the whole array from first to last
// a[] = [2,1,5,4,3] ------> a[] = [3,4,5,1,2]

void rotateArrayToLeftByKtimesOptimal(int arr[], int n, int k)
{
    k = k % n;
    // 1. first reverse first k elements of the array
    reverseArray(arr, 0, k - 1); // O(k)
    // 2. then reverse remaing elements starting from kth index to last index
    reverseArray(arr, k, n - 1); // O(n-k)
    // 3. now reverse the whole array from first to last
    reverseArray(arr, 0, n - 1); // (n)
}
// T: = O(k)+O(n-k) + O(n) = O(2n)
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
    int k;
    cout << "enter how many elemenst have to be left shifted: ";
    cin >> k;
    // rotateArrayToLeftByKtimes(arr, n, k);
    rotateArrayToLeftByKtimesOptimal(arr, n, k);
    cout << "array after rotation: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}