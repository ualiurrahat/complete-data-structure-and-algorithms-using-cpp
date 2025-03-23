// Demonstrating the use of nested vectors with pairs in C++

#include <iostream>
#include <utility> // For using std::pair
#include <vector>  // For using std::vector
using namespace std;

// Function to print the contents of a vector of pairs
void printVec(vector<pair<int, int>> &v)
{
    cout << "size : " << v.size() << endl; // Printing the size of the vector

    // Iterating through the vector and printing each pair
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl; // Accessing and printing the pair values
    }
    cout << endl; // New line for better readability
}

int main()
{
    // Initializing a vector of pairs with predefined values
    vector<pair<int, int>> v = {{1, 10}, {2, 20}, {3, 30}};

    // Printing the vector of pairs
    printVec(v);

    // Taking user input to create a vector of pairs dynamically
    int n; // Variable to store the number of pairs
    cout << "Enter total no. of pairs: ";
    cin >> n;

    vector<pair<int, int>> p; // Declaring a vector to store user-input pairs

    cout << "Enter pair values: ";
    // Loop to take n pairs as input from the user
    for (int i = 0; i < n; i++)
    {
        int x, y; // Variables to store pair values

        cin >> x >> y; // Taking input for each pair

        p.push_back({x, y}); // Adding the pair to the vector
        // Equivalent to: p.push_back(make_pair(x, y));
    }

    // Printing the user-input vector of pairs
    printVec(p);

    return 0;
}
