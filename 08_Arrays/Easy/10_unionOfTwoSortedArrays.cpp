/*
given two sorted arrays with multiple existing of each numbers,
find the union of these array containing each element just one time
ex: a[] = [1,1,2,3,4,5], b[] = [1,2,2,4,5,6]
output[] = [1,2,3,4,5,6]
*/

#include <bits/stdc++.h>
using namespace std;

// brute force approach
// 1. take a set and insert all elements of two given arrays
//  set saves those numbers in sorted fashion
// 2. now take an array and put all elements of set to it.
// this is the output
vector<int> unionOfArraysBrute(vector<int> &a, vector<int> &b)
{
    // take a set
    set<int> s; // S: O(n)
    // take a vector to save output
    vector<int> ans; // S: O(n)
    // 1.copy all elements of a and b to the set
    for (auto num : a) // O(n1*logn)
    {
        s.insert(num); // T:O(logn for each insertion)
    }
    for (auto num : b) // O(n2)
    {
        s.insert(num); // T:O(logn for each insertion)
    }
    // 2. copy all set elements to the ans vector
    for (auto num : s)
    {
        ans.push_back(num); // O(n1+n2)
    }
    // return output
    return ans;
}
// T:O(n1logn1 + n2logn2) + O(n1+n2) == O(size of a + size of b)
// S:O(size of set + size of output vector) = O(n+n) = O(2n)

// optimal approach
vector<int> unionOfArraysOptimal(vector<int> &a, vector<int> &b)
{
    // Write your code here
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> ans;
    // traversing both array and comparing elements
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            // only push a[i], when ans array is either empty
            // or its last element is not equal to a[i]
            if (ans.size() == 0 || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else
        {
            // only push b[i], when ans array is either empty
            // or its last element is not equal to b[i]
            if (ans.size() == 0 || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    // in case array a got exhausted but b still has elements
    while (j < n2)
    {
        if (ans.size() == 0 || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }
    // in case array b got exhausted but a still has elements
    while (i < n1)
    {
        if (ans.size() == 0 || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }
    return ans;
}
// T:O(n1+n2)
// S:O(n)
int main()
{
    vector<int> a = {1, 1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 4, 5, 6, 6, 7};
    // vector<int> ans = unionOfArraysBrute(a, b);
    vector<int> ans = unionOfArraysOptimal(a, b);
    for (auto num : ans)
    {
        cout << num << " ";
    }

    return 0;
}