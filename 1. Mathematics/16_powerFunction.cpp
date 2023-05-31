// write a funciton to calculate a number(x) to the power of another number(y)
// ex: x = 2, y = 5
// output: 2^5 = 32
#include <iostream>
using namespace std;

int power(int a, int x)
{
    int ans = a;
    while(x > 1)
    {
        ans = ans*a;
        x--;
    }
    return ans;
}
int main()
{
    int baseNum, powerNum;
    cout << "Enter base and power number: ";
    cin >> baseNum >> powerNum;

    cout << baseNum << " to the power of " << powerNum << " is = " << power(baseNum, powerNum);
    
    return 0;
}