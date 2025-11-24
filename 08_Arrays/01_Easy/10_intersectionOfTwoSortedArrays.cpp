/*
---------------------------------------------------------------------------------------
Problem Statement:
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both arrays are
sorted in non-decreasing order. You must return the INTERSECTION of these two arrays.

The intersection contains all common elements that appear in both arrays (including
duplicates in the correct count). Output order must follow the original sorted order.

Notes:
1. Length of each array > 0
2. Arrays are sorted
3. Output must follow the natural order of intersection
4. If no intersection exists → return an empty array

Example:
A = [1,2,2,3,3,4,5,6]
B = [2,3,3,5,6,7]
Output = [2,3,3,5,6]

Constraints:
1 ≤ N, M ≤ 10^4
0 ≤ A[i], B[i] ≤ 10^5

---------------------------------------------------------------------------------------
Additional Explanation:
find intersection of two sorted arrays.
ex: a[] = [1,2,2,3,3,4,5,6]
    b[] = [2,3,3,5,6,7]
output = [2,3,3,5,6]
---------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// ================================================================================
//                               BRUTE FORCE APPROACH
// ================================================================================

/**
 * @brief Brute force intersection of two sorted arrays.
 *
 * Key Idea (your explanation rewritten professionally):
 * - For every element in array A, try to find its corresponding element in array B.
 * - Since duplicates may exist, we maintain a "visited" array for B to ensure that
 *   each matched element from B is used only once.
 * - Steps:
 *   1. For each element in A, traverse full array B.
 *   2. Use visited[] to ensure elements in B are not reused.
 *   3. If match found → push to ans[], mark visited[j] = 1.
 *
 * Time Complexity: O(n1 * n2)
 * Space Complexity: O(n2) for visited[] + O(n1+n2) for ans[] → O(n1+n2)
 *
 * @param a First sorted array
 * @param b Second sorted array
 * @return vector<int> Intersection result
 */
vector<int> interSectionBrute(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();

    // visited array marks elements of B that are already matched
    vector<int> visited(n2, 0); // S: O(n2)

    vector<int> ans; // S: O(n1 + n2)

    // traverse array A
    for (int i = 0; i < n1; i++) // O(n1)
    {
        // search for a[i] inside array B
        for (int j = 0; j < n2; j++) // O(n2)
        {
            // element matches AND has not been used yet
            if (a[i] == b[j] && visited[j] == 0)
            {
                ans.push_back(a[i]);
                visited[j] = 1; // mark as used
                break;          // very important
            }
            // optimization: since arrays are sorted, break early
            else if (b[j] > a[i])
            {
                break;
            }
        }
    }

    return ans;
}

// ================================================================================
//                               OPTIMAL APPROACH
// ================================================================================

/**
 * @brief Optimal intersection using two pointers.
 *
 * Idea:
 * - Since arrays are sorted, use two pointers i and j.
 * - If a[i] == b[j] → match found → push to ans, move both pointers.
 * - If a[i] < b[j] → a[i] cannot appear later in B → increment i.
 * - If b[j] < a[i] → b[j] cannot appear later in A → increment j.
 *
 * This ensures both arrays are scanned only ONCE.
 *
 * Time Complexity: O(n1 + n2)
 * Space Complexity: O(n1 + n2) for output array
 *
 * @param a First sorted array
 * @param b Second sorted array
 * @return vector<int> Intersection result
 */
vector<int> interSectionOptimal(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int n = a.size();
    int m = b.size();

    int i = 0;
    int j = 0;

    // traverse both arrays
    while (i < n && j < m)
    {
        // common element found
        if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
        // a[i] is smaller → cannot be present in remaining B
        else if (a[i] < b[j])
        {
            i++;
        }
        // b[j] is smaller → cannot be present in remaining A
        else
        {
            j++;
        }
    }
    return ans;
}

// ================================================================================
//                                      MAIN
// ================================================================================

int main()
{
    vector<int> a = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> b = {2, 3, 3, 5, 6, 7};

    // vector<int> intersectionArray = interSectionBrute(a, b);
    vector<int> intersectionArray = interSectionOptimal(a, b);

    for (int i = 0; i < intersectionArray.size(); i++)
    {
        cout << intersectionArray[i] << " ";
    }

    return 0;
}
