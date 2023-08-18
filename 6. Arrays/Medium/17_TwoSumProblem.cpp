/*
Given an array of integers and an integer target, return indices of the two numbers such that they add up to target.You may assume that each input would have exactly one solution, and you may not use the same element twice.
if there are no two numbers which equal to the target, return -1,-1 for both indices
ex: arr[] = {18,1,8,1,20}, target = 28
output = {2,4}
and if target = 100
output = {-1,-1}
*/

#include <bits/stdc++.h>
using namespace std;

// brute force
vector<int> twoSum(vector<int> &nums, int target)
{
    // to store indices
    vector<int> indices;
    // array size
    int n = nums.size();
    // flag to check if we got our desired numbers
    int flag = 0;
    // outer loop to find elements
    for (int i = 0; i < n; i++)
    {
        // flag is one. Means we got our numbers. So getting out from the loop.
        if (flag == 1)
        {
            break;
        }
        else
        {
            // inner loop to check if nums[j] and nums[i] add up to the target
            for (int j = i + 1; j < n; j++)
            {
                // conditions fulfilled
                if (nums[i] + nums[j] == target)
                {
                    // insert both the index in the indices array
                    indices.push_back(i);
                    indices.push_back(j);
                    // update flag.
                    flag = 1;
                    // come out the loop
                    break;
                }
            }
        }
    }
    // in case there are no numbers in the array which add up to the target
    if (indices.empty())
    {
        // inserting -1 in both the indices
        indices.push_back(-1);
        indices.push_back(-1);
    }
    // return the indices array
    return indices;
}
// T:O(N^2)

// optimal approach: using hashmap
vector<int> twoSumOptimal(vector<int> &nums, int target)
{
    int n = nums.size();
    // hashmap to store elements and their indices.
    map<int, int> mpp;
    vector<int> indices;
    // loop to traverse the array
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        int rem = target - num;
        // check if rem exists in the hashmap
        if (mpp.find(rem) != mpp.end())
        {
            // rem exists in map. so insert both the indices and return the array
            indices.push_back(mpp[rem]);
            indices.push_back(i);
            return indices;
        }
        mpp[num] = i; // logN for eash insertion ordered map. O(1) in best case,O(N) in worst case for unordered_map
    }
    // in case there are no numbers in the array which add up to the target
    if (indices.empty())
    {
        indices.push_back(-1);
        indices.push_back(-1);
    }
    return indices;
}
// T:O(NlogN) for ordered map,O(N)in best case and O(N^2) in worst case for unordered_map,
// S:O(N) for hashmap.

int main()
{
    int n; // array size
    cout << "Enter array size: ";
    cin >> n;
    vector<int> nums;
    // take user input
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int target;
    cout << "Enter target value: ";
    cin >> target;
    // ans array to store indices. calling the twoSum function to perform the task
    // vector<int> ans = twoSum(nums, target);
    vector<int> ans = twoSumOptimal(nums, target);

    cout << "indexes for numbers that add up to " << target << " are : " << ans[0] << " and " << ans[1] << endl;
    return 0;
}