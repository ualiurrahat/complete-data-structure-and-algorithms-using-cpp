// print all the prime factors of a number.
// ex: for number 12, output: 2, 2, 3

#include <iostream>
using namespace std;

void printPrimeFactors(int n)
{
    for (int div = 2; div * div <= n; div++)
    {
        while (n % div == 0)
        {
            cout << div << " ";
            n = n / div;
        }
    }
    if (n != 1)
    {
        cout << n;
    }
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime factors of " << n << " : ";
    printPrimeFactors(n);

    return 0;
}