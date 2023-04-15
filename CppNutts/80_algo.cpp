#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {25, 31, 8, 1, 13, 7, 9, 22, 17};

    cout << "Input vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // now sorting in ascending order.
    cout << "vector in ascending order: ";
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // now sorting in descending order.
    cout << "vector in descending order: ";
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // reverse.
    cout << "reversed vector: ";
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // max and min value.

    auto it = max_element(v.begin(), v.end());
    cout << "max : " << (*it) << endl;

    cout << endl;

    auto iter = min_element(v.begin(), v.end());
    cout << "min : " << (*iter) << endl;

    cout << endl;

    // merging two vectors.
    vector<int> v1 = {70, 80, 90, 100};

    vector<int> v3(v1.size() + v.size());
    merge(v.begin(), v.end(), v1.begin(), v1.end(), v3.begin());

    cout << "\nmerging vector: ";
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
    cout << endl;

    //sort array
    int arr[] = {1, 7, 4, 2};
    int n = 4;

    //ascending order
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

    return 0;
}