// next permutation
// string s = "abc"

// next Perumtutaion = "acb"
// all permutation follows:
// abc
// acb
// bac
// bca
// cab
// cba

// s = "abc"
// bool res = next_permutation(s.begin(), s.end());
// s becomes "acb" and res = true

// s = "cba"
// bool res = next_permutation(s.begin(), s.end());
// s remains "cba" as no more permutation is possible
// res = false

#include <bits/stdc++.h>

using namespace std;

int main()
{

    // print all the permutaton of a string
    string s = "bca";
    sort(s.begin(), s.end());

    do
    {
        cout << s << endl;

    } while (next_permutation(s.begin(), s.end()));

    // do not try this in interview. use this in CP

    // prev permutations
    // bool res = prev_permutation(s.begin(), s.end());

    return 0;
}