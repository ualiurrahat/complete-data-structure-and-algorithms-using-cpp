#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
Problem: Alex has N empty boxes, each with a given side length ai.
Alex can place a smaller box i inside a larger box j if:
1. Box i is not already placed inside another box.
2. Box j is empty and doesn't contain any other boxes.
3. The side length of box i is smaller than the side length of box j (ai < aj).
Alex wants to minimize the number of visible boxes (boxes that are not inside another box).
Help Alex determine the minimum number of visible boxes possible.

Input format:
The first line contains one integer N — the number of boxes Alex has got.
The second line contains N integers a1, a2, ..., aN, where ai is the side length of the ith box.

Output format:
Output a single integer, the minimum number of visible boxes possible.

**Intuition and Explanation:**
1. If we have multiple boxes of the same size, we cannot nest them inside each other because they are of the same size.
2. For example, if we have **3 boxes of size 5**, we cannot fit one inside another since they all have the same size. Therefore, all of them will need to remain **visible**.
3. If a box size appears more frequently, this means we will have at least that many visible boxes because we can only nest the smaller ones inside larger ones, but we cannot nest boxes of the same size.
4. Thus, the **maximum frequency** of any box size gives the **minimum number of visible boxes** because:
   - We need at least **as many visible boxes as the maximum frequency** of a particular box size, since those boxes cannot be nested inside each other.

**Test Case Explanation:**

**Test Case 1:**
Input:
  5
  5 3 5 7 5

- Frequency of box sizes:
  - `5` appears 3 times.
  - `3` appears 1 time.
  - `7` appears 1 time.

- The maximum frequency of any box size is **3** (for box size 5).
- Therefore, at least **3 boxes of size 5** need to remain visible.

Output:
  3

**Test Case 2:**
Input:
  6
  8 8 7 7 7 7

- Frequency of box sizes:
  - `8` appears 2 times.
  - `7` appears 4 times.

- The maximum frequency of any box size is **4** (for box size 7).
- Therefore, at least **4 boxes of size 7** need to remain visible.

Output:
  4
*/

int main()
{
    int n;
    cin >> n;         // Read the number of boxes
    vector<int> a(n); // Create a vector to store the side lengths of the boxes

    // Read the side lengths of the boxes
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<int, int> mp; // A map to store the count of each box size

    // Count the occurrences of each box size
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++; // Increment the count of the current box size in the map
    }

    int ans = 0;

    // Find the maximum count of any box size
    // The number of visible boxes will be the maximum count of any box size
    for (auto it : mp)
    {
        ans = max(ans, it.second); // Update the answer with the maximum frequency
    }

    cout << ans << endl; // Output the minimum number of visible boxes

    return 0;
}
