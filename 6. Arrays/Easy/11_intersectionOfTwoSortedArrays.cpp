/*
find intersection of two sorted arrays.
ex: a[] = [1,2,2,3,3,4,5,6]
b[] =[2,3,3,5,6,7]
output = [2,3,3,5,6]
*/

#include <bits/stdc++.h>
using namespace std;

// brute force approach
// solution trick: every element in array 1 has to be its corresponden element in array 2
// 1. for each element in array 1, traverse whole array 2
// 2. take an extra visited array to check elements in array2
// 3. if one element got its correspondent in array2
//      mark this as one in visited array
//      and push it to ans array
vector<int> interSectionBrute(vector<int> &a, vector<int> &b)
{
    // size of a and b
    int n1 = a.size();
    int n2 = b.size();
    vector<int> visited(n2, 0); // S:O(n2)
    vector<int> ans;            // S:O(n1+n2)
    // traverse array a
    for (int i = 0; i < n1; i++) // O(n1)
    {
        // find correspondent element in b
        for (int j = 0; j < n2; j++) // O(n2)
        {
            if (a[i] == b[j] && visited[j] == 0)
            {
                ans.push_back(a[i]);
                visited[j] = 1;
            }
            else if (b[j] > a[i])
            {
                break;
            }
        }
    }
    return ans;
}
// T:O(n1*n2)
// S:O(n1+n2)

// optimal approach
vector<int> interSectionOptimal(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int n = a.size();
    int m = b.size();
    int i = 0;
    int j = 0;
    // traverse two arrays and compares their elements
    while (i < n && j < m)
    {
        // common number found
        if (a[i] == b[j])
        {
            // push it in the number and update both iterators
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            // since a[i] is lesser than b[j], a[i] can not exist in b
            // update iterator of a array
            i++;
        }
        else
        {
            // b[j] is lesser than a[i] already,
            // so b[j] does not exist in a array
            // update iterator of b
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> a = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> b = {2, 3, 3, 5, 6, 7};
    // vector<int> interSectionArray = interSectionBrute(a, b);
    vector<int> interSectionArray = interSectionOptimal(a, b);
    for (int i = 0; i < interSectionArray.size(); i++)
    {
        cout << interSectionArray[i] << " ";
    }
}