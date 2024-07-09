/*
Printing n terms of fibonacci series with starting terms 0, 1.
Condition: do not use array.

*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cout << "Enter the th term of fibo series you wanna see: ";
    cin >> n;
    if (n == 1)
    {
        cout << "0 " << endl;
    }
    else if (n == 2)
    {
        cout << "0 1 " << endl;
    }
    else 
    {
        int a = 0, b = 1, current_fibo, i = 3;
        cout << a << " " << b << " ";
        while (i <= n)
        {
            current_fibo = a + b;
            cout << current_fibo << " ";
            a = b;
            b = current_fibo;
            i++;
        }
    }

    return 0;
}