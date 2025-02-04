/*You are given a number n and a position k.
toggle the kth bit. if it is 1, then write 0 and vice versa
ex: n = 13 = 1 1 0 1, k = 2
output = 1 0 0 1 = 9

brute force solution:
1. convert the number n into binary form
2. traverse in reverse order upto kth bit
3. toggle the bit

optimal solution:
1. left shift 1 up to k times
2. do xor of the above value with number n
ex:     13 = 1 1 0 1 = n,          k = 2
x = 1 << 2 = 0 1 0 0
----------------------------
    n ^ x  = 1 0 0 1
*/

#include <bits/stdc++.h>
using namespace std;

// optimal soltuion to toggle kth bit
int toggleKthBitOptimal(int n, int k)
{
    return (n ^ (1 << k));
    // T:O(1), S:O(1)
}
int main()
{
    int n, k;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter the bit position to clear the bit: ";
    cin >> k;
    int ans = toggleKthBitOptimal(n, k);
    cout << "input number: " << n << endl;
    cout << "output after toggling " << k << "th bit : " << ans << endl;

    return 0;
}