// remove duplicates from a given array and prints all the unique numbers
#include <bits/stdc++.h>

using namespace std;

// function to remove duplicates

vector<int> removeDuplicates(int a[], int size)
{
    vector<int> v;
    // creating unordered_map for storing unique elements
    unordered_map<int, bool> checked;
    for (int i = 0; i < size; i++)
    {
        // if elements already present in the map
        if (checked.count(a[i]) > 0)
        {
            // exiting this and going to next iteration.
            continue;
        }
        else
        {
            // elements not included in map. so including it
            checked[a[i]] = true;
            // pushing this unique elements in the vector.
            v.push_back(a[i]);
        }
    }
    // sorting vector
    // sort(v.begin(), v.end());
    return v;
    // T:O(n) as we have used unordered_map
    // for  map, it would have been T:O(nlogn)
}

int main()
{
    int a[] = {18, 1, 8, 1, 20, 20, 1, 13, 1, 14, 14, 1};
    // int a[] = {1, 1, 2};

    int size = sizeof(a) / sizeof(a[0]);

    vector<int> v = removeDuplicates(a, size);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}