/*Given two variables ‘X’ and ‘Y’. Your task is to swap the number
 without using a temporary variable or third variable.
 */

#include <bits/stdc++.h>
using namespace std;

// brute force solution: using temporary variable
vector<int> swapNumberBrute(int x, int y)
{
    vector<int> ans;
    // temp var to store value to swap numbers
    int temp = x;
    x = y;
    y = temp;
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}
// optimized solution: using XOR operation
vector<int> swapNumberOptimal(int x, int y)
{
    // Write your code here.
    vector<int> swappedNums;
    x = x ^ y;
    y = x ^ y; // (x ^ y) ^ y = x
    x = x ^ y; // (x ^ y) ^ x = y
    swappedNums.push_back(x);
    swappedNums.push_back(y);
    return swappedNums;
}
int main()
{
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << endl
         << "input numbers are, x = " << x << " y = " << y << endl;
    // using brute force solution
    // vector<int> ans = swapNumberBrute(x, y);
    // cout << "Output numbers are, x = " << ans[0] << " y = " << ans[1] << endl;
    // using optimal solution
    vector<int> ans = swapNumberOptimal(x, y);
    cout << "Output numbers are, x = " << ans[0] << " y = " << ans[1] << endl;

    return 0;
}