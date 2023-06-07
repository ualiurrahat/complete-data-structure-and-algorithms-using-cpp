// find the largest element in array
// a[] = {18,1,8,5,20,13}
// output = 20
#include <bits/stdc++.h>
using namespace std;

// brute force solution
// T:O(NlogN)
// S:O(1)
int findLargestElement(vector<int> &a, int n)
{
    // sort the array first
    sort(a.begin(), a.end());
    // return the last element
    return a[a.size() - 1];
}

// optimal solution
// T:O(N), S:O(1)
int findLargestElementOptimal(vector<int> &a, int n)
{
    // take first element as the largest one
    int largest = a[0];
    // traverse the whole array
    for (int i = 1; i < n; i++)
    {
        // compare each element with largest
        // if current element is greater than largest,
        // update the largest
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }
    return largest;
}
int main()
{

    int n;
    cout << "Enter total no. of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "largest element is: " << findLargestElement(arr, n) << endl;
    cout << "largest element is: " << findLargestElementOptimal(arr, n) << endl;

    return 0;
}