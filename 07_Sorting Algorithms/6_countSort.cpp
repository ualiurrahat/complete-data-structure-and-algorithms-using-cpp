/*
count sort is used when all input elements are +ve numbers.
it sorts elements based on their total frequency in the array
*/

#include <bits/stdc++.h>
using namespace std;

// funciton to perform count sort
void countSort(int a[], int n)
{
    // 1. find the max element
    int maxi = 0;
    for(int i = 0; i < n; i++)
    {
        maxi = max(maxi,a[i]);
    }
    // 2. take an array with size maxi+1
    // this array will save frequency of each elements
    int count[maxi+1];
    // 3. initialize all indexes of count with 0
    for(int i = 0; i < maxi+1; i++)
    {
        count[i] = 0;
    }
    // 4. store index-based frequency of each numbers in the count array
    for(int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    // 5. now sort given array based on their frquency
    for(int i = 0, j = 0; i < maxi+1; i++)
    {
        // if i does not exist in the a array, continue
        if(count[i] == 0)
        {
            continue;
        }
        else
        // i exists in a.
        // insert i in a
        // increase index j
        // reduce frequency of i in count array
        {
            a[j] = i;
            j++;
            count[i]--;
        }
    }
}
int main()
{
    
     int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    cout << "Enter array elements (+ve numbers only): ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Given array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    countSort(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}