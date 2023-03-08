
/* for n = 3. the pattern would look like

numeric pattern:    1 2 3
                    1 2
                    1

binary pattern:     1 0 1
                    1 0
                    1

alphabetic pattern: A B C
                    A B
                    A

asterisk pattern:   * * *
                    * *
                    *

*/

#include <iostream>
using namespace std;

int main()
{
    int row, col;
    int num;
    cout <<"enter N = ";
    cin >> num;

    // code for numeric pattern.
    for(row = num; row >= 1; row--)
    {
        for(col = 1; col <= row; col++)
        {
            cout <<col;
        }
        cout <<endl;
    }

    // code for binary pattern.
    cout <<endl;
    cout <<(" binary pattern.");
    cout <<endl;
    for(row = num; row >= 1; row--)
    {
        for(col = 1; col <= row; col++)
        {
            cout <<col%2;
        }
        cout <<endl;
    }

    // code for alphabetic pattern.
    char ch = char('a'-1);
    cout <<endl;
    cout <<("alphabetic pattern\n");
    for(row = num; row >= 1; row--)
    {
        for(col = 1; col <= row; col++)
        {
            cout <<char(col+ch);
        }
        cout <<endl;
    }

    // code for asterisk pattern.
    cout <<endl;
    cout <<("asterisk pattern:\n");
    for(row = num; row >= 1; row--)
    {
        for(col = 1; col <= row; col++)
        {
            cout <<"* ";
        }
        cout <<endl;
    }

    return 0;

}
