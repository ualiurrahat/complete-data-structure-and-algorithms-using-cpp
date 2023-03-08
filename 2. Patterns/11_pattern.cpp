/* for n = 3, pattern would look like:

     * * * * *
       * * *
        *

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    int col, row;
    cout << ("enter n = ");
    cin >> n;

    for (row = n; row >= 1; row--)
    {
        // printing space.
        for (col = 1; col <= n - row; col++)
        {
            cout << (" ");
        }
        // printing *
        for (col = 1; col <= 2 * row - 1; col++)
        {
            cout << ("*");
        }
        cout << ("\n");
    }

    return 0;
}
