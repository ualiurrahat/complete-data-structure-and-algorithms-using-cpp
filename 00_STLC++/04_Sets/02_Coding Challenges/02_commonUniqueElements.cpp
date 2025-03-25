// Question:
// Given two vectors of integers, find the common unique elements which are present in both the vectors.
//
// Input Format:
// The first line of input contains two space-separated integers N and M — the number of integers in the first and second vectors.
// The next line contains N space-separated integers - integers in the first vector.
// The next (third) line contains M space-separated integers - integers in the second vector.
//
// Output Format:
// Output on a new line the K space-separated integers which are unique and common in both the vectors. Print them in sorted order.

#include <iostream> // For input and output operations
#include <set>      // For using the set container to store unique elements

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; // Read sizes of both vectors

    set<int> A, B; // Sets to store unique elements from both vectors

    // Read elements of the first vector and insert into set A
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.insert(x);
    }

    // Read elements of the second vector and check if they exist in A
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (A.count(x))
        { // If x is found in A, insert into B (common elements)
            B.insert(x);
        }
    }

    // Print the common unique elements in sorted order
    for (auto val : B)
    {
        cout << val << " ";
    }

    return 0; // Indicate successful program termination
}
