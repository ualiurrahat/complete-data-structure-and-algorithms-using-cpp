/*You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once.
There is a single integer value that is present in the array twice.
Your task is to find the duplicate integer value present in the array.

For example:
Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// brute force approach : Using Nested Loop
int findDuplicateBrute(vector<int> &arr)
{
    int n = arr.size();
    int ans = -1; // initializing with -1 indicating no duplicate is found yet.
    // iterate over the input array
    for (int i = 0; i < n - 1; i++)
    {
        // for each element at index i, check all elements at index j >i
        for (int j = i + 1; j < n; j++)
        {
            // check if both numbers are same
            if (arr[i] == arr[j])
            {
                // duplicate found. return it.
                ans = arr[i];
                break;
            }
        }
    }
    return ans;
    // T:O(N^2), S:O(1)
}
// solution 2: using sorting
int findDuplicate2(vector<int> &arr)
{
    // sort the input array
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int ans = -1; // to store duplicat number
    // iterate over the array
    for (int i = 0; i < n - 1; i++)
    {
        // check if elements of two consecutive indexes are equal
        if (arr[i] == arr[i + 1])
        {
            // this is the duplicate
            ans = arr[i];
            break;
        }
    }
    return ans;
    // T:O(NlogN) + O(N)
    // S:O(1)
}
// solution 3: using Hashset (Unordered Set)
int findDuplicate3(vector<int> &arr)
{
    unordered_set<int> seen;

    for (int num : arr)
    {
        if (seen.count(num)) // If number is already in set, it's the duplicate
            return num;
        seen.insert(num); // Add number to set
    }

    return -1; // Should never reach here as a duplicate is guaranteed
    // T:O(N), S:O(N)
}
// solution 4: Using Hashmap (unordered map)
#include <unordered_map>

int findDuplicate(vector<int> &arr)
{
    unordered_map<int, int> freq;

    for (int num : arr)
    {
        freq[num]++;       // Increment frequency count
        if (freq[num] > 1) // If count > 1, it's the duplicate
            return num;
    }

    return -1; // Should never reach here as a duplicate is guaranteed
    // T:O(N), S:O(N)
}

/*
   Function to find the duplicate number in an array using Floyd's Cycle Detection Algorithm.
   The array contains numbers from 1 to N-1, with exactly one duplicate.
*/
int findDuplicateOptimal(vector<int> &arr)
{
    int n = arr.size(); // size of array
    // Step 1: Initialize slow and fast pointers
    int slow = arr[0];
    int fast = arr[0];

    // Phase 1: Detect the cycle using Floyd’s Tortoise and Hare Algorithm
    do
    {
        slow = arr[slow];      // Move slow pointer one step
        fast = arr[arr[fast]]; // Move fast pointer two steps
    } while (slow != fast); // Loop until both pointers meet

    // Phase 2: Find the start of the cycle (duplicate number)
    slow = arr[0]; // Reset slow pointer to start
    while (slow != fast)
    {
        slow = arr[slow]; // Move slow pointer one step
        fast = arr[fast]; // Move fast pointer one step
    }

    return slow; // The duplicate number
    // T:O(N)
    // S:O(1)
}
int main()
{
    vector<int> a = {6, 3, 1, 5, 4, 3, 2};
    // int ans = findDuplicateBrute(a);
    // int ans = findDuplicate2(a);
    int ans = findDuplicateOptimal(a);
    cout << "Input array: ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Duplicate Value: " << ans << endl;

    return 0;
}