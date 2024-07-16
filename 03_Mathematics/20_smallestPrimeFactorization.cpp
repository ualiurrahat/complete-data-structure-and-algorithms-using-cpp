// for a given number n, print out all its prime factors
// ex: input = 780
// output = 2,2,2,2,3,5,5
#include <bits/stdc++.h>
using namespace std;

// brute force
vector<int> solutionBrute(int n)
{
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                ans.push_back(i);
                n = n / i;
            }
        }
    }
    if (n > 1) // If n is a prime number greater than 1
    {
        ans.push_back(n);
    }
    return ans;
}

int main()
{
    int n = 780;
    // vector<int> output = solutionBrute(n);
    vector<int> ans = solutionBrute(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}