// Permutation calculation
// write down a code to compute permutation vale
// ex: 5P2 = 20
#include <iostream>
using namespace std;

int nPr(int n, int r)
{
    // edge cases
    if(r>n || r < 0)
    {
        return 0;
    }
    int ans = 1;
    for(int i = 1; i <= r; i++)
    {
        ans = ans*n;
        n--;
    }
    return ans;
}
int main()
{
    int n, r;
    cout << "Enter n and r : ";
    cin >> n >> r;

    cout << n <<"P" << r << " = " << nPr(n,r) << endl;
    
    return 0;
}