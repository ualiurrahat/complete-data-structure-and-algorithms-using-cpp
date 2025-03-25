// Question:
// You are given a set of 2D coordinates represented as pairs of integers (x, y).
// Complete the given C++ function that sorts these coordinates based on their distance from the origin (0, 0).
//
// The distance of a coordinate from the origin is calculated as the Euclidean distance: √(x^2 + y^2).
//
// Complete the function with the following signature:
// vector<pair<int, int>> sortCoordinates(const vector<pair<int, int>>& coordinates)
// The function should return a new vector containing the input coordinates sorted in ascending order of their distance from the origin.
//
// Your solution should be efficient, with a time complexity better than O(n^2).
//
// Input Format:
// The first line of input will contain a single integer N, denoting the number of coordinates.
// Each of the next N lines consists of two integers: x and y, the coordinates of the i-th 2D point.
//
// Output Format:
// Print on N new lines, the coordinates sorted by distance from origin.

#include <iostream>  // For input and output operations
#include <vector>    // For using the vector container
#include <algorithm> // For sorting function

using namespace std;

// Function to calculate the squared Euclidean distance from the origin
long long distance_squared(int x, int y)
{
    return 1LL * x * x + 1LL * y * y; // Avoids floating-point calculations for efficiency
}

// Function to sort coordinates based on their distance from the origin
vector<pair<int, int>> sortCoordinates(const vector<pair<int, int>> &coordinates)
{
    int n = coordinates.size();
    vector<pair<int, int>> result;          // Stores sorted coordinates
    vector<pair<long long, int>> distances; // Stores distance along with index

    // Compute distances and store them with indices
    for (int i = 0; i < n; i++)
    {
        distances.push_back({distance_squared(coordinates[i].first, coordinates[i].second), i});
    }

    // Sort the distances in ascending order
    sort(distances.begin(), distances.end());

    // Arrange coordinates based on sorted distances
    for (int i = 0; i < distances.size(); i++)
    {
        result.push_back(coordinates[distances[i].second]);
    }

    return result;
}

int main()
{
    int n, x, y;
    cin >> n; // Read the number of coordinates
    vector<pair<int, int>> coordinates;

    // Read input coordinates
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        coordinates.push_back({x, y});
    }

    // Sort coordinates by distance from the origin
    coordinates = sortCoordinates(coordinates);

    // Print the sorted coordinates
    for (int i = 0; i < n; i++)
    {
        cout << coordinates[i].first << " " << coordinates[i].second << endl;
    }

    return 0; // Indicate successful program termination
}
