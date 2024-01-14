/* for n = 3, pattern would look like this.
 * * *
 * * *
 * * *
 */
#include <iostream>
using namespace std;

int main()
{
    int n, row, col;
    cout << ("enter n = ");
    cin >> n;

    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= n; col++)
        {
            cout << ("* ");
        }
        cout << ("\n");
    }
    return 0;
}
