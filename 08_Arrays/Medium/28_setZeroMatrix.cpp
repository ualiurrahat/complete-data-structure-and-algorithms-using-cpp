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
// better solution
vector<vector<int>> zeroMatrixBetter(vector<vector<int>> &matrix, int n, int m)
{
    // step 1: take two array to mark
    // the specific rows and columns
    // containing 0s
    int row[n] = {0};
    int col[m] = {0};

    // step 2: traverse the array and mark rows,cols
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // marking
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    // step 3: now update matrix values
    // in the marked rows and columns to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
    // T:O(n*m) + O(n*m) = O(2*n*m)
    // O(n+m); for column,row array
}
// optimal solution
vector<vector<int>> zeroMatrixOptimal(vector<vector<int>> &matrix, int n, int m)
{
    // instead of using extra space for marking
    // we will use 1st row and 1st col
    // of the given matrix.

    // int col[m] = {0}; -> matrix[0][..]
    // int row[n] = {0}; -> matrix[..][0]

    int col0 = 1; // to mark 0th column
    // step 1: traverse the matrix and
    // mark ith row and jth column
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark ith row
                matrix[i][0] = 0;
                // mark jth column
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }
    // step 2: mark the matrix from (1,1) to(n-1,m-1)
    // inside the matrix who are according to the
    // marked done on ith row and jth column
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for marked row and column
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // now mark the first row first and
    // then the first column
    // NOTE: first row must be marked before first column
    // why?
    /* the modification of the 1st row is dependent on matrix[0][0]
    and the modification of the 1st column is dependent on col0
     which is an independent variable. Now, if we modify the 1st column first,
      matrix[0][0] might be changed and this will hinder
      the modification of the 1st row as well.
      But if we simply do the opposite, the 1st row will be changed first,
      based on the value matrix[0][0] and
      then the 1st column will be changed based on the variable col0.
      This is why the order of change matters.
      */

    // step 3: mark the first row
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    // step 4: mark the first column
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
    // T:O(n*m)+O(n-1)*(m-1)+O(m)+ O(n) == O(2*n*m)
    // S:O(1)
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
    // matrix = zeroMatrixBrute(matrix, n, m);
    // matrix = zeroMatrixBetter(matrix, n, m);
    matrix = zeroMatrixOptimal(matrix, n, m);
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
