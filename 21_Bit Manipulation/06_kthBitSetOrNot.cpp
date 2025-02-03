/*Given a number ‘N’ and a number ‘K’.
Return true if ‘K’th bit of number is set, else return false.
Here, K is a 0-based indexing

(1)brute force solution:
step 1: convert the given number into its binary form
step 2: then iterate in revere order(right to left) and check if kth bit is '1' or not.

(2) optimal solution using Left Shift (<<) Operator
step 1: Do left shift of 1 up to k times
    int x =1 << k;
step 2: then check if number & x == 1, then kth bit is set i.e. 1
        if number & x == 0, then kth bit is not set i.e. 0
How it works?
sol: let's take n = 13 and k = 2
    x = 1 << k = 1 << 2 = 4 = 0 0 0 0 0 1 0 0
    n = 13 = 0 0 0 0 1 1 0 1
         x = 0 0 0 0 0 1 0 0
-------------------------------------
(n & x )   = 0 0 0 0 0 1 0 0 (only kth bit will produce non 0, if kth bit is 1)
otherwise, if kth bit is 0, n&x = n & (1 << k) will always be 0
for n = 13 and k = 1, i = 1 << 1 = 2;
  n = 13 = 0 0 0 0 1 1 0 1
       x = 0 0 0 0 0 0 1 0
---------------------------------
n & x    = 0 0 0 0 0 0 0 0 (0 because kth bit = 1th bit is 0)

(3) optimal solution using Right Shift ( << ) Operator
step 1: shift the number n to right up to k times
    n >> k;
step 2: check n & 1
        if( n & 1) == 1, kth bit is set
        otherwise, kth bit is not set.
ex: n = 13, k = 2;
        n >> 2 = 13 >> 2 = 3 = 0 0 0 0 0 0 1 1
                           1 = 0 0 0 0 0 0 0 1
----------------------------------------------------
                    (n&1)    = 0 0 0 0 0 0 0 1
                    if kth bit is set, n&1 will always be non zero
                    otherwise, it will always be zero. so bit is not set then.
*/
#include <bits/stdc++.h>
using namespace std;

// optimal soltution using left shitf operator
bool isKthBitSet1(int n, int k)
{
    if ((n & (1 << k)) != 0)
    {
        return true;
    }
    // kth bit not set
    return false;
}
// optimal solution using right shift operator
bool isKthBitSet2(int n, int k)
{
    n = n >> k;
    if (n & 1)
    {
        return true;
    }
    return false;
}
int main()
{

    int n, k;
    cout << "Enter a number: ";
    cin >> n;
    cout << endl
         << "Enter the bit position (0 based you want to check): ";
    cin >> k;

    // bool ans = isKthBitSet1(n, k);
    // if (ans == true)
    // {
    //     cout << "In " << n << ", " << k << "th bit is set " << endl;
    // }
    // else
    // {
    //     cout << "In " << n << ", " << k << "th bit is not set " << endl;
    // }
    bool ans = isKthBitSet2(n, k);
    if (ans == true)
    {
        cout << "In " << n << ", " << k << "th bit is set " << endl;
    }
    else
    {
        cout << "In " << n << ", " << k << "th bit is not set " << endl;
    }
    return 0;
}