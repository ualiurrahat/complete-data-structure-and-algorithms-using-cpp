// Question: Reserve Books
// You are developing a reservation system for a library that allows students to reserve books.
// Each student can reserve multiple copies of the same book. Your task is to implement the reservation system
// which returns all the required books in ascending order of their title.
//
// Input Format:
// The first line of input contains an integer N — the size of both the vectors.
// The second line contains N space-separated strings - the title of books.
// The third line contains N space-separated positive integers - the reservations against each book.
//
// Output Format:
// Output on a single line K space-separated titles of the books in sorted alphabetical order - where K is the total reserved books.

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cassert>

using namespace std;

class Solution
{
public:
    multiset<string> reserveBooks(const vector<string> &bookTitles, const vector<int> &reservations)
    {
        multiset<string> result;                          // Multiset to store reserved book titles
        assert(bookTitles.size() == reservations.size()); // Ensure the sizes of both vectors are the same

        // Loop through each book title and corresponding reservation count
        for (int i = 0; i < bookTitles.size(); i++)
        {
            // Insert the book title multiple times as per the reservation count
            for (int j = 0; j < reservations[i]; j++)
            {
                result.insert(bookTitles[i]);
            }
        }

        return result; // Return the multiset containing reserved books sorted in alphabetical order
    }
};
