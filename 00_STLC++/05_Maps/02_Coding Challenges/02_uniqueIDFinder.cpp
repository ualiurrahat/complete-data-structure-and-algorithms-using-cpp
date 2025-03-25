/*
Question:
You are given a vector of integers where each integer represents the ID of a user. However, there is exactly one user who has a duplicate ID. Your task is to find and return the ID of the user who has the duplicate ID.

Input Format:
- The first line of input contains an integer N — the number of IDs.
- The second line of input contains N space-separated integers - the IDs.

Output Format:
- Output on a single line, the duplicate ID.
*/

#include <iostream> // For input and output operations
#include <map>      // For storing ID frequencies
#include <cassert>  // For asserting the presence of exactly one duplicate

using namespace std;

int main()
{
    int n, duplicate_id, duplicates = 0;
    cin >> n; // Read the number of IDs

    map<int, int> id; // Map to store ID frequencies

    // Read IDs and track duplicates
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        id[x]++;
        if (id[x] > 1)
        { // If the ID appears more than once, it's the duplicate
            duplicates++;
            duplicate_id = x;
        }
    }

    assert(duplicates == 1); // Ensure there is exactly one duplicate

    cout << duplicate_id; // Output the duplicate ID

    return 0;
}
