/* for n=5, pattern would look like this

    *
    **
    *  *
    *    *
    * * * *
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    int col, row;

    cout <<("enter n = ");
    cin >> n;

    for(row = 1; row <= 5; row++)
    {
        for(col = 1; col <= n; col++)
        {
            if(col == 1 || row ==n || row==col)
            {
                cout <<("*");
            }
            else
            {
                cout <<(" ");
            }
        }
        cout <<("\n");
    }


    return 0;

}


