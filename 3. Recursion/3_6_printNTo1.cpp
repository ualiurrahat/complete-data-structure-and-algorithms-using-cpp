/*
print N to number 1 recursively.
input: 5
output: 5 4 3 2 1
*/
#include <iostream>
using namespace std;

void printNumberFromNToOne(int n)
{
    // base case
    if(n == 0)
    {
        return;
    }
    // small calculaiton: print numbers
    cout << n << " ";
    // recursive call
    printNumberFromNToOne(n-1);
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    printNumberFromNToOne(n);
    
    return 0;
}