/*
write a function to check if an array is sorted in non-decreasing order
return 1 if array is sorted,else 0
ex: a[] = [18,1,8,5,20]
output = 0
b[] = [1,5,7,9,11]
output = 1
*/
#include <iostream>
using namespace std;

// funciton to check if array is sorted in non-decreasing order
// funciton takes two parameters: an array and its size
int isArraySorted(int arr[], int n)
{
    // traversing array from first element to before last element
    for (int i = 0; i < n - 1; i++)
    {
        // for non-decreasing order, (i+1)th element has to be
        // greater than or equal to ith element
        if (arr[i + 1] >= arr[i])
        {
            // sorting condition fulfilled
            // go to next element
            continue;
        }
        else
        {
            // condition not fulfilled. array not sorted.
            return 0;
        }
    }
    // all elements are in sorted order. return 1
    return 1;
}
int main()
{

    int n;
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
    cout << isArraySorted(arr, n) << endl;
    return 0;
}