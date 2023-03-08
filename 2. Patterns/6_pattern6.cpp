/* for n = 3, pattern would look like this,
        1 2 3
        1 2
        1
        */

#include <iostream>
using namespace std;

int main()
{
    int row, col, n;
   cout <<("enter n = ");
    cin >> n;

    for(row = n; row >= 1; row--)
    {
        for(col = 1; col <= row; col++)
        {
           cout <<col;
        }
       cout <<("\n");
    }
    return 0;
}

