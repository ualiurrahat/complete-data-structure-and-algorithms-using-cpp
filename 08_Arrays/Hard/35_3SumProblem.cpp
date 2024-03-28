/*You are given an array ‘ARR’ containing ‘N’ integers.
Return all the unique triplets [ARR[i], ARR[j], ARR[k]] such that i != j, j != k and k != i and their sum is equal to zero.
Example:
Input: ‘N’ = 5
'ARR' =  [-1, -1, 2, 0, 1]
Output:
-1 -1 2
-1 0 1

Explanation:
(-1 -1 +2) = (-1 +0 +1) = 0.*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// brute force solution
vector<vector<int>> tripletBrute(int n, vector<int> &arr)
{
    // to store unique triplets
    set<vector<int>> st;

    // loop to find triplets whose sum will be 0
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                // condition for the desired triplets
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    // temporary array to contain these triplets
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    // sort the triplets
                    sort(temp.begin(), temp.end());
                    // insert triplets in the set
                    // the triplets will be inserted only if
                    // they are unique. means they are not
                    // already exist in the set
                    st.insert(temp);
                }
            }
        }
    }
    // now store all the triplets from the set
    // to a vector of vectors
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

    // T:O(3n)-- 3 for loop + O(log* no. of unique triplets) for insertion in set
    // we are not considering the sorting here, as only 3 elements are sorted.
    // T:O(3n + O(log * no. of unique tripltets))
    // S:O(2* no. of unique triplets) [1 for set, 1 for vectors of vectors]
}
int main()
{
    // -1 0 1 2 -1 4
    vector<int> arr;
    int n;
    cout << "Enter array size: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<vector<int>> ans = tripletBrute(n, arr);

    cout << "Desired triplets: " << endl;
    for (auto vec : ans)
    {
        for (auto num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}