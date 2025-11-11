/*
============================================================================
   FILE: 05_rotateArrayByKPlaces.cpp
   TOPIC: Rotate Array by K Places
============================================================================

🧠 PROBLEM STATEMENT:
----------------------
Given an integer array nums, rotate the array to the right by k steps,
where k is non-negative.

📘 Example 1:
-------------
Input:  nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Explanation:
rotate 1 step  → [7,1,2,3,4,5,6]
rotate 2 steps → [6,7,1,2,3,4,5]
rotate 3 steps → [5,6,7,1,2,3,4]

📘 Example 2:
-------------
Input:  nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]

Explanation:
rotate 1 step  → [99,-1,-100,3]
rotate 2 steps → [3,99,-1,-100]

============================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// 🧩 Brute Force Solution
// ------------------------------------------------------------
// Approach:
// 1️⃣ Normalize k → since rotating n times gives same array,
//     we only need to rotate k % n times.
// 2️⃣ Create a temporary vector "ans".
// 3️⃣ Copy the last k elements of nums into ans first.
// 4️⃣ Then copy the first (n - k) elements.
// 5️⃣ Copy everything from ans back into nums.
//
// 🔹 Time Complexity:  O(n)
// 🔹 Space Complexity: O(n) — using extra vector
// ------------------------------------------------------------
void rotateBrute(vector<int> &nums, int k)
{
    int n = nums.size();

    // Edge case handling: Normalize k
    k = k % n;

    vector<int> ans;

    // Step 1: Push last k elements to ans
    for (int i = n - k; i < n; i++)
    {
        ans.push_back(nums[i]);
    }

    // Step 2: Push first (n - k) elements to ans
    for (int i = 0; i < n - k; i++)
    {
        ans.push_back(nums[i]);
    }

    // Step 3: Copy elements back to nums
    for (int i = 0; i < n; i++)
    {
        nums[i] = ans[i];
    }
}

// ------------------------------------------------------------
// ⚙️ Optimal Solution — In-place using Reversal Algorithm
// ------------------------------------------------------------
// Intuition:
// To rotate array to right by k steps:
// 1️⃣ Normalize k = k % n
// 2️⃣ Reverse the entire array.
// 3️⃣ Reverse the first k elements.
// 4️⃣ Reverse the remaining (n - k) elements.
//
// Example: nums = [1,2,3,4,5,6,7], k = 3
// After Step 1: reverse all        → [7,6,5,4,3,2,1]
// After Step 2: reverse first 3    → [5,6,7,4,3,2,1]
// After Step 3: reverse remaining  → [5,6,7,1,2,3,4] ✅
//
// 🔹 Time Complexity:  O(n)
// 🔹 Space Complexity: O(1)
// ------------------------------------------------------------

// function to reverse an array within a given starting and ending index
void reverseArray(vector<int> &nums, int i, int j)
{
    while (i < j)
    {
        swap(nums[i], nums[j]); // swap current left and right element
        i++;
        j--;
    }
}

void rotateOptimal(vector<int> &nums, int k)
{
    int n = nums.size();

    // 1. Normalize k = k % n
    k = k % n;

    // 2. Reverse the entire array (0 to n-1)
    reverseArray(nums, 0, n - 1);

    // 3. Reverse the first k elements (0 to k-1)
    reverseArray(nums, 0, k - 1);

    // 4. Reverse the remaining n - k elements (k to n-1)
    reverseArray(nums, k, n - 1);
}

// ------------------------------------------------------------
// 🧪 Main Function — Driver Code
// ------------------------------------------------------------
int main()
{
    int n, k;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter k (no. of rotation steps): ";
    cin >> k;

    // Uncomment below line to test brute force method
    // rotateBrute(nums, k);

    // Testing optimal in-place method
    rotateOptimal(nums, k);

    cout << "Rotated array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
