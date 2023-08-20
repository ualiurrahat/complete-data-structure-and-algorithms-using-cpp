/*The Dutch National Flag i.e. DNF sort is used to
sort an array containing 0,1,and 2 only
......................
intuition behind DNF sort:
we take 3 pointers-->low,mid,high
index [0,......,low-1] --> contains 0 (extreme left part of the array)
index [low,......, mid-1] --> contains 1
index[high+1,......., n-1] --> contains 2 (extreme right part)
these are the sorted part of the array.
index[mid,.....,high] --> contains unsorted elements means 0,1,2.
this is the unsorted part of the array..
we need to place these numbers in the sorted places.
we will take pointer low = 0, mid = 0 and high = n-1.
then start the iteration with the mid index element:
1)if a[mid] == 0,
 swap(a[low], a[mid]), mid++,low++
 since 0 resides in the regin a[0,...low-1]
 low is increased, since total sorted no. of 0 is increased by 1.
 mid is increased, to go and check the next element.
2)if a[mid] == 1,then we do nothing but mid++.
since a[low-1,....mid-1] contains all 1,
that is why a[mid]=1 is already in the right position
so going to the next element doing mid++.
3) if a[mid] == 2,
swap(a[mid], a[high]),high--,mid++
since 2 resides in the a[high+1,.....n-1]
so there is a new 2 arrives here.
assigned it in the place a[high]
since total no. of sorted 2 is increased by 1
if any other 2 comes during iteration,
we need place it infront of the current 2
hence high is decreased doing high--;
the whole iteration will continue while(mid <= high)
*/

#include <iostream>
using namespace std;

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
// T:O(N),S:O(1)
int main()
{
    int arr[] = {0, 1, 1, 1, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    DNFSort(arr, n);
    cout << "array after sorting with DNF algo: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}