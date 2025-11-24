/*
print from 1 to N recursively.
input: 5
output: 1 2 3 4 5
*/
#include <iostream>
using namespace std;

void printOneToN(int n)
{
    // base case
    if (n == 0)
    {

        return;
    }
    // recursive call
    printOneToN(n - 1);
    // small calculation: print numbers
    cout << n << " ";
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    printOneToN(n);

    return 0;
}