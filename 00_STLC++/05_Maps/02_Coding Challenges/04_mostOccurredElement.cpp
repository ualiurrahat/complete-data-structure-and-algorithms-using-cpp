// Question: Given n elements, print the element that occurs the maximum number of times.
// Input: A list of integers.
// Output: The element that occurs the maximum number of times and the count of occurrences.
//
// Example:
// Input: 18 1 8 1 20 1 13 1 14 14 1
// Output: 1 (5 times)

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cout << "Enter total elements: ";
    cin >> n; // Input the number of elements

    map<int, int> mpp; // Map to store element and its frequency
    int maxi = 0;      // Variable to track the element with maximum frequency

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x; // Input each element
        mpp[x]++; // Increment the frequency of the element

        // Update the element with the maximum frequency
        if (mpp[x] > mpp[maxi])
        {
            maxi = x;
        }
    }

    // Output the element that occurs most frequently and its count
    cout << "Most Occurred: " << maxi << " (" << mpp[maxi] << " times)" << endl;

    return 0;
}
