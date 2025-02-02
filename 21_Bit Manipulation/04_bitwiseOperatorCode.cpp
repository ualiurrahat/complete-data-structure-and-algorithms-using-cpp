#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int andValue = a & b;
    cout << a << " & " << b << " = " << andValue << endl;

    int orValue = a | b;
    cout << a << " | " << b << " = " << orValue << endl;

    int xorValue = a ^ b;
    cout << a << " ^ " << b << " = " << xorValue << endl;

    int rightShift = a >> 2;
    // right shifting a by 2
    cout << a << " >> 2 (right shift by 2)= " << rightShift << endl;
    // left shifting b by 3
    int leftShift = b << 3;
    cout << b << " << (left shift by 3) = " << leftShift << endl;

    // not operator value for 13
    int notValue = 13;
    notValue = ~notValue;
    cout << "(~13) = " << notValue << endl;
    return 0;
}