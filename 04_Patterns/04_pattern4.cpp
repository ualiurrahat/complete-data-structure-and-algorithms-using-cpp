/* for n = 3, pattern would look like it,
        1
        1 2
        1 2 3
        1 2 3
        1 2
        1

        same number would look like this.
        1
        2 2
        3 3 3
        2 2
        1

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    int row, col;
    cout << "enter n = ";
    cin >> n;

    // code for ascending sequence.
    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= row; col++)
        {
            cout << "%d ", col;
        }
        cout << endl;
    }
    // code for descending sequence.
    for (row = n - 1; row >= 1; row--)
    {
        for (col = 1; col <= row; col++)
        {
            cout << col;
        }
        cout << endl;
    }

    cout << endl;
    cout << "code for same number: \n";

    // code for same number.
    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= row; col++)
        {
            cout << row;
        }
        cout << endl;
    }

    for (row = n - 1; row >= 1; row--)
    {
        for (col = 1; col <= row; col++)
        {
            cout << row;
        }
        cout << endl;
    }

    return 0;
}
