/* for n = 3, pattern would look like
    1
    1 2
    1 2 3

    same pattern for binary triangle would look like
    1
    1 0
    1 0 1

    alphabetic triangle would look like
    A
    A B
    A B C

    asterisk star would look like
    *
    * *
    * * *


    note: in binary triangle, you get 1 for odd and 0 for even numbers as remainder when you divide them with 2.
    */

#include <iostream>
using namespace std;

int main()
{
    int n, row, col;
    cout << ("Enter n = ");
    cin >> n;

    // code for numberic triangle.
    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= row; col++)
        {
            cout <<  col;
        }
        cout << endl;
    }

    cout << endl;
    cout << ("now we will do the same for binary right triangle\n");

    // code for binary triangle.
    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= row; col++)
        {
            cout << ( col % 2); // taking remainder value after division by 2.
        }
        cout << endl;
    }

    cout << endl;
    cout << ("now will do the same for alphabetic triangle\n");

    // code for alphabetic triangle.
    char ch = char('a'-1);
    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= row; col++)
        {
            cout << char( col + ch);
        }
        cout << endl;
    }

    cout << endl;
    cout << ("now will do the same for asterisk triangle\n");

    // code for asterisk triangle.
    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= row; col++)
        {
            cout << ("* ");
        }
        cout << endl;
    }

    return 0;
}
