// function objects in cpp
// functors.
// function objects: function wrapped in a class so that
// it is available like objects. it is treated like an object.
#include <iostream>
#include <string>
#include <functional> // header file for function objects.
#include <algorithm>  // to use sort() function.

using namespace std;

int main()
{
    int arr[] = {18, 1, 8, 20, 13, 14, 25};
    // sorting the array in ascending order.
    sort(arr, arr + 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // sorting the array in descending order.
    // with the help of function objects.
    sort(arr, arr + 7, greater<int>());
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}