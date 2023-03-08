
/* for n= 4, pattern would look like this.
         *
        * *
       * * *
      * * * *

      */
#include <iostream>
using namespace std;
int main()
{
    int n, row, col;
    cout <<("enter n = ");
   cin >> n;

    for(row = 1; row <=n; row++)
    {
        // for space
        for(col =1; col <= n-row; col++)
        {
            cout <<(" ");
        }
        // for *
        for(col = 1; col <=row; col++)
        {
            cout <<("* ");
        }
        cout <<("\n");
    }


    return 0;
}
