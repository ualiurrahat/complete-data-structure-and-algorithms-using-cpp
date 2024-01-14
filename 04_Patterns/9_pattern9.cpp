/* for n = 4, pattern would look like this,
        1
        2 4
        3 6 9
        4 8 12 16

        */
#include <iostream>
using namespace std;

int main()
{
    int n,row,col;
    cout <<("enter n = ");
    cin >> n;

    for(row = 1; row <= n; row++)
    {
        for(col = 1; col <= row; col++)
        {
            cout << row*col << " ";
        }
        cout <<("\n");
    }
    return 0;
}
