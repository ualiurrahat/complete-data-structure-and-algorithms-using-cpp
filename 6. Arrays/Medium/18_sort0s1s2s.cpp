/*An array containing only 0,1 and 2. sort them.
This problem also famously known as Dutch National Flag Problem
 */
#include <iostream>
using namespace std;

// brute force: using merge sort
void merge(int arr[], int low, int mid, int high)
{

    int i = low;
    int j = mid + 1;
    int k = low;
    // take an array to store elements in sorted order
    int b[high + 1];
    // compare elements from low to mid and mid to high indexes
    //  and store them in b array
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    // in case left part is exhausted but right part has elements to sort
    if (i > mid)
    {
        while (j <= high)
        {
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    // case when right part is exhausted but left part is not
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            k++;
            i++;
        }
    }
    // now copy b array in a
    for (k = low; k <= high; k++)
    {
        arr[k] = b[k];
    }
}
// merge sort funciton
// takes an array,lowest index, and last index
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // find mid index
        int mid = low + (high - low) / 2;
        // recursive call
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        // merge sorted parts
        merge(arr, low, mid, high);
    }
}
// time complexity for brute force solution: T=O(Nlogn)
// space complexity : S=O(N) for the temporaray array

// better approach: count total no. of 0,1,2
// insert them in the array
void sortZeroOneTwoBetter(int arr[], int n)
{
    int countZeroes = 0;
    int countOnes = 0;
    int countTwos = 0;
    // count total no. of 0,1,2 in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            countZeroes++;
        else if (arr[i] == 1)
            countOnes++;
        else
            countTwos++;
    }
    // fill up 0 from index 0
    for (int i = 0; i < countZeroes; i++)
    {
        arr[i] = 0;
    }
    // fill up ones
    for (int i = countZeroes; i < countZeroes + countOnes; i++)
    {
        arr[i] = 1;
    }
    // fill up twos;
    for (int i = countZeroes + countOnes; i < countZeroes + countOnes + countTwos; i++)
    {
        arr[i] = 2;
    }
    return;
}
// T:(N+N) = O(2N), S:O(1)

// optimal approach: using DNF Sort Algorithm
// funciton to perform DNF sort
void DNFSort(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return;
}
// T:O(N), S=O(1)
int main()
{

    int arr[] = {0, 1, 1, 2, 2, 0, 2, 1, 2, 0, 0, 0, 1, 2, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // sorting array using merge sort
    // mergeSort(arr, 0, n);
    // cout << "Array after sorting using merge sort: " << endl;
    // sorting using better solution
    // sortZeroOneTwoBetter(arr, n);
    DNFSort(arr, n);
    // cout << "Array after sorting user better solution: " << endl;
    cout << "Array after sorting using DNF algorithm:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}