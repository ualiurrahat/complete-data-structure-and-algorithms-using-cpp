/*
print factors of a number
ex: factors of 12 are 1,2,3,4,6,12.
*/
#include <iostream>
#include <string>

using namespace std;

void findFactors(int n)
{

    cout << "Factors: 1 ";
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << n << endl;
}

int main()
{

    int n;
    cout << "enter a number: ";
    cin >> n;
    findFactors(n);
    return 0;
}