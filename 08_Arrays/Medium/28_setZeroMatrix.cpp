/*ou are given a matrix 'MATRIX' of dimension 'N' x 'M'. Your task is to make all the elements of row 'i' and column 'j' equal to 0 if any element in the ith row or jth column of the matrix is 0.
Note:
1) The number of rows should be at least 1.
2) The number of columns should be at least 1.*/
#include <bits/stdc++.h>
using namespace std;

// function to mark all elements of ith row as -1
void markRow(vector<vector<int>> &matrix, int n, int m, int i)
{
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
    // T:O(m)
}
// function to mark all elements of jth column as -1
void markCol(vector<vector<int>> &matrix, int n, int m, int j)
{
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
    // T:O(n)
}
// brute force solution
vector<vector<int>> zeroMatrixBrute(vector<vector<int>> &matrix, int n, int m)
{
    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    // T:O(n*m)[for traversing matrix]*O(n+m)[markRow,markCol] +O(n*m)[marking -1 as 0]
    // T:O(n*m)^2 + O(n*m);
    return matrix;
}
int main()
{

    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 0}};
    cout << "given matrix: " << endl;
    int n = matrix.size();    // row
    int m = matrix[0].size(); // column
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    matrix = zeroMatrixBrute(matrix, n, m);
    cout << "after zero matrix performance: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
