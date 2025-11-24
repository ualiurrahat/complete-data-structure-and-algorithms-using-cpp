/*count no. of a digits recursively*/
#include <iostream>

using namespace std;

// recursive function to count no. of digits
int countDigit(long long x)
{
    // base case
    if (x == 0)
    {
        return 0;
    }
    int smallCount = countDigit(x / 10);
    return smallCount + 1;
}

int main()
{
    int num;
    cout << "Enter a number: " << endl;
    cin >> num;
    cout << "total no. of digits : " << countDigit(num) << endl;
}