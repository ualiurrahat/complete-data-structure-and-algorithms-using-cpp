// this is the most general solution
#include <iostream>
using namespace std;

int findGCD(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (a % b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return b;
}
int main()
{
    int n;
    cout << "enter how many query you want: ";
    cin >> n;

    while (n--)
    {
        int a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;
        int gcd = findGCD(a, b);
        int lcm = (a * b) / gcd;
        cout << "GCD of " << a << " and " << b << " : " << gcd << endl;
        cout << "lcm of " << a << " and " << b << " : " << lcm << endl;
    }

    return 0;
}