/*
Given array that contains number from 1 to N. only one number is missing.
find that number. Array has n-1 total numbers.
ex = a[] = [1,2,3,5]
output = 4
*/

#include <iostream>
using namespace std;

// brute force approach
int missingNumberBrute(int arr[], int n)
{
    int ans;
    // outer loop to run from 1 to n
    for (int i = 1; i <= n; i++)
    {
        // a flag var with initial value 0.
        // if i exists in arr,flag is assignd 1
        int flag = 0;
        // inner loop to run from 0 to n-1
        // to find if i exists in arr
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] == i)
            {
                // update flag
                flag = 1;
                break;
            }
        }
        // if flag is still 0, then i is the missing number
        if (flag == 0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
// T:O(n*n), at worst case
// S:O(1)

// better approach
int missingNumberBetter(int a[], int N)
{
    int ans;
    // take a hash array. it will store frequencies of elements.
    int freq[N + 1] = {0};
    // storing frequencies of elements in freq array
    for (int i = 0; i < N - 1; i++)
    {
        freq[a[i]] = 1;
    }
    // checking the frequencies for number 1 to N.
    for (int i = 1; i <= N; i++)
    {
        if (freq[i] == 0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
// T:O(N)
// S:O(N)

// optimal approach 1: use sum of n natural numbers
int missingNumberOptimalOne(int arr[], int n)
{
    int sum = (n * (n + 1)) / 2;
    // now subtract each number of array from sum
    for (int i = 0; i < n - 1; i++)
    {
        sum = sum - arr[i];
    }
    // now reaming value of sum is the missing number
    return sum;
}
// T:O(n), S:O(1)

// optimal approach 2: use xor
int missingNumberOptimalTwo(int arr[], int n)
{
    // find xor of first n natural numbers.
    int xor1 = 0;
    for (int i = 1; i <= n; i++)
    {
        xor1 = xor1 ^ i;
    }
    int xor2 = 0;
    // find xor of given array numbers
    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i];
    }
    // now xor of both xor values is the missing number
    return xor1 ^ xor2;
}
// T:O(n), S:O(1)

int main()
{
    int a[] = {1, 2, 3, 5};
    int b[] = {1, 2, 3, 5, 4, 7, 8};

    // cout << missingNumberBrute(a, 5) << endl;
    // cout << missingNumberBrute(b, 8) << endl;

    // cout << missingNumberBetter(a, 5) << endl;
    // cout << missingNumberBetter(b, 8) << endl;

    // cout << missingNumberOptimalOne(a, 5) << endl;
    // cout << missingNumberOptimalOne(b, 8) << endl;

    cout << missingNumberOptimalTwo(a, 5) << endl;
    cout << missingNumberOptimalTwo(b, 8) << endl;
    return 0;
}