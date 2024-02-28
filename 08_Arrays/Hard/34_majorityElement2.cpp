/*Given an array ‘A’ of ‘N’ integers, find the majority elements of the array.
A majority element in an array ‘A’ of size ‘N’ is an element that appears more than floor(N / 3) times.
Note: The floor function returns the number rounded down to the nearest integer.
Note: Return the array of majority elements in sorted order.
Example:
Input: ‘N’ = 9 ‘A’ = [2, 2, 1, 3, 1, 1, 3, 1, 1]
Output: 1
Explanation: The frequency of ‘1’ is 5, which is greater than floor(N / 3), hence ‘1’ is the majority element.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// brute force solution
vector<int> majorityElementBrute(vector<int> &v)
{
    // size of the array
    int n = v.size();
    // list of answers
    vector<int> ls;

    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]
        // checking if v[i] as already
        // in the list or not
        if (ls.size() == 0 || ls[0] != v[i])
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                // counting frequency of v[i]
                if (v[j] == v[i])
                {
                    count++;
                }
            }
            // if frequency is greater than n/3
            // than it is a majority element
            if (count > n / 3)
            {
                ls.push_back(v[i]);
            }
        }
        // at max there can be only two elements
        // having frequency greater than n/3
        // in the given array
        if (ls.size() == 2)
        {
            break;
        }
    }
    sort(ls.begin(), ls.end());
    return ls;
    // T:O(n^2), [sorting times very little,as only 2 elements are there]
    // S:O(1), as the vector we are returning has only 2 elements
}

// better solution
vector<int> majorityElementBetter(vector<int> v)
{
    // size of the array
    int n = v.size();
    // list of answers
    vector<int> ls;
    // minimum frequency of the majority element
    int mini = int(n / 3) + 1;
    // declaring a map to store element based upon its frequency
    map<int, int> mpp;

    // storing elements in the map along its occurences
    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
        // check if v[i] is the majority element
        if (mpp[v[i]] == mini)
        {
            ls.push_back(v[i]);
        }
        // there can be only two majority
        // element in the entire array
        if (ls.size() == 2)
        {
            break;
        }
    }
    // sorting the answer
    sort(ls.begin(), ls.end());
    return ls;
    // O(n*mapTime), here ls has only 2 elements. so sotring will take only O(2log2)time,negligible.
    // for using default map: T:O(nlogn)
    // for unordered map: T:O(n)[avg case] as it takes O(1) time for map operation
    // for unordered map: T:O(n^2)[worst case] as it takes O(n) time for map operation.
}
int main()
{
    vector<int> arr = {2, 2, 1, 3, 1, 1, 3, 1, 1};
    cout << "The given array elements: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // vector<int> ans = majorityElementBrute(arr);
    vector<int> ans = majorityElementBetter(arr);
    cout << "majority elements are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}