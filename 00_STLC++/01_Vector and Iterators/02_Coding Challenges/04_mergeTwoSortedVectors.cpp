/*
    Task: Merge two sorted vectors or reverse the largest one

    Given two vectors of integers:
    - If both are sorted, merge them and print the merged vector.
    - Otherwise, print the elements of the larger vector in reverse order.

    Input Format:
    - The first line contains two space-separated integers: N (size of first vector) and M (size of second vector).
    - The second line contains N space-separated integers (first vector).
    - The third line contains M space-separated integers (second vector).

    Output Format:
    - If both vectors are sorted, print the merged vector (space-separated).
    - Otherwise, print the elements of the larger vector in reverse order.
*/

#include <iostream>
#include <vector>
#include <algorithm> // For is_sorted(), merge(), and reverse()

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; // Read sizes of the two vectors

    vector<int> a(n), b(m);

    // Read elements of the first vector
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Read elements of the second vector
    for (int i = 0; i < m; i++)
        cin >> b[i];

    // Check if both vectors are sorted
    if (is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end()))
    {
        // Merge the two sorted vectors
        vector<int> v(n + m);
        merge(a.begin(), a.end(), b.begin(), b.end(), v.begin());

        // Print the merged vector
        for (int i = 0; i < n + m; i++)
            cout << v[i] << " ";
    }
    else
    {
        // If vectors are not sorted, find the larger one and print it in reverse order
        if (n > m)
        {
            reverse(a.begin(), a.end());
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
        }
        else
        {
            reverse(b.begin(), b.end());
            for (int i = 0; i < m; i++)
                cout << b[i] << " ";
        }
    }

    return 0;
}
