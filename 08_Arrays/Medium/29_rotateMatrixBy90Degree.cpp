/*You are given a square matrix ‘Mat’ of size ‘N’. You need to rotate ‘Mat’ by 90 degrees in the clockwise direction.
Note:
You must rotate the matrix in place, i.e., you must modify the given matrix itself.
You must not allocate another square matrix for rotation.
For example
When,
‘N’ = 2 and ‘Mat’ = {{1, 2}, {3, 4}}, we must modify ‘Mat’ to {{3, 1}, {4, 2}}.*/
#include <bits/stdc++.h>
using namespace std;

// brute force function to rotate matrix by 90 degree
void rotateMatrixBrute(vector<vector<int>> &mat)
{
    // step 1: take a square matrix
    //  of same rows and columns of given matrix
    vector<vector<int>> arr(mat.size(), vector<int>(mat[0].size()));
    // row
    int row = mat.size();
    // col
    int col = mat[0].size();
    int n = row;
    // for 90 degree rotation
    // mat[i][j] = arr[j][n-1-i]

    // step 2: fill the 90 degree rotated matrix
    // in the array arr
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[j][n - 1 - i] = mat[i][j];
        }
    }
    // step 3: copy the arr into mat
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = arr[i][j];
        }
    }
    // T:O(N^2)
    // S:O(n2), for array vector.
}
// optimal solution:
void rotateMatrixOptimal(vector<vector<int>> &mat)
{
    // step 1: transpose the matrix
    int n = mat.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // step 2: reverse the rows
    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
    // T:O(n*n)[for transponse] + O(n*n)[for reversing]
    // T:O(2*n^2)
    // S:O(1)
}
int main()
{

    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    cout << "given matrix: " << endl;
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
    // rotateMatrixBrute(matrix);
    rotateMatrixOptimal(matrix);
    cout << "Matrix after rotating by 90 degree: " << endl;
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