#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// The Enchanted Locket Problem
// Luna Lovegood found a mysterious locket in the Room of Requirement.
// Harry Potter wants to ensure that no one else has been influenced by this enchanted locket before Luna.
// Given a list of N names of people who held the locket in sequence, determine if they held the locket at any point before.

// Input:
// The first line of input contains an integer N — names of people.
// The next N lines contain the name of people, each on a separate line.

// Output:
// For each name si at the ith position in the list, output on a separate line:
// Output YES if there exists an earlier position j (j < i) where sj = si.
// Otherwise, output NO.

int main()
{
    int n;
    cin >> n; // Read the number of people holding the locket

    unordered_map<string, bool> mpp; // Declare a map to store the names and check if they appeared before
    vector<string> person(n);        // Vector to store the names in order

    // Iterate over the list of names
    for (int i = 0; i < n; i++)
    {
        cin >> person[i]; // Read each person's name

        // Check if this name has appeared before using the unordered_map
        if (mpp.find(person[i]) != mpp.end())
        {
            cout << "YES" << endl; // If found, output YES (the name was held before)
        }
        else
        {
            cout << "NO" << endl;  // If not found, output NO (the name is appearing for the first time)
            mpp[person[i]] = true; // Mark this name as having been seen
        }
    }
    return 0;
}
