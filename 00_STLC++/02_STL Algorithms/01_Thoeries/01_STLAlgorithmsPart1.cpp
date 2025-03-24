// This program demonstrates various sorting and manipulation techniques on vectors and arrays using STL algorithms.
// It includes sorting in ascending and descending order, reverse, stable_sort, max_element, min_element, partial_sort, and merging two vectors.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// function to print a vector
template <class T>
void printVec(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {25, 31, 8, 1, 13, 7, 9, 22, 17};

    cout << "Input vector: ";
    printVec(v);

    // sort: sort the container in ascending order
    cout << "vector in ascending order: ";
    sort(v.begin(), v.end());
    printVec(v);
    cout << endl;

    // now sorting in descending order.
    cout << "vector in descending order: ";
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << endl;

    // reverse.
    cout << "reversed vector: ";
    reverse(v.begin(), v.end());
    printVec(v);
    cout << endl;
    /*stable_sort() is similar to sort(), but it ensures that the relative order of
     equal elements remains unchanged after sorting.

      syntax: stable_sort(start_iterator, end_iterator, comparison_function);
     */
    /*Use sort() when performance is critical and stability is not required.
    Use stable_sort() when stability is important ( sorting by multiple keys, such as sorting first by age, then by name).*/
    stable_sort(v.begin(), v.end()); // Sorts vec in ascending order
    cout << "vector after performing stable sort: ";
    printVec(v);
    cout << endl;
    // max and min value.
    // returns an iterator in case of vector
    auto it = max_element(v.begin(), v.end());
    cout << "max : " << (*it) << endl;

    auto iter = min_element(v.begin(), v.end());
    cout << "min : " << (*iter) << endl;

    /*partial_sort() partially sorts the range such that the smallest k elements are sorted in ascending order.
    Time Complexity: O(n log k), where n is the number of elements and k is the number of elements to sort.
    partial_sort(start_iterator, middle_iterator, end_iterator, comparison_function);
    */
    vector<int> ur = {18, 1, 8, 5, 20, 7, 13, 32, 100};
    partial_sort(ur.begin(), ur.begin() + 3, ur.end()); // Sorts the smallest 3 elements
    cout << "vector ur after partial sorting up to 3 elements: ";
    printVec(ur);

    // merging two vectors.
    vector<int> v1 = {70, 80, 90, 100};

    vector<int> v3(v1.size() + v.size());
    merge(v.begin(), v.end(), v1.begin(), v1.end(), v3.begin());

    cout << "\nmerging vector: ";
    printVec(v3);
    cout << endl;

    // sort array using the sort algo
    int arr[] = {1, 7, 4, 2};
    int n = 4;

    // ascending order
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, arr + n, greater<int>());

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    /*nth_element(): element at the nth position is in its correct sorted position,
     and all elements before it are less than or equal to it,
      while all elements after it are greater than or equal to it.
    Complexity: O(n) on average.

    syntax: nth_element(start_iterator, nth_iterator, end_iterator, comparison_function);
*/
    vector<int> kb = {3, 1, 4, 2, 5};
    nth_element(kb.begin(), kb.begin() + 2, kb.end()); // place the 3rd smallest element in right position
    cout << "vector kb: ";
    printVec(kb);
    return 0;
}