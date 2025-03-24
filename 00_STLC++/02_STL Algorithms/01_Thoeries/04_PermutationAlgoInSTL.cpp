
#include <iostream>
#include <algorithm>
#include <vector>
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
    /*next_permutation() rearranges the elements in a range into the next lexicographically greater permutation. If the current permutation is the largest possible, it rearranges the elements to the smallest possible permutation and returns false, otherwise returns true.

Time Complexity: O(n), where n is the number of elements in the range.*/

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

    // do not try this in interview. use this in CP

    /*prev_permutation() rearranges the elements in a range into the next lexicographically smaller permutation. If the current permutation is the smallest possible, it rearranges the elements to the largest possible permutation and returns false, otherwise returns true.

Time Complexity: O(n), where n is the number of elements in the range.*/
    // prev permutations
    vector<int> vec = {3, 2, 1};
    do
    {
        for (int num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    } while (prev_permutation(vec.begin(), vec.end()));

    return 0;
}