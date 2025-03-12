#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for iota() function
using namespace std;

// function to print vectors
template <class T>
void print(vector<T> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    /*copy(): used to copy elements from one range to another.
    T: O(n), where n is the number of elements to copy.
*/
    vector<int> source = {1, 2, 3, 4, 5};
    vector<int> destination(5);
    copy(source.begin(), source.end(), destination.begin()); // Copies elements from source to destination
    print(destination);                                      // 1 2 3 4 5

    /*  reverse(): reverse the order of elements in a range.
        T: O(n), where n is the number of elements to reverse.
        */
    vector<int> vec = {1, 2, 3, 4, 5};
    reverse(vec.begin(), vec.end()); // Reverses the order of elements in vec
    print(vec);                      // 5 4 3 2 1

    /*  fill():bassigns a specified value to all elements in a range.
        T: O(n), where n is the number of elements to fill.
     */
    vector<int> v(5);
    fill(v.begin(), v.end(), 8); // Fills vec with value 42
    print(v);                    // 8 8 8 8 8

    /*iota(): assigns increasing values to a range starting from a specified value.
    T: O(n), where n is the number of elements to assign.*/
    vector<int> a(5);
    iota(a.begin(), a.end(), 1); // Assigns values 1, 2, 3, 4, 5 to vec
    print(a);                    // 1 2 3 4 5

    return 0;
}