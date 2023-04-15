// count the number of times an element appears in an array
// using STL
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int a[] = {1, 5, 7, 7, 8, 10, 10, 10, 11, 11, 12};
    // for x = 10 -- ans = 3
    // for x = 6 -- ans = 0;

    // for 10
    int upper = upper_bound(a, a + 11, 10) - a;
    int lower = lower_bound(a, a + 11, 10) - a;

    cout << "number of 10: " << upper - lower << endl;

    upper = upper_bound(a, a + 11, 6) - a;
    lower = lower_bound(a, a + 11, 6)-a;

    cout << "number of 6: " << upper - lower << endl;

    return 0;
}