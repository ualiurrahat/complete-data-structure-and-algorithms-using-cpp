// Question:
// Alice, Bob, and Charlie participated in a 400-metre race.
// The time taken by Alice, Bob, and Charlie to complete the race was X, Y, and Z seconds respectively.
// Note that X, Y, and Z are distinct.
//
// Determine the person having the highest average speed in the race.
//
// Input Format:
// The first line of input will contain a single integer T, denoting the number of test cases.
// Each test case consists of multiple lines of input.
// The first line of each test case contains three space-separated integers X, Y, and Z —
// the time taken by Alice, Bob, and Charlie to complete the race.
//
// Output Format:
// For each test case, output on a new line:
// "ALICE", if Alice had the highest average speed.
// "BOB", if Bob had the highest average speed.
// "CHARLIE", if Charlie had the highest average speed.

#include <iostream> // For input and output operations
using namespace std;

int main()
{
    int t;
    cin >> t; // Read the number of test cases

    while (t--)
    { // Loop through all test cases
        int x, y, z;
        cin >> x >> y >> z; // Read the race completion times for Alice, Bob, and Charlie

        // The person with the least time has the highest average speed
        if (x <= y && x <= z)
            cout << "Alice" << endl; // Alice has the highest speed
        else if (y <= x && y <= z)
            cout << "Bob" << endl; // Bob has the highest speed
        else
            cout << "Charlie" << endl; // Charlie has the highest speed
    }

    return 0; // Indicate successful program termination
}
