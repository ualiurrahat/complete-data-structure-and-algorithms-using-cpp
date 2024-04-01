/*
You are given an integer ‘N’. You need to return the first ‘N’ rows of Pascal’s triangle.
Example:
Input:
N = 4
Output:
1
1 1
1 2 1
1 3 3 1
Explanation: The output matrix has the first four rows of Pascal’s Triangle.

*/

#include <iostream>
#include <vector>

using namespace std;

// function to generate element
// on the fiven row and column
// in pascal triangle
int findElement(int n, int row)
{
    int ans = 1;
    for (int i = 0; i < row; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }
    return ans;
    // T:O(r), O(1)
}
// function to generate all elment of nth row
// in pascal triangle. the function returns the
// nth row elements in a vector

vector<int> generateNthRow(int n)
{
    vector<int> ansRow;
    // first element of any row
    // in pascal triangle is always 1
    int ans = 1;
    ansRow.push_back(ans);
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        ansRow.push_back(ans);
    }
    // T:O(n)
    // S:O(n)[for returning ans], but[O(1) for only solving problem]
    return ansRow;
}
// brute force solution to get all elements
// of pascal triangle for value of N
vector<vector<int>> pascalTriangleBrute(int N)
{
    // take a vector of vectors
    vector<vector<int>> ans;
    // for each row
    for (int i = 1; i <= N; i++)
    {
        // take a vector to contain all element each column
        vector<int> temp;
        // for each column
        for (int j = 1; j <= i; j++)
        {
            int elem = findElement(i - 1, j - 1);
            temp.push_back(elem);
        }
        // add each row on the ans vector
        ans.push_back(temp);
    }
    return ans;
    // T:O(n*n*r) ~= T:O(n^3)
    // S:O(n^2), but it is asked by the question. so it is O(1).
}
// optimal solution to get all elements
// of pascal triangle for value of N
vector<vector<int>> pascalTriangleOptimal(int N)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++)
    {
        // generating ith row
        vector<int> ansrow = generateNthRow(i);
        // insert ith row in the ans
        ans.push_back(ansrow);
    }
    return ans;
    // T:O(n*n);
}

int main()
{
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    // vector<vector<int>> ans = pascalTriangleBrute(n);
    vector<vector<int>> ans = pascalTriangleOptimal(n);
    cout << "The pascal triangle up to " << n << " th row is: " << endl;
    for (const auto &row : ans)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}