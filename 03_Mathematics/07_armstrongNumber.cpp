/*
An Armstrong number is one whose sum of digits raised to the power three equals the number itself. 371, for example, is an Armstrong number because 3**3 + 7**3 + 1**3 = 371.
armStrong Number: 153 = 1^3 + 5 ^3 + 3^3 = 153.

*/
#include <iostream>
#include <string>

using namespace std;

int main()
{

    int num, temp;
    int sum = 0, rem;
    cout << "enter a num: ";
    cin >> num;

    temp = num;

    while (temp != 0)
    {
        rem = temp % 10;
        sum = sum + rem * rem * rem;
        temp = temp / 10;
    }
    if (sum == num)
    {
        cout << num <<" is armstrong" << endl;
    }
    else
    {
        cout <<num << " is not armstrong" << endl;
    }
    return 0;
}