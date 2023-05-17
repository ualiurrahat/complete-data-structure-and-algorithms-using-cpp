// you will be given a number , and you have to write the digits of the number in English form
// ex: 412 -> four one two
#include <bits/stdc++.h>

using namespace std;
void sayDigit(int n, string arr[])
{
    // base case
    if (n == 0)
    {
        return;
    }
    // calculation
    int digit = n % 10;
    n = n / 10;
    // recursive call
    sayDigit(n, arr);
    cout << arr[digit] << " ";
}

int main()
{

    string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    sayDigit(123, num);
    cout << endl;
    sayDigit(412, num);
    cout << endl;
    return 0;
}