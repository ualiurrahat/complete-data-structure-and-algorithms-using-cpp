// hw:
// 1. given n elements, print the elements that occurs maximum number of times.
// input: 18 1 8 1 20 1 13 1 14 14 1
// ouput: 1(5 times)
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cout << "enter total elements: ";
    cin >> n;
    map<int, int> mpp;
    int maxi = 0;

    int x;
    for (int i = 0; i < n; i++)
    {

        cin >> x;
        mpp[x]++;
        if (mpp[x] > mpp[maxi])
        {
            maxi = x;
        }
    }
    cout << "Most Occured: " << x << endl;

    return 0;
}