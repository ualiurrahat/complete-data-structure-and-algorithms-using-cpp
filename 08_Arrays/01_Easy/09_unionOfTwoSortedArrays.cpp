/*
Given two sorted arrays with multiple occurrences of each number,
find the union of these arrays containing each element just once.

Example:
a[] = [1,1,2,3,4,5], b[] = [1,2,2,4,5,6]
Output: [1,2,3,4,5,6]

Note:
- Union contains **distinct elements** from both arrays.
- Both arrays are sorted, which allows us to use two-pointer technique for optimal solution.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// ---------------------- Brute Force Approach ----------------------

/**
 * @brief Brute force approach to find union of two sorted arrays
 *
 * 1. Take a set and insert all elements of the two arrays.
 *    - Set automatically removes duplicates and keeps elements sorted.
 * 2. Copy all elements of the set into a vector.
 *
 * @param a First sorted array
 * @param b Second sorted array
 * @return vector<int> Sorted union of both arrays with distinct elements
 */
vector<int> unionOfArraysBrute(vector<int> &a, vector<int> &b)
{
    // take a set
    set<int> s; // S: O(n1+n2)
    // take a vector to save output
    vector<int> ans; // S: O(n1+n2)
    // 1. copy all elements of a to set
    for (auto num : a) // O(n1*log n1)
    {
        s.insert(num); // T: O(log n) per insertion
    }
    // 2. copy all elements of b to set
    for (auto num : b) // O(n2*log n2)
    {
        s.insert(num); // T: O(log n) per insertion
    }
    // 3. copy all elements of set to ans vector
    for (auto num : s)
    {
        ans.push_back(num); // O(n1+n2)
    }
    // return output
    return ans;
}

/*
Time Complexity: O(n1*log n1 + n2*log n2) due to set insertion
Space Complexity: O(n1+n2) for set and output vector
Note: Slower for large arrays because of log(n) overhead in set insertions
*/

// ---------------------- Optimal Approach ----------------------

/**
 * @brief Optimal approach to find union of two sorted arrays using two pointers
 *
 * 1. Use two pointers i, j for arrays a and b respectively.
 * 2. Compare a[i] and b[j], insert the smaller (or equal) into ans if not duplicate.
 * 3. Move the pointer of the element inserted.
 * 4. After one array is exhausted, copy remaining elements of the other array avoiding duplicates.
 *
 * @param a First sorted array
 * @param b Second sorted array
 * @return vector<int> Sorted union of both arrays with distinct elements
 */
vector<int> unionOfArraysOptimal(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> ans; // output vector

    // traversing both arrays and comparing elements
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            // only push a[i] if ans is empty or last element is not equal to a[i]
            if (ans.size() == 0 || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else
        {
            // only push b[j] if ans is empty or last element is not equal to b[j]
            if (ans.size() == 0 || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    // if array a is exhausted but b still has elements
    while (j < n2)
    {
        if (ans.size() == 0 || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }

    // if array b is exhausted but a still has elements
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

/*
Time Complexity: O(n1+n2) as each element is visited only once
Space Complexity: O(n1+n2) for output vector
Note: Faster than brute force because it avoids set insertion overhead
*/

// ---------------------- Main Function ----------------------

int main()
{
    // example arrays
    vector<int> a = {1, 1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 4, 5, 6, 6, 7};

    // calling brute force solution
    // vector<int> ans = unionOfArraysBrute(a, b);

    // calling optimal solution
    vector<int> ans = unionOfArraysOptimal(a, b);

    // print the union array
    cout << "Union of the two arrays: ";
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
