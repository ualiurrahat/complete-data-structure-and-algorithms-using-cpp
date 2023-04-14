// this is the previous solution but in recursive way
#include <iostream>
using namespace std;

// recursive function to find GCD
// T: O(log(min(a,b)))
// S:O(log(min(a,b)))
int findGCDBetterRecursive(int a, int b)
{
    // edge case
    if (a < b)
    {
        return findGCDBetterRecursive(b, a);
    }
    // base case
    if (b == 0)
    {
        return a;
    }
    // reucurive call
    return findGCDBetterRecursive(b, a % b);
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
        int gcd = findGCDBetterRecursive(a, b);
        int lcm = (a * b) / gcd;
        cout << "GCD of " << a << " and " << b << " : " << gcd << endl;
        cout << "lcm of " << a << " and " << b << " : " << lcm << endl;
    }
    return 0;
}