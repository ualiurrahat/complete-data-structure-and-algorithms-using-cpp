#include <iostream>
#include <vector>
using namespace std;

// Template function to print a vector of vectors
// This function takes a 2D vector and prints its elements in a structured format
// Templated to support different data types
template <class T>
void printVector(vector<vector<T>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Displaying vector " << i + 1 << ": ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter how many vectors you want to take: ";
    cin >> n;

    // Declaring a vector of vectors to store multiple vectors
    vector<vector<int>> v;

    // Loop to take input for 'n' vectors
    for (int i = 0; i < n; i++)
    {
        cout << "Enter size of vector number " << i + 1 << " : ";
        int size;
        cin >> size;

        // Temporary vector to store individual vector elements
        vector<int> a;

        // Alternative way: directly push an empty vector into 'v' before input
        // v.push_back(vector<int>());

        cout << "Enter elements for vector " << i + 1 << ": ";
        for (int j = 0; j < size; j++)
        {
            int x;
            cin >> x;
            a.push_back(x);

            // Alternative way: directly push into v[i]
            // v[i].push_back(x);
        }
        v.push_back(a); // Store the current vector in the 2D vector
    }

    // Function call to print the 2D vector
    printVector(v);

    // Displaying size of the entire 2D vector
    cout << "Total number of vectors: " << v.size() << endl;

    // Displaying sizes of individual vectors inside the 2D vector
    if (!v.empty())
    {
        cout << "Size of first vector: " << v[0].size() << endl;
        if (v.size() > 1)
            cout << "Size of second vector: " << v[1].size() << endl;
        if (v.size() > 2)
            cout << "Size of third vector: " << v[2].size() << endl;
    }

    return 0;
}
