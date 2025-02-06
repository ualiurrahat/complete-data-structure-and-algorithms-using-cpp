/*
Write a program that uses bitwise AND operator to check if a given positive integer is even or odd.
*/

#include <iostream>
using namespace std;

// optimal solution using bitwise technique
void checkOddEven(int n)
{
    if (n & 1)
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    return;
}
int main()
{
    // Write your code here
    int n;
    cout << "Enter a number: ";
    cin >> n;
    checkOddEven(n);
    return 0;
}