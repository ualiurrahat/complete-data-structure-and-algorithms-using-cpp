#include <iostream>
using namespace std;

int fibo(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    
    int fibo1 = fibo(n-1);
    int fibo2 = fibo(n-2);
    int ans = fibo1 + fibo2;
    return ans;
}
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << fibo(n) << endl;
    
    return 0;
}