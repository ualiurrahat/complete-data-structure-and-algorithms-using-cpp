/*
    Problem Statement:
    Pain is the leader of a secret organization aiming to destroy Konoha. Naruto, the village head, is not in a condition to fight.
    The village's fate rests on the soldiers who have sworn loyalty to him.
    Each soldier has an attack power Ai. When attacking Pain, his strength (Z) reduces by Ai, but Ai is halved after each attack.
    Soldiers can attack any number of times (including zero). The goal is to determine the minimum number of attacks needed
    to reduce Pain's strength to 0 or less. If it's not possible, output "Evacuate".

    Input Format:
    - The first line contains an integer T (number of test cases).
    - Each test case consists of:
      - Two integers N (number of soldiers) and Z (Pain's strength).
      - N space-separated integers representing the attacking power of each soldier.

    Output Format:
    - Print the minimum number of attacks required, or "Evacuate" if it's not possible.
*/

#include <iostream> // For input and output operations
#include <set>      // For multiset data structure
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        int n, z; // Number of soldiers and Pain's initial strength
        cin >> n >> z;
        multiset<int> m_set; // Multiset to store soldier powers in sorted order

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            m_set.insert(x); // Insert each soldier's power into the multiset
        }

        int min_moves = 0; // Counter for the number of attacks

        // While there are soldiers and Pain's strength is still greater than 0
        while (!m_set.empty() && z > 0)
        {
            min_moves++;
            int temp = *m_set.rbegin(); // Get the strongest soldier's power (last element of multiset)
            m_set.erase(--m_set.end()); // Remove that element from the multiset

            /*
                Explanation of `m_set.erase(--m_set.end());`
                - `m_set.end()` gives an iterator **past the last element**.
                - `--m_set.end()` moves it back to point to the **last element**.
                - `m_set.erase(--m_set.end());` removes the **largest element** efficiently.

                Alternative way:
                ```cpp
                auto it = m_set.end();
                it--;              // Move back to the last element
                m_set.erase(it);   // Remove the largest element
                ```
            */

            z -= temp; // Reduce Pain's strength
            temp /= 2; // Halve the soldier's power

            if (temp > 0)
                m_set.insert(temp); // Reinsert if it's still greater than zero
        }

        // If Pain's strength is reduced to 0 or below, print the number of attacks
        if (z <= 0)
        {
            cout << min_moves << endl;
        }
        else
        {
            cout << "Evacuate" << endl; // If Pain cannot be defeated, print "Evacuate"
        }
    }
    return 0;
}
