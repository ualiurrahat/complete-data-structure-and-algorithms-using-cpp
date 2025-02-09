/* Topic: std::vector

Syntax: std::vector<int>vector_name;

1. Vector is a sequence container. also knows as Dynamic Array or Array List.
2. Its size can grow and shrink dynamically, and no need to provide size in compile time.

//Element Access:
at(), [], front(), back(), data()

// Modifiers:
insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()


note: arr[index]: if index exceeds size of arr, then compiler shows error.
    arr.at(index): if index is greater than size, then compiler shows exception not error.

*/
#include <iostream>
#include <string>
#include <vector>    // header file for vectors
#include <algorithm> // to use max_element(), min_element() functions
#include <numeric>   // to use accumulate() and partial_sum() functions

using namespace std;

int main()
{

    // ways of traversing a vector.
    vector<int> v = {1, 2, 3};

    // way 1: using index position through sqaure bracktes []
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
        // here , element is a var name indicating each element of vector v.
        // this name can be anything, like (auto it: v)
        // auto will automatically change the data type according to element.
        // here auto is int type.
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
    // we use accumulate() defined in the numeric library.
    int sum1 = accumulate(v.begin(), v.end(), 0); // 0 = initial value of sum1

    /*we can even perform any binary operation with accumulate(), not just addition.
      int mul(int x, int y) // custom multiplication function
    {
        return x * y;
    }
  int product = accumulate(v.begin(), v.end(), 1, mul);
  */
    cout << sum1 << endl;

    // *max_element returns pointer to the max element

    int mx1 = *max_element(v.begin(), v.end());
    // *min_element returns pointer to the min element
    int mn1 = *min_element(v.begin(), v.end());

    cout << "max of v: " << mx1 << endl;
    cout << "min of v: " << mn1 << endl;

    // to convert the vector into a prefix sum vector.
    // ex: v={10,20,30}
    // prefix_sum v = {10,30,60}
    partial_sum(v.begin(), v.end(), v.begin());
    for (auto element : v)
    {
        cout << element << " ";
    }
    /* Same as accumulate(), we can even pass a custom function with partial_sum()

  int myop (int x, int y) {
     return x+y+1;
  }

  vector<int> result2(v.size());
  partial_sum(v.begin(), v.end(), result2.begin(), myop); */
    cout << endl;

    return 0;
}