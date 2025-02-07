/*You are given an array A of length N, where N is always an odd integer.
 There are (N-1)/2 elements in the array that occur twice and one element which occurs once.
Your task is to find the only element that occurs once in the array.
Note: There are (N-1)/2+1 elements that are unique in the array.
Example:
Consider the array be 1,6,4,6,2,4,2
The integers 2, 4, 6 occur twice and only the integer 1 occurs once. */

#include <iostream>
#include <map>
#include <vector>
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

// optimal solution: using bitwise XOR(^) operation
int singleElementOptimal(vector<int> &a)
{
    int xorValue = 0;
    // do xor of all the elements
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        xorValue ^= a[i];
    }
    // all elements appearing twice become 0 for the XOR operation
    // so only single element value is now the xorvalue
    // return xorvalue
    return xorValue;
    // T:O(N), S:O(1)
}
int main()
{
    vector<int> input = {20, 13, 14, 14, 1, 20, 13};
    cout << "Input Array: ";
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    // int ans = singleElementBrute(input);
    int ans = singleElementOptimal(input);
    cout << "Single Element: " << ans << endl;
    return 0;
}