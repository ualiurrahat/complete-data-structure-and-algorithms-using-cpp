// write down a program to find factorial of a number.
// input : 5
// output: 120

#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n < 0)
    {
        cout << "factorial of negative number is undefined!";
        return -1;
    }
    int ans = 1;
    for(int i = 2; i <= n; i++)
    {
        ans = ans *i;
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial of " << n << " is = " << factorial(n) << endl;    
    return 0;
}