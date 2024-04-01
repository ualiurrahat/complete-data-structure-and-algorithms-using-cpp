/*You are given a 2D matrix ‘MATRIX’ of ‘N’*’M’ dimension. You have to return the spiral traversal of the matrix.
Example:
Input:
MATRIX = [ [1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60] ]
Output:
1 3 5 7 20 60 34 30 23 10 11 16
Explanation: Starting from the element in the first row and the first column, traverse from left to right (1 3 5 7), then top to bottom (20 60), then right to left (34 30 23), then bottom to up (10) and then left to right (11 16).*/

#include <bits/stdc++.h>
using namespace std;

// function to return the spiral traversal of a matrix
vector<int> spiralMatrix(vector<vector<int>> &MATRIX)
{
    int row = MATRIX.size();
    int col = MATRIX[0].size();
    vector<int> ans;
    int rowStart = 0;
    int rowEnd = row - 1;
    int colStart = 0;
    int colEnd = col - 1;
    while (rowStart <= rowEnd && colStart <= colEnd)
    {
        // for printing starting row
        for (int i = colStart; i <= colEnd; i++)
        {
            ans.push_back(MATRIX[rowStart][i]);
        }
        rowStart++;
        // for printing ending column
        for (int i = rowStart; i <= rowEnd; i++)
        {
            ans.push_back(MATRIX[i][colEnd]);
        }
        colEnd--;
        // for printing ending row
        if (rowStart <= rowEnd)
        {
            for (int i = colEnd; i >= colStart; i--)
            {
                ans.push_back(MATRIX[rowEnd][i]);
            }
            rowEnd--;
        }
        // for printing starting column
        if (colStart <= colEnd)
        {
            for (int i = rowEnd; i >= rowStart; i--)
            {
                ans.push_back(MATRIX[i][colStart]);
            }
            colStart++;
        }
    }
    return ans;
    // T:O(n*m);
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};

    int n = matrix.size();    // row
    int m = matrix[0].size(); // column
    cout << "The given matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> ans = spiralMatrix(matrix);
    cout << "spiral traversal : " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}