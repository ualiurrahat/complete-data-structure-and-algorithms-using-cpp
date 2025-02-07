/*Given an integer array nums where every element appears three times except for one,
 which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity
and use only constant extra space.*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// brute force solution: using map data structure
// returns the number that appears only 1
// else returns -1, in case there is no such element.
int singleElementBrute(vector<int> &a)
{
    // map variable to store number with their frequencies
    map<int, int> m;
    // step 1: traverse the array and store elements in the map with frequencies
    for (int i = 0; i < a.size(); i++)
    {
        m[a[i]]++; // increasing frequency of a[i] each time it appears.
    }
    // step 2: now iterate whole map and find the single appearing number
    for (auto it : m)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    // in case of no single number, returning -1
    return -1;
    /*Time Complexity: T=O(NxlogM + M) [ N = total elements, M = size of map]
    Space Complexity: S = O(M) [for using M size map]
    */
}

/*better solution: let nums = [5,5,5,6,4,4,4,]

    bit position =  2  1  0  (th bit)

            5    =  1  0  1
            5    =  1  0  1
            5    =  1  0  1
            6    =  1  1  0
            4    =  1  0  0
            4    =  1  0  0
            4    =  1  0  0
---------------------------------------
number of 1s    =   7  1  3
            7 % 3 == 1 (set bit)
            1 % 3 == 1  (set bit)
            3 % 3 == 0 (unset bit)
            so ans = 1 1 0  = 6
If the sum is divisible by 3, it means that the number that appears only once on that bit position has a bit value of 0. Otherwise, it has a bit value of 1. This is because if a number appears thrice in the input array, the sum of its bits at any position will be divisible by 3.

Algorithm:
Step 1: Initialise a variable `ans` to store the result.

Step 2: Iterate through each bit position from 0 to 31.
 Inside the loop:
Initialise a counter `cnt` to count the number of set bits at the current bit position.

Step 3: Inside the loop, iterate through each element in the input array.
 Inside this nested loop:
Check if the bit at the current position is set in the current element using bitwise AND with a mask for that current bit position from 0 to 31 ie. nums[i] & 1 << bitIndex.
If the bit is set, increment the counter `cnt`.

Step 4: After iterating through all elements, check if the count of set bits at the current bit position is not divisible by 3. If the condition is true, set the corresponding bit in the answer variable `ans` using the bitwise OR operation ie. ans |= 1 << bitIndex.
Step 5: After iterating through all bit positions, return the decimal representation of the answer stored in ans.

*/

int singleNumberBetter(vector<int> &nums)
{
    // step 1: initialise a variable 'ans' to store the result
    int ans = 0;
    // variable to track bit position
    int bitIndex;
    // size of input array
    int n = nums.size();
    // step 2: loop to iterate through each bit position from 0 to 31
    for (bitIndex = 0; bitIndex < 32; bitIndex++) // T:O(32)
    {
        // to count the no. of set bits at the current bit position of all the numbers
        int count = 0;
        // step 3: loop to iterate through each element in the input array
        for (int i = 0; i < n; i++) // O(N)
        {
            // 3.1: check if the bit at the current position is set in the current element
            if (nums[i] & (1 << bitIndex))
            {
                // 3.2: bit is set. increment the count
                count++;
            }
        }
        // step 4: check if count of set bits at current position is not divisible by 3
        if (count % 3 == 1)
        {
            // 4.1: condition is true. so set the corresponding bit in the ans variable
            ans = ans | (1 << bitIndex);
        }
    }
    // step 5: return the decimal representation of the answer stored in ans
    return ans;
    // T:O(32 x N), always whether it's a best/worst/avg case
    // S:O(1)
}
// optimal solution
int singleNumberOptimal(vector<int> &nums)
{
    int n = nums.size(); // size of given array
    // step 1: sort the array
    sort(nums.begin(), nums.end());
    // step 2: traverse the sorted array from index 1
    // since the array is sorted, there will be 3 consecutive triplets of each element
    // except the number out of order.
    // Increment the loop variable by 3 in each iteration to skip elements in groups of three
    for (int i = 1; i < n; i = i + 3)
    {
        // step 3: compare the current element with its preceding element
        // if current element is not equal to the preceding one
        // then the preceding element is the number that appears one
        if (nums[i] != nums[i - 1])
        {
            return nums[i - 1];
        }
    }
    // step 4: if the loop ends without the out of place element.
    // then the last element is the out of place element. return it.
    return nums[n - 1];
    // T:O(NlogN) + O(N/3)
    // how this is better than better solution complexity :T = O(N x 32)
    // because it is always T:O(N x 32) in all best/worst/avg case
    // where as T:O(NlogN) will be O(N x 32) when array size = 2^32, which is very rare.
    // elements in the array. this is rare. so this is optimal solution.
}
/*Fourth Solution: using concept of buckets (this is the best solution)
we will store numbers in buckets:
ones->number that appear once, same goes for buckets like twos and threes
ones = 0;
twos = 0;
threes = 0;
rutles: 1) num[i] will go to one if it is not in twos (only adding in ones)
2) num[i] will go to twos if it is in ones (delete in ones, adding in twos)
3) num[i] will go to threes if it is in twos

1) num[i] will go to one if it is not in twos
= (num[i] ^ ones) & (~twos);
2) if it is not in ones, it will go to twos
= (num[i] ^ twos) & (~ones);

we don't need to check who appears thrice and stores them in threes
we achieved what we need just by this two options. all we care is
who is appearing only once in the array.

*/
int singleNumberBest(vector<int> &a)
{
    int ones = 0, twos = 0;
    int n = a.size(); // size of input array
    for (int i = 0; i < n; i++)
    {
        // step 1: add the number in ones, if it is not in twos
        ones = (ones ^ a[i]) & (~twos);
        // step 2: add the number in twos, if it is in ones.
        twos = (twos ^ a[i]) & (~ones);
    }
    return ones;
    // T:O(N), S:O(1)
}
int main()
{

    vector<int> input = {5, 6, 4, 4, 5, 4, 5};
    cout << "Input Array: ";
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    // int ans = singleElementBrute(input);
    // int ans = singleNumberBetter(input);
    // int ans = singleNumberOptimal(input);
    int ans = singleNumberBest(input);
    cout << "Single Element: " << ans << endl;
    return 0;
}