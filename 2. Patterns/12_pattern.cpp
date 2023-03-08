/* for n = 3, pattern would look like this.

        *
      * * *
    * * * * *
      * * *
        *

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    int row, col;
    cout <<("enter n = ");
    cin >> n;

    // printing  upper half.
    for(row = 1; row <= n; row++)
    {
        // space printing
        for(col = 1; col <= n-row; col++)
        {
            cout <<(" ");
        }
        //  printing *
        for(col = 1; col <= 2*row-1; col++)
        {
            cout <<("*");
        }
        cout <<("\n");
    }

    // printing lower half.
    for(row = n-1; row >= 1; row--)
    {
        //printing space
        for(col = 1; col <= n-row; col++)
        {
            cout <<(" ");
        }
        // printing *.
        for(col = 1; col <= 2*row-1; col++)
        {
            cout <<("*");
        }
        cout <<("\n");
    }
    return 0;
}

