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
// better solution
vector<vector<int>> tripletBetter(int n, vector<int> &arr)
{
    // to store unique triplets.
    // this is a set collection of triplets
    set<vector<int>> st;

    // loop to find triplets whose sum will be 0
    for (int i = 0; i < n; i++)
    {
        // take a set to insert all numbers
        // between i and j, for each time i is running
        // third number from triplets will be in this set.
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            // third number to construct unique triplets
            int third = -(arr[i] + arr[j]);
            // check if third number exists in the hashset
            if (hashset.find(third) != hashset.end())
            {
                // unique triplets found
                // store them in a vector
                vector<int> temp = {arr[i], arr[j], third};
                // sort the triplets
                sort(temp.begin(), temp.end());
                // store them in the set of triplets
                st.insert(temp);
            }
            // insert current num in the hashset
            hashset.insert(arr[j]);
        }
    }
    // now store all the triplets from the set
    // to a vector of vectors
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

    /*
        T: O(n^2)*O(log * size of array)
        second part is for storing array elements in the hashset.
        it's size varies with each time i is running.
        so, T:O(n^2*logM);

        S:O(N), for hashset + O(no. of triplets) for set of triplets.

    */
}
// optimal solution
vector<vector<int>> tripletOptimal(int n, vector<int> &arr)
{
    // to store answer
    vector<vector<int>> ans;
    // sort the given array
    sort(arr.begin(), arr.end());

    // traverse the entire array
    for (int i = 0; i < n; i++)
    {
        // move i further as long as
        // duplicate element is encountred
        // check from index 1 as first element
        // can not have any previous element
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
            // so, this will not run the code below
            // this will just increase the value of i
            // then start running the loop from the first
        }
        // two pointers to track remaining two numbers
        // to form triplets
        int j = i + 1; // next element of i
        int k = n - 1; // the last element of the array
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                // we found the triplets
                vector<int> temp = {arr[i], arr[j], arr[k]};
                // store them in the answer
                ans.push_back(temp);

                // now update the pointers
                j++;
                k--;
                // update pointers as long as
                // they encounter duplicate values
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
                while (j < k && arr[j] == arr[j + 1])
                {
                    j++;
                }
            }
        }
    }
    return ans;
    // T:O(nlogn) for sorting + O(n[for loop] * n[while loop])
    // T:O(nlogn) + O(n^2)
    // S:O(no. of triplets)
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    // vector<vector<int>> ans = tripletBrute(n, arr);
    // vector<vector<int>> ans = tripletBetter(n, arr);
    vector<vector<int>> ans = tripletOptimal(n, arr);
    cout << "triplets are: " << endl;
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}