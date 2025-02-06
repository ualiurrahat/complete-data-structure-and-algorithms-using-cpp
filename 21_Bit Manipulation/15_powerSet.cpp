/*Given an integer array nums of unique elements, return all possible
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    // to contain all subsets
    vector<vector<int>> ans;
    // total no. of subsets = 2^(size of nums)
    int n = nums.size();
    int numSubsets = (1 << n);
    // external loop to form all subsets
    for (int num = 0; num < numSubsets; num++)
    {
        // to store elements for each individual subsets
        vector<int> currentSubset;
        // internal loop to fill each subset
        for (int i = 0; i < n; i++)
        {
            // check if ith bit is set.
            if (num & (1 << i))
            {
                // bit is set. so add the number in the subset
                currentSubset.push_back(nums[i]);
            }
        }
        // add current subset to list of all subsets
        ans.push_back(currentSubset);
    }
    return ans;
    // T:O(n x 2^n)
    // S:O(n x 2^n) [ 2^n subsets, but not all subsets are n sizes.so difficult to get the exact space complexity]
}
// function to print the subsets
void printSubsets(const vector<vector<int>> &subsets)
{
    cout << "[\n";
    for (const auto &subset : subsets)
    {
        cout << "  [";
        for (size_t i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ", "; // Add comma if not the last element
        }
        cout << "]\n";
    }
    cout << "]\n";
    // T:O(n x 2^n)
    // S:O(1)
}
int main()
{

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> output = subsets(nums);
    printSubsets(output);
    return 0;
}