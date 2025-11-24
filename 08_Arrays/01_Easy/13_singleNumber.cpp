/*
Problem Statement:
------------------
Given a non-empty array of integers `nums`, every element appears exactly twice except for ONE element,
which appears only once. Your task is to find that single element.

You MUST implement a solution with:
1. Linear runtime complexity → O(n)
2. Constant extra space → O(1)

Examples:
---------
Input:  [2,2,1]
Output: 1

Input:  [4,1,2,1,2]
Output: 4

Input:  [1]
Output: 1

Constraints:
------------
1 <= nums.length <= 3 * 10^4
-3 * 10^4 <= nums[i] <= 3 * 10^4
Every element appears twice except one.
*/

#include <iostream>
#include <map>
using namespace std;

/*
Brute Force Approach
--------------------
Idea:
- For each element, linearly scan the entire array and count how many times it appears.
- If its count is 1, that is our answer.

Drawbacks:
- Inefficient because for every element, we scan the whole array.

@returns the element that appears only once.

Time Complexity:
- O(n^2) → Nested loops.

Space Complexity:
- O(1) → No extra data structures used.
*/
int findSingleElementBrute(int arr[], int n)
{
    for (int first = 0; first < n; first++)
    {
        int selected = arr[first];
        int count = 1;

        // Count occurrences of the selected element
        for (int second = 0; second < n; second++)
        {
            if (arr[second] == selected && second != first)
            {
                count++;
            }
        }

        if (count == 1)
        {
            return selected;
        }
    }
    return -1; // logically unreachable
}

/*
Better Approach 1 (Hash Array)
------------------------------
Idea:
- Build a frequency array.
- But this cannot handle negative numbers or large magnitude values safely.
- Kept only for learning purposes.

Time Complexity:
- O(n) to build frequency + O(n) to scan.

Space Complexity:
- O(max_element) → Not constant.
*/
int findSingleElementBetterOne(int arr[], int n)
{
    int maxi = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxi)
            maxi = arr[i];
    }

    int hash[maxi + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
            return arr[i];
    }

    return -1;
}

/*
Better Approach 2 (Using std::map)
----------------------------------
Idea:
- Map stores frequency of each element.
- Iterate map to find element with frequency = 1.

Drawback:
- Uses O(n) extra space.
- map operations cost O(log n).

Time Complexity:
- O(n log n)

Space Complexity:
- O(n)
*/
int findSingleElementBetterTwo(int arr[], int n)
{
    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (auto &entry : freq)
    {
        if (entry.second == 1)
        {
            return entry.first;
        }
    }

    return -1;
}

/*
Optimal Approach (XOR)
----------------------
Key XOR Properties:
1. a ^ 0 = a
2. a ^ a = 0
3. XOR is commutative and associative.

Since pairs cancel each other out, only the unique element remains.

Time Complexity:
- O(n)

Space Complexity:
- O(1) → Constant space.
*/
int findSingleElementOptimal(int arr[], int n)
{
    int xorr = 0;

    // XOR all elements
    for (int i = 0; i < n; i++)
    {
        xorr ^= arr[i];
    }
    return xorr;
}

/*
Main Function
-------------
Demonstrates usage with simple input.
*/
int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Input array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Example usage:
    // cout << findSingleElementBrute(arr, n) << endl;
    // cout << findSingleElementBetterOne(arr, n) << endl;
    // cout << findSingleElementBetterTwo(arr, n) << endl;

    cout << "Single element in the array is: "
         << findSingleElementOptimal(arr, n) << endl;

    return 0;
}
