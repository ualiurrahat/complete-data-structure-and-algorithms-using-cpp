#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

/**
 * @brief Brute Force Approach: Uses prefix and suffix max arrays to compute water trapped.
 *
 * @param height Array representing elevation map.
 * @return Total units of trapped rainwater.
 *
 * @note Time Complexity: O(3n)
 * @note Space Complexity: O(2n)
 */
int trapBrute(vector<int> &height)
{
    int n = height.size();
    int prefixMax[n]; // to store left max values
    int suffixMax[n]; // to store right max values

    // ---------------------- Left Max Array ----------------------
    prefixMax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], height[i]);
    }

    // ---------------------- Right Max Array ----------------------
    suffixMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], height[i]);
    }

    int total = 0; // to track total trapped water

    // ---------------------- Calculate Trapped Water ----------------------
    for (int i = 0; i < n - 1; i++)
    {
        int leftMax = prefixMax[i];
        int rightMax = suffixMax[i];
        if (height[i] < leftMax && height[i] < rightMax)
        {
            total = total + min(leftMax, rightMax) - height[i];
        }
    }

    return total;
}

/**
 * @brief Better Approach: Precomputes suffix max, and calculates prefix max on-the-go.
 *
 * @param height Array representing elevation map.
 * @return Total units of trapped rainwater.
 *
 * @note Time Complexity: O(2n)
 * @note Space Complexity: O(n)
 */

/**
 * @brief Stack-based approach to compute trapped rainwater.
 *
 * @param height Vector representing elevation map.
 * @return Total units of trapped rainwater.
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(n)
 */
int trapStack(vector<int> &height)
{
    int n = height.size();
    int total = 0;
    stack<int> st; // stack stores indices of height[]

    for (int current = 0; current < n; current++)
    {
        // While stack is not empty and current bar is taller than stack top
        while (!st.empty() && height[current] > height[st.top()])
        {
            int bottom = st.top(); // The "bottom" index
            st.pop();

            if (st.empty())
                break; // No left boundary to trap water

            int left = st.top();            // The index of left boundary
            int width = current - left - 1; // distance between left and current
            int bounded_height = min(height[left], height[current]) - height[bottom];

            total += width * bounded_height;
        }

        // Always push current index to stack
        st.push(current);
    }

    return total;
}

int trapBetter(vector<int> &height)
{
    int n = height.size();
    int suffixMax[n]; // to store right max values

    // ---------------------- Build Right Max Array ----------------------
    suffixMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], height[i]);
    }

    int leftMax = INT_MIN; // will calculate left max values while traversing
    int total = 0;         // to track total trapped water

    // ---------------------- Calculate Trapped Water ----------------------
    for (int i = 0; i < n - 1; i++)
    {
        leftMax = max(leftMax, height[i]);
        int rightMax = suffixMax[i];
        if (height[i] < leftMax && height[i] < rightMax)
        {
            total = total + min(leftMax, rightMax) - height[i];
        }
    }

    return total;
}

/**
 * @brief Optimal Approach: Two-pointer method with constant space usage.
 *
 * @param height Array representing elevation map.
 * @return Total units of trapped rainwater.
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(1)
 */
int trapOptimal(vector<int> &height)
{
    int leftMax = 0;
    int rightMax = 0;
    int total = 0;

    int left = 0, right = height.size() - 1;

    // ---------------------- Two-Pointer Traversal ----------------------
    while (left < right)
    {
        if (height[left] <= height[right])
        {
            // If current height is less than left max, trap water
            if (leftMax > height[left])
            {
                total = total + leftMax - height[left];
            }
            else
            {
                leftMax = height[left];
            }
            left++;
        }
        else
        {
            // If current height is less than right max, trap water
            if (rightMax > height[right])
            {
                total = total + rightMax - height[right];
            }
            else
            {
                rightMax = height[right];
            }
            right--;
        }
    }

    return total;
}
int main()
{
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height2 = {4, 2, 0, 3, 2, 5};

    cout << "Brute  -> " << trapBrute(height1) << " | " << trapBrute(height2) << endl;
    cout << "Better -> " << trapBetter(height1) << " | " << trapBetter(height2) << endl;
    cout << "Optimal-> " << trapOptimal(height1) << " | " << trapOptimal(height2) << endl;

    return 0;
}
