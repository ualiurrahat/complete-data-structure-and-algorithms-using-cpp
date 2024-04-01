/*
pascal triangle:
1st row-------------- 1
2nd row-------------1   1
3rd---------------1   2   1
4th-------------1   3    3  1
5th-----------1    4   6   4   1
there can be 3 types of questions:
1) given row and column, find the element:
input: row 3, column 2 , output = 2
2) print the nth row:
input: 4, output: 1 3 3 1
3)given n, print the pascal triangle for number n
input: 5, output: above triangle

NOTE: here, each element value is nothing but n-1
                                                C
                                                  r-1
ex: 4th row, 3rd column, element is  3C2 = 3
*/
#include <iostream>
using namespace std;

// function to find the element,
// given values of row and column as input
long long nCr(int n, int r)
{
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
    // T:O(r),S:O(1).
}
// brute force solution to print nth row of pascal triangle
void printNthRowBrute(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << nCr(n - 1, i - 1) << " ";
    }
    cout << endl;
    // T:O(n*r),S:O(1)
}
// optimal solution to print nth row of pascal triangle
void printNthRowOptimal(int n)
{
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
    // T:O(n), S:O(1)
}
int main()
{
    int row, col;
    cout << "Enter value of row and column: ";
    cin >> row >> col;
    long long elem = nCr(row - 1, col - 1);
    cout << "The value of the element on the " << row << "ith row and " << col << "th column is : " << elem << endl;

    int n;
    cout << "Enter the row number you want to print in pascal triangle: ";
    cin >> n;
    cout << "The " << n << " the row : " << endl;
    // printNthRowBrute(n);
    printNthRowOptimal(n);
    return 0;
}