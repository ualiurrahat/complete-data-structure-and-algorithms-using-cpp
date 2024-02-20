// find out sum of first n natural number recursively.
// input: 5
// output: 15 (since, sum = (n*(n+1)) / 2
// have to do it in recursive way.
#include <iostream>
using namespace std;

int sumOfFirstN(int n)
{
    // base case
    if (n < 1)
    {
        return 0;
    }
    // recursive call
    int smallAns = sumOfFirstN(n - 1);
    // small calculation
    smallAns = smallAns + n;

    return smallAns;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum of first " << n << " numbers is : " << sumOfFirstN(n) << endl;

    return 0;
}