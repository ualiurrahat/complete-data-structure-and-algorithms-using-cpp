/*
Pascal's Triangle.
              1 (0C0)
    1(1C0)           1(1C1)
1(2C0)      2(2C1)      1(2C2)
....................................
...................................

lets say i = row, and j = column.
so element t(i,j) = iCj.
...goes on.
1 3 3 1
1 4 6 4 1
*/

#include <iostream>
#include <string>

using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int main()
{
    int n;
    cout << "Enter how many rows you want to see in Pascal's Triangle: ";
    cin >> n;

    //loop for rows.
    // rows are from 0 to n-1;
    for (int i = 0; i < n; i++)
    {
        // loop for columns.
        // each column has its row number of element.
        // so condition is j<= i
        for (int j = 0; j <= i; j++)
        {
            // Term(i,j) = iCj.
            cout << factorial(i) / (factorial(j) * factorial(i - j)) << " ";
        }
        // going to next row.
        cout << endl;
    }

    return 0;
}