/* for n = 3, pattern would look like this,

        1
      1 2
    1 2 3
      1 2
        1
*/

#include <iostream>
using namespace std;

int main()
{
    int row,col,n;
    cout <<("enter n = ");
    cin >> n;

     for(row = 1; row <= n; row++)
    {
        // printing space.
        for(col = 1; col <= n - row; col++)
        {
            cout <<(" ");
        }
        // for printing value.
        for(col = 1; col <= row; col++)
        {
            cout <<col;
        }
        cout <<("\n");
    }
    // for decreasing part.
     for(row = n-1; row >= 1; row--)
    {
        for(col = 1; col <= row; col++)
        {
            cout <<col;
        }
        cout <<("\n");
    }
    return 0;
}
