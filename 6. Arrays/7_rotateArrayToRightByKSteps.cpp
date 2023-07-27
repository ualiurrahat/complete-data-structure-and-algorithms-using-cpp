/*
rotate an array to the right by k times.
ex: a[] = [1,2,3,4,5,6,7], k = 3
output-> a[] = [5,6,7,1,2,3,4]
*/
#include <iostream>
using namespace std;

// brute force approach
// function takes 3 parameters: an array, its size n, an integer k
void rotateArrayToRightKtimes(int arr[], int n, int k)
{
    // rechecking value of k
    k = k % n;
    // take a temporary array to store non-rotating elements
    int temp[n - k];
    // storing first n-k elements of arr in the temp array
    for (int i = 0; i < n - k; i++)
    {
        temp[i] = arr[i];
    }
    // right shifting remaining arr elements
    for (int i = 0; i < k; i++)
    {
        arr[i] = arr[n - k + i];
    }
    // copying temp elements in arr
    for (int i = k; i < n; i++)
    {
        arr[i] = temp[i - k];
    }
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
    int k;
    cout << "enter how many elemenst have to be right shifted: ";
    cin >> k;
    // rotateArrayToLeftByKtimes(arr, n, k);
    rotateArrayToRightKtimes(arr, n, k);
    cout << "array after rotation: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}