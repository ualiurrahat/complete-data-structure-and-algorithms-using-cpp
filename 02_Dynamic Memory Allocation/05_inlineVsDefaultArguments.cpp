#include <bits/stdc++.h>

using namespace std;

inline int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

// function with default value of the parameter
int sum(int a, int b, int c = 0, int d = 0)
// c and d are given default value
// if user doesn't give any value. it will assume value as 0 by default
// note***: start from the rightmost position to assign default value of paramters
{
    return a + b + c + d;
}

int main()
{
    int a = 18;
    int b = 20;
    int c = 1;
    int d = 5;

    int e = max(a, b);
    int f = max(c, d);

    /* when we call a normal function, the function gets invoked.
    it performs instructions defined by user.

    but in inline function, the function is not call actually.
    the line of function call gets replaced by its body.
    So inline function works faster than normal function.

    .....for inline....its like below:
    int e = max(a,b) gets replaced by this int e = (a > b) ? a : b;

    ....for normal function it gets like this....
    int e = max(a,b); then, int e = max(int a, int b).....


*/

    // sum works fine for 2,3,4 var addition
    cout << sum(25, 8) << endl;
    cout << sum(25, 8, 9) << endl;     //c = 9, d = 0
    cout << sum(25, 8, 9, 10) << endl; // c = 9, d = 10

    return 0;
}