/*There is an integer array ‘a’ of size ‘n’.
An element is called a Superior Element if it is greater than all the elements present to its right.
You must return an array all Superior Elements in the array ‘a’.
Note:
The last element of the array is always a Superior Element.
Example
Input: a = [1, 2, 3, 2], n = 4
Output: 2 3
Explanation:
a[ 2 ] = 3 is greater than a[ 3 ]. Hence it is a Superior Element.
a[ 3 ] = 2 is the last element. Hence it is a Superior Element.
The final answer is in sorted order.
*/
#include <bits/stdc++.h>

using namespace std;

// brute force solution to fine leaders in an array
vector<int> superiorElementsBrute(vector<int> &a)
{
    vector<int> leaders;
    int n = a.size();
    // traverse the array and consider each element
    for (int i = n - 2; i >= 0; i--)
    {
        // assume the current element a[i] as a leader
        bool flag = true;
        // loop to traverse the entire right side elements
        // from the current a[i]
        for (int j = i + 1; j < n; j++)
        {
            // if any right side element is
            // equal or greater than a[i], it is not a leader
            if (a[j] >= a[i])
            {
                // updating flag and breaking the loop
                flag = false;
                break;
            }
        }
        // if flag is true, means a[i] is a leader
        if (flag)
        {
            // inserting a[i] in the leaders array
            leaders.push_back(a[i]);
            ;
        }
    }
    // the most right element of array is always a leader
    leaders.push_back(a[n - 1]);
    // sorting the leader array
    sort(leaders.begin(), leaders.end());
    // returning the answer
    return leaders;
    // T: O(n^2) + O(nlogn)
    // S:O(n), for leader array
}
// optimal solution
vector<int> superiorElementsOptimal(vector<int> &a)
{
    // to track the max element among
    // all elements positioned at right side
    // of the current element.
    int maxi = INT_MIN;
    // to store answer.
    vector<int> ans;
    // size of given array.
    int n = a.size();
    // taverse the array from the end of the array
    for (int i = n - 1; i >= 0; i--)
    {
        // if current element is greater than maxi
        // then it is a leader.
        if (a[i] > maxi)
        {
            // update maxi
            maxi = a[i];
            // insert a[i] to the leader array
            ans.push_back(a[i]);
        }
    }
    // sort the leaders
    sort(ans.begin(), ans.end());
    return ans;
    // T:O(n) + O(nlogn)
    //  S:O(n), for returning leader array.
}
int main()
{
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
    vector<int> ans = superiorElementsOptimal(arr);
    cout << "leader elements are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}