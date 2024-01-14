// Combination Calculation.
// write a function to calculate combination value
// ex: 6C3 = 20;

#include <iostream>
using namespace std;

int nCr(int n, int r)
{
    // edge cases
    if(r > n)
    {
        return 0;
    }
    else if(r == 0 || r == 1)
    {
        return 1;
    }
    int ans = 1;
    for(int i = 1; i <= r; i++)
    {
        ans = ans*n;
        n--;
    }
    for(int i = 2; i <= r; i++)
    {
        ans = ans / i;
    }
    return ans;

}
int main()
{
     int n, r;
    cout << "Enter n and r : ";
    cin >> n >> r;

    cout << n <<"C" << r << " = " << nCr(n,r) << endl;
    
    
    return 0;
}