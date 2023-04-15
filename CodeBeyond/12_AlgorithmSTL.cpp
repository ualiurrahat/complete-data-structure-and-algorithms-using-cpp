#include <bits/stdc++.h>

using namespace std;

int main()
{

    // sorting
    // array, vector

    int a[5] = {18, 1, 8, 5, 20};

    // sort from index 1 to 3
    sort(a + 2, a + 5);
    cout << "sorting array from index 2 to 4: ";
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    sort(a, a + 5); // sort(arr, arr+size)

    cout << "sorted array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    vector<int> v = {20, 1, 13, 5, 14, 18, 10};

    cout << "sorting vector from index 1 to 4: ";
    sort(v.begin() + 1, v.begin() + 4);

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "sorting entire vector: ";
    sort(v.begin(), v.end());

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    // reverse
    reverse(a, a + 5);
    // reverse(a+1, a+4);  // reverse from index 1 to 3
    cout << "reversed array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    reverse(v.begin(), v.end());
    cout << "reversed vector: ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    // max and min element
    // for iterator: max_element(startIterator, lastIterator)
    // for value: *max_element(startIterator, lastIterator)

    int max_a = *max_element(a, a + 5);
    int max_v = *max_element(v.begin(), v.end());

    cout << "max in array: " << max_a << endl;
    cout << "max in vector: " << max_v << endl;

    int min_a = *min_element(a, a + 5);
    cout << "min in array: " << min_a << endl;

    // sum of elements
    // accumulate(startIterator, endIterator, initialSum)
    int sum_a = accumulate(a, a + 5, 0);
    int sum_v = accumulate(v.begin(), v.end(), 0);

    cout << "vector sum: " << sum_v << endl;
    cout << " array sum: " << sum_a << endl;

    // count number of times an element is present in the array or vector
    // count(startIterator, endIterator, number)
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    int cnt = count(v.begin(), v.end(), 1);
    cout << "total 1 in vector: " << cnt << endl;

    // find first index of an element
    auto it = find(a, a + 5, 20);
    // returns an iterator pointing to the fisrt instance of 20
    // either returns the end() if the number(20) is not there
    cout << "index of 20: " << it - a << endl; // address of 20

    // binary search
    // this stl works only for sorted arrays.

    // binary_search(firstIterator, lastIterator, num)
    // returns 1 if the num is in the array
    // returns 0 if the num is not in the array
    int b[] = {5, 8, 13, 21, 34};
    int res1 = binary_search(b, b + 5, 18);
    int res2 = binary_search(b, b + 5, 21);
    cout << res1 << endl;
    cout << res2 << endl;

    // lower_bound function
    // returns an iterator pointing to the first element
    // which is not less than x
    // c = {1,5,7,7,8,10,10,10,12,25}
    // x = 10, lower_bound iterator returns index = 5
    // x = 6, index = 2.
    // x = 28, index = last iterator

    auto it1 = lower_bound(a, a + 5, 20);
    int index1 = it1 - a;

    auto it2 = lower_bound(v.begin(), v.end(), 8);
    int index2 = it2 - v.begin();
    cout << index1 << endl;
    cout << index2 << endl;

    // upper_bound function
    // returns an iterator pointing to the first element
    // which is just greater than x
    // c = {1,5,7,7,8,10,10,10,12,25}
    // x = 10, upper_bound iterator returns index = (number 12)
    // x = 28, index = last iterator

    return 0;
}