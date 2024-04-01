/*You are given an array ‘a’ of ‘n’ integers.
You have to return the lexicographically next to greater permutation.
Note:
If such a sequence is impossible, it must be rearranged in the lowest possible order.
Example:
Input: 'a' = [1, 3, 2]
Output: 2 1 3
Explanation: All the permutations of [1, 2, 3] are [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1], ]. Hence the next greater permutation of [1, 3, 2] is [2, 1, 3].*/
#include <bits/stdc++.h>
using namespace std;

// optimal function to find next permutation
vector<int> nextGreaterPermutation(vector<int> &A)
{
    int n = A.size(); // size of the array
    // step 1: find the break point
    // break point means the first greater element
    // in the array while traversing back when arr[i] < arr[i+1]
    int index = -1; // break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            // break point found
            index = i;
            break;
        }
    }
    // if break point does not exist
    if (index == -1)
    {
        // no break point means giving arrangement
        // is the last lexicographical permutaion
        // so the first lexicographical permutaion is the next one.
        // so reverse the whole array
        reverse(A.begin(), A.end());
        return A;
    }
    // step 2: find the next greater element
    // and swap it with arr[ind]
    for (int i = n - 1; i > index; i--)
    {
        if (A[i] > A[index])
        {
            swap(A[i], A[index]);
            break;
        }
    }

    // step 3: reverse the right half
    reverse(A.begin() + index + 1, A.end());

    // return answer
    return A;
    // T:O(3N), S:O(1).
}
int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    // creating n size vector
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr = nextGreaterPermutation(arr);
    cout << "next greater permutation: " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}