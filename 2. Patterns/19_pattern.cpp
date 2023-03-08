/* for n=4, pattern would look like this,
         1234321
          12321
           121
            1
    */

#include <iostream>
using namespace std;

int main()
{
    int n, row, col;
    int count = 0;

    cout << ("enter n = ");
    cin >> n;

    for (row = n - 1; row >= 1; row--)
    {
        for (col = 1; col <= n - row; col++)
        {
            cout << (" ");
        }
        for (col = 1; col <= row; col++)
        {
            cout << col;
        }
        for (col = row - 1; col >= 1; col--)
        {
            cout << col;
        }
        cout << ("\n");
    }
    return 0;
}
