/**
 * @file 01_assignCookies.cpp
 * @brief Greedy Algorithm — Assign Cookies
 *
 * Problem:
 * You want to maximize the number of children who can be made content.
 * Each child has a greed factor g[i], which is the minimum cookie size
 * they require to be satisfied. Each cookie has a size s[j].
 *
 * You can assign at most one cookie to each child.
 * A child is content if s[j] >= g[i].
 *
 * Goal: Return the maximum number of content children.
 *
 * Example 1:
 * g = [1,2,3], s = [1,1]
 * Output = 1
 *
 * Example 2:
 * g = [1,2], s = [1,2,3]
 * Output = 2
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Finds the maximum number of content children using a greedy strategy.
 *
 * @param g Vector of greed factors of children.
 * @param s Vector of cookie sizes.
 * @return int Maximum number of children that can be satisfied.
 *
 * @details
 * Logic:
 * -----------------------------------------------------------
 * - Sort both the greed factor array and the cookie sizes array.
 * - Use two pointers to iterate over children and cookies.
 *      left  → cookie pointer
 *      right → child pointer
 *
 * - If the current cookie can satisfy the current child
 *      (i.e., s[left] >= g[right]):
 *          → assign cookie, move both pointers.
 *   Otherwise:
 *          → cookie is too small, move to the next cookie.
 *
 * - The pointer 'right' represents the number of children satisfied.
 *
 * Time Complexity:
 *      O(n log n + m log m) due to sorting.
 *
 * Space Complexity:
 *      O(1) extra space (sorting done in-place).
 */
int findContentChildren(vector<int> &g, vector<int> &s)
{

    // sort both the greed and cookies array
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    // two pointers to iterate over greed and cookies
    // left --> cookie pointer, right --> greed pointer
    int left = 0, right = 0;
    int n1 = g.size();
    int n2 = s.size();

    // iterate while both arrays still have elements left
    while (left < n2 && right < n1)
    {

        // if current cookie size is enough for the current child's greed factor
        if (s[left] >= g[right])
        {
            // cookie satisfies the child → move both pointers
            left++;
            right++;
        }
        else
        {
            // cookie is too small → try next larger cookie
            left++;
        }
    }

    // right is the index number before which greed has been satisfied
    return right;
}

int main()
{

    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << "Output (Expected 1): " << findContentChildren(g1, s1) << endl;

    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << "Output (Expected 2): " << findContentChildren(g2, s2) << endl;

    return 0;
}
