/* for n = 5 , pattern would look like this......
   *    *
    *  *
     *
   *  *
 *      *


 the X symbol...

 */

#include <iostream>
using namespace std;
int main()
{
    int n, row, col;
    cout << "Enter n = ";
    cin >> n;

    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= n; col++)
        {
            if (row == col || row + col == (n+1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
