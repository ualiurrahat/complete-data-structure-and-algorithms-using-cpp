/*
    File: 05_assignMiceHoles.cpp

    Problem Statement:
    ------------------
    You are given two arrays mices[] and holes[] of the same size.
    - mices[i] represents the position of the i-th mouse on a straight line.
    - holes[i] represents the position of the i-th hole on the same line.
    - Each hole can accommodate exactly one mouse.
    - A mouse can either stay where it is, move left, or move right.
    - Moving one step takes exactly 1 minute.

    Goal:
    -----
    Assign each mouse to a distinct hole such that:
        - The time taken by the last mouse to reach its hole is minimized.
        - Return this minimum possible time.

    Example:
    --------
    Input:
        mices = {4, -4, 2}
        holes = {4, 0, 5}

    After assignment:
        Mouse at 4  → Hole at 4 → time 0
        Mouse at -4 → Hole at 0 → time 4
        Mouse at 2  → Hole at 5 → time 3

    Maximum time taken by any mouse = 4  ← Answer

    Constraints:
    ------------
    1 ≤ mices.size() = holes.size() ≤ 1e5
    -1e5 ≤ mices[i], holes[i] ≤ 1e5

    Approach Summary:
    -----------------
    Greedy approach works:
        - Sort both arrays.
        - Assign smallest mouse position to smallest hole position.
        - Assign second smallest mouse to second smallest hole, and so on.
        - This pairing minimizes the maximum time any mouse takes.

    Intuition:
    ----------
    Sorting ensures minimal mismatch between mouse and hole positions.
    This minimizes the maximum absolute difference.
*/

#include <iostream>
#include <vector>
#include <algorithm> // to use the sort() algorithm function
#include <cstdlib>   // to use abs() function
#include <climits>   // to use INT_MAX / INT_MIN
using namespace std;

/*
    Brute Force Approach (Not Feasible)
    -----------------------------------
    Try all permutations of hole assignments and compute the maximum
    movement time for each assignment, then return the minimum of those.
    Time Complexity: O(N! × N) → Impossible for N > 10
*/

/*
    Better Approach (Using Sorting)
    -------------------------------
    Sort both arrays and pair i-th mouse to i-th hole.
    Time Complexity: O(N log N)
    Space Complexity: O(1)
*/

/**
 * @brief Computes minimum possible maximum time for assigning mice to holes.
 *
 * This is the optimal solution using a greedy strategy:
 * 1. Sort mices[].
 * 2. Sort holes[].
 * 3. Pair i-th mouse with i-th hole.
 * 4. Maximum absolute difference across all pairs is the answer.
 *
 * @param mices A vector containing mouse positions.
 * @param holes A vector containing hole positions.
 * @return int The minimized maximum time required by any mouse.
 *
 * Time Complexity: O(N log N)
 * Space Complexity: O(1)
 */
int assignHole(vector<int> &mices, vector<int> &holes)
{
    // Step 1: Sort the mouse positions so they align in increasing order.
    sort(mices.begin(), mices.end());

    // Step 2: Sort the hole positions.
    sort(holes.begin(), holes.end());

    // Initialize maxTime to a very small value.
    // This will store the maximum difference seen so far.
    int maxTime = INT_MIN;

    int n = mices.size();

    // Step 3: Pair the i-th mouse with the i-th hole.
    for (int i = 0; i < n; i++)
    {
        // Calculate time for current mouse to reach the current hole.
        int currentTime = abs(mices[i] - holes[i]);

        // Update the maximum time encountered so far.
        maxTime = max(maxTime, currentTime);
    }

    // Step 4: maxTime now represents the minimal possible maximum time.
    return maxTime;
}

int main()
{
    // Sample Test Case 1
    vector<int> mices1 = {4, -4, 2};
    vector<int> holes1 = {4, 0, 5};
    cout << assignHole(mices1, holes1) << endl; // Expected Output: 4

    // Sample Test Case 2
    vector<int> mices2 = {1, 2};
    vector<int> holes2 = {20, 10};
    cout << assignHole(mices2, holes2) << endl; // Expected Output: 18

    // Additional Test Case
    vector<int> mices3 = {-10, -2, 0, 4};
    vector<int> holes3 = {-12, -1, 2, 3};
    cout << assignHole(mices3, holes3) << endl; // Expected Output: 3

    return 0;
}
