// Question:
// You are given N integers. Count the number of distinct integers among them.
//
// Input Format:
// The first line of each test case contains an integer N — the number of integers.
// The next line contains N space-separated integers.
//
// Output Format:
// Output on a new line the number of distinct integers.

#include <iostream> // For input and output operations
#include <set>      // For using the set container to store distinct elements

using namespace std;

int main()
{
    int n, a;
    set<int> S; // Set to store unique integers

    cin >> n; // Read the number of integers

    // Read N integers and insert them into the set
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        S.insert(a); // Inserts only unique elements
    }

    cout << S.size() << endl; // Print the count of distinct integers

    return 0; // Indicate successful program termination
}
