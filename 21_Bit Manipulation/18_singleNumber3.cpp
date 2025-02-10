/*
Given an integer array nums, in which exactly two elements appear only once
 and all the other elements appear exactly twice.
Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// brute force solution: using hashmap
vector<int> singleNumberBrute(vector<int> &nums)
{
    // size of input array
    int n = nums.size();
    // to store unique numbers
    vector<int> ans;
    // take a map to store element and their total apperances
    map<int, int> mpp;
    // iterate over the given array
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
        // T:O(NlogM), M = map size, N = array size
    }
    // now iterate over the map and check each number and their frequencies
    for (auto it : mpp) // O(M)
    {
        // check if it is appeared only once
        if (it.second == 1)
        {
            // add it in the ans vector
            ans.push_back(it.first);
        }
    }
    // return the ans
    return ans;
    // T:O(NlogM)+O(M), map size M = (N/2) + 1 always
    // since n-2 numbers are twice and 2 numbers are once.
    // S:O(M), since we are using hashmap
}
int main()
{

    vector<int> input = {1, 1, 2, 3, 3, 4, 5, 5, 6, 6};
    vector<int> output = singleNumberBrute(input);

    cout << "Singly Appeared Numbers: " << output[0] << " , " << output[1] << endl;
    return 0;
}