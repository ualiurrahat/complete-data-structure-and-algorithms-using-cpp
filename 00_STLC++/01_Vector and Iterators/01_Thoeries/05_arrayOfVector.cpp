// Demonstrating the use of an array of vectors in C++

#include <iostream>
#include <vector> // For using std::vector
using namespace std;

// Template function to print a vector of any data type
template <class T>
void printVector(vector<T> &v)
{
    // Iterating through the vector and printing elements
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl; // New line for better readability
}

int main()
{
    int n; // Variable to store the number of arrays (vectors)
    cout << "Enter total no. of arrays in the vector: ";
    cin >> n;

    // Declaring an array of vectors with size n
    vector<int> v[n];

    // Explanation:
    // - `vector<int> v[n]` is an array of vectors.
    // - It behaves like a 2D array but with flexible column sizes.
    // - Unlike `int arr[10][10]` which has fixed row and column sizes,
    //   here each row (vector) can have a different number of elements.

    // Loop to take input for each vector in the array
    for (int i = 0; i < n; i++)
    {
        cout << "Enter size of the vector " << i + 1 << " : ";
        int size;
        cin >> size;

        cout << "Enter the vector elements: ";

        // Fill up the i-th vector
        for (int j = 0; j < size; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x); // Adding elements to the current vector
        }
    }

    // Printing all the vectors
    for (int i = 0; i < n; i++)
    {
        printVector(v[i]); // Calling the function to print each vector
    }

    return 0;
}
