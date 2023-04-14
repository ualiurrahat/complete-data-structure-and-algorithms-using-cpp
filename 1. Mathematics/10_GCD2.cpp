// this is better approach to find gcd
// using Euclidean's GCD
// according to euclidean algorithm,
// if(a > b), then gcd(a,b) = gcd(b, a%b)
// if a == 0, then gcd = b
// and if b == 0, then gcd = a
#include <iostream>
using namespace std;

// better funciton to find GCD
// T:O((max(a,b)) )
int findGCDBetter(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
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
        int gcd = findGCDBetter(a, b);
        int lcm = (a * b) / gcd;
        cout << "GCD of " << a << " and " << b << " : " << gcd << endl;
        cout << "lcm of " << a << " and " << b << " : " << lcm << endl;
    }
    return 0;
}