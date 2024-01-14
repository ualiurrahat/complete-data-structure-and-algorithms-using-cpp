/*
you are given an array of n size(even number) with
equal number of +ve and -ve numbers.
you must return an array with alternative
+ve and -ve numbers.
*/

#include <bits/stdc++.h>
using namespace std;

// brute force
vector<int> alternateNumbersBrute(vector<int> &a)
{

    int n = a.size();
    // arrays to store positive and negative numbers respectively
    vector<int> pos;
    vector<int> neg;
    // traverse the array
    for (int i = 0; i < n; i++)
    {
        // store +ve elements in pos array
        if (a[i] >= 0)
        {
            pos.push_back(a[i]);
        }
        // store -ve elements in neg array
        else
        {
            neg.push_back(a[i]);
        }
    }
    // pos,neg both have n/2 number of elements.
    // loop to rearrange elements in alternative order
    for (int i = 0; i < n / 2; i++)
    {
        // storing +ve nums to even index.
        a[2 * i] = pos[i];
        // storing -ve nums to odd index
        a[2 * i + 1] = neg[i];
    }
    return a;
}
// T:O(N) + O(N/2) = O(3N/2)
// S:O(N/2) + O(N/2) = O(N)

// optimal approach:traverse the array once and reduce time.
vector<int> alternateNumbersOptimal(vector<int> &a)
{

    int n = a.size();
    // +ve numbers in even indexes
    // -ve numbers in odd indexes
    int posIndex = 0, negIndex = 1;
    // to store rearranged elements
    vector<int> ans(n, 0);
    // traverse the array
    for (int i = 0; i < n; i++)
    {
        // store +ve elements in pos array
        if (a[i] >= 0)
        {
            ans[posIndex] = a[i];
            posIndex += 2;
        }
        // store -ve elements in neg array
        else
        {
            ans[negIndex] = a[i];
            negIndex += 2;
        }
    }

    return ans;
}
int main()
{
    // size of array
    int n;
    cout << "Enter array size: ";
    cin >> n;
    // creating n size vector
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // arr = alternateNumbersBrute(arr);
    arr = alternateNumbersOptimal(arr);
    cout << "Array after alternating elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}