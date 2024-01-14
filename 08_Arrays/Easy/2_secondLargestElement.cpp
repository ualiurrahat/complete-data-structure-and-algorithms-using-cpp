#include <bits/stdc++.h>
using namespace std;

// brute force approach
// T:O(nlogn) + O(n) = O(nlogn)
int secondLargestBrute(vector<int> &a, int n)
{
    // to store the second largest element
    // initial value -1, in case second largest does not exist in the array
    int ans = -1;
    // sort the array: O(nlogn)
    sort(a.begin(), a.end());
    // now traverse the sorted array in reverse order
    // return the second largest element
    int largest = a[n - 1];
    // O(n)
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < largest)
        {
            ans = a[i];
            break;
        }
    }
    return ans;
}

// better approach
// T:O(N) + O(N) = O(N+N) = O(2N)
int secondLargestBetter(vector<int> &a, int n)
{
    // take -1 as initial answer if all given inputs are +ve,
    // or INT_MIN for +ve,-ve numbers as input
    int secondLargest = INT_MIN;
    // first parse: find the largest element: O(n)
    int largest = a[0];
    for (int i = 1; i < n; i++)
    {
        if (largest < a[i])
        {
            largest = a[i];
        }
    }
    // second parse: find second largest now.
    // O(n)
    for (int i = 0; i < n; i++)
    {
        if (a[i] > secondLargest && a[i] < largest)
        {
            secondLargest = a[i];
        }
    }
    return secondLargest;
}
// optimal approach
// T:O(N)
int secondLargestBest(vector<int> &a, int n)
{
    int largest = a[0];
    // take -1 as initial answer if all given inputs are +ve,
    // or INT_MIN for +ve,-ve numbers as input
    int secondLargest = INT_MIN;
    // traverse the array
    for (int i = 1; i < n; i++)
    {
        // if a[i] > largest, set secondLargest to largest
        // update largest to a[i]
        if (a[i] > largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        // a[i] > secondLargest but not than largest,
        // update the secondLargest
        else if (a[i] < largest && a[i] > secondLargest)
        {
            secondLargest = a[i];
        }
    }
    return secondLargest;
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

    // cout << "second largest element is: " << secondLargestBrute(arr, n);
    // cout << "second largest element is: " << secondLargestBetter(arr, n);
    cout << "second largest element is: " << secondLargestBest(arr, n);

    return 0;
}