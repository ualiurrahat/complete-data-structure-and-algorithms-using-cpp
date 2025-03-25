// Question:
// Given two sets of integers, A and B, check if B is a subset of A or not.
//
// Note: A set X is a subset of a set Y if all elements of X are also elements of Y.
//
// Input Format:
// The first line of input contains two space-separated integers N and M — the number of integers in set A and set B respectively.
// The next line contains N space-separated integers - integers in set A.
// The next (third) line contains M space-separated integers - integers in set B.
//
// Output Format:
// Output on a single line YES if set B is a subset of set A, else NO.

#include <iostream> // For input and output operations
#include <set>      // For using the set container to store unique elements
#include <cassert>  // For assertions

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; // Read sizes of both sets

    set<int> A, B; // Sets to store unique elements

    // If B has more elements than A, it cannot be a subset
    if (n < m)
    {
        cout << "NO";
        return 0;
    }

    // Read elements of set A
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.insert(x);
    }

    bool isSubset = true; // Flag to track if B is a subset of A

    // Read elements of set B and check if they exist in A
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (!A.count(x))
        { // If x is not in A, B is not a subset
            isSubset = false;
        }
        B.insert(x);
    }

    // Validate that set sizes match expected input counts
    assert(A.size() == n);
    assert(B.size() == m);

    // Output the result
    cout << (isSubset ? "YES" : "NO");

    return 0; // Indicate successful program termination
}
