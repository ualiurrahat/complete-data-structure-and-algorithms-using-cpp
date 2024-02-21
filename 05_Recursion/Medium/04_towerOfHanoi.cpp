// move n disks from source A to destionation C with the help of helper B

#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char helper)
{
    // base case
    if (n == 1)
    {
        cout << "Move 1st disk to " << destination << " from " << source << endl;
        return;
    }

    // induction hypothesis:
    // move (n-1) disks to helper form source using destination
    towerOfHanoi(n - 1, source, helper, destination);
    // move nth disk to destination from source
    cout << "Move " << n << "th disk to " << destination << " from " << source << endl;

    // move those (n-1) disks from helper to destination using source
    towerOfHanoi(n - 1, helper, destination, source);
    // T:O(2^n - 1);
}

int main()
{
    towerOfHanoi(3, 'a', 'c', 'b');

    return 0;
}