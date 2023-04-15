// Sorting using your own comparison function.
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// function for sorting in descending order.
bool descending(int a, int b)
{
    return a > b;
}

// function to sort strings in ascending order.
bool ascending(string &a, string &b)
{
    return a.size() < b.size();
}

int main()
{

    int arr[4] = {9, 5, 7, 10};

    //sort(container.begin(), container.end(), comparison_function);
    // sorting in descending order.
    sort(arr, arr + 4, descending);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // This time, we will sort strings by their length — that is, we want the shortest string to come first, and the longest one should be at the end.

    string str[4] = {"Violet", "Blue", "Red", "Green"};
    sort(str, str + 4, ascending);
    for (int i = 0; i < 4; i++)
    {
        cout << str[i] << " ";
    }

    return 0;
}