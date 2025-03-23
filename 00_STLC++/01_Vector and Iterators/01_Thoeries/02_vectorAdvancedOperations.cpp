/*
    Topic: Advanced Vector Operations Using STL in C++

    This file covers:
    1. Various ways to traverse a vector (index, iterators, range-based for loop).
    2. Element access functions: at(), front(), back(), data().
    3. Modifiers: insert(), push_back(), pop_back(), erase(), clear(), swap().
    4. STL algorithms for vectors:
       - Finding the sum using accumulate().
       - Finding the max and min elements using max_element() and min_element().
       - Computing prefix sums using partial_sum().
    5. Swapping vectors.
    6. Replacing elements using replace().
    7. Merging two sorted vectors using merge().

    Note: This file focuses on STL functions. For basic vector operations, refer to '01_vectorBasics.cpp'.

    1. Vector is a sequence container, also known as Dynamic Array or Array List.
    2. Its size can grow and shrink dynamically, and no need to provide size in compile time.

    Note:
    - arr[index]: if index exceeds size of arr, compiler shows error.
    - arr.at(index): if index is greater than size, compiler throws an exception, not an error.
*/
#include <iostream>
#include <string>
#include <vector>    // header file for vectors
#include <algorithm> // to use max_element(), min_element(), replace(), merge() functions
#include <numeric>   // to use accumulate() and partial_sum() functions

using namespace std;

int main()
{
    // ways of traversing a vector.
    vector<int> v = {1, 2, 3};

    // way 1: using index position through square brackets []
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // way 2: using iterator
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // way 3: using for(auto) loop
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;

    vector<int> v2 = {10, 20, 30};

    // swap two vectors.
    swap(v, v2);

    cout << "v: ";
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;
    cout << "v2: ";
    for (auto element : v2)
    {
        cout << element << " ";
    }
    cout << endl;

    // sum of vector
    int sum1 = accumulate(v.begin(), v.end(), 0); // 0 = initial value of sum1
    cout << "Sum of v: " << sum1 << endl;

    // *max_element returns pointer to the max element
    int mx1 = *max_element(v.begin(), v.end());
    // *min_element returns pointer to the min element
    int mn1 = *min_element(v.begin(), v.end());

    cout << "Max of v: " << mx1 << endl;
    cout << "Min of v: " << mn1 << endl;

    // to convert the vector into a prefix sum vector.
    partial_sum(v.begin(), v.end(), v.begin());
    cout << "Prefix Sum Vector: ";
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;

    // Replacing elements in a vector
    vector<int> replace_vec = {2, 3, 5, 6, 3};
    replace(replace_vec.begin(), replace_vec.end(), 3, 8); // Replace all occurrences of 3 with 8
    cout << "Vector after replace(): ";
    for (auto element : replace_vec)
    {
        cout << element << " "; // Output: 2 8 5 6 8
    }
    cout << endl;

    // Merging two sorted vectors
    vector<int> v1 = {1, 2, 3};
    vector<int> v2_merge = {2, 2, 3, 4};
    vector<int> v3(v1.size() + v2_merge.size()); // Size must be v1.size() + v2_merge.size()
    merge(v1.begin(), v1.end(), v2_merge.begin(), v2_merge.end(), v3.begin());

    cout << "Merged Vector: ";
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " "; // Output: 1 2 2 2 3 3 4
    }
    cout << endl;

    return 0;
}
