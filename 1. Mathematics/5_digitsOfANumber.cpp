// Print the digits of a number in new line

#include <iostream>
#include <cmath>
using namespace std;

// function to print digits of a number
void printDigits(int n)
{
    // 1. find the total no. of digits in a number
    int  totaldigits = 0;
    int temp = n;
    while (temp)
    {
        temp = temp / 10;
         totaldigits++;
    }
    // 2. the divisor will be a power 10 to the (digits -1)
    int divisor = pow(10, totaldigits-1);
    // 3. loop to print digits. loop will end when divisor becomes zero
    while(divisor != 0)
    {
        // divide n with divisor. the quotient is the digit
        int digit = n / divisor;
        // update i.e minimize n as we get each digit
        n = n % divisor;
        // print the digit
        cout << digit << endl;
        // update the divisor dividing by 10
        divisor = divisor / 10;
        // minimize n 
        

    }
}
int main()
{

    // take a number from user
    int n;
    cout << "Enter a number: ";
    cin >> n;

    printDigits(n);
    return 0;
}