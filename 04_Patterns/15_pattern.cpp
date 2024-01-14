/* for n = 5, pattern would look like this,

     * * * * *
     *       *
     *       *
     *       *
     * * * * *

     */

#include <iostream>
using namespace std;

int main()
{
    int n;
    int row, col;
   cout <<("enter n = ");
   cin >> n;

    for(row = 1; row <= n; row++)
    {
        for(col = 1; col <= n; col++)
        {
            if(row == 1 || row == n || col == 1 || col == n)
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
