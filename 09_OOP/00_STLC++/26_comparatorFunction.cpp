#include <bits/stdc++.h>
using namespace std;

// compartator funciton is used for changing the behaviour of sorting
// all the sort function compare two elements and sort them according to the condition
// like (if(a[i] > a[j]){swap(a[i],a[j])})
// here, this condition is doing ascending order sorting
// we can use our custom condition to sort elements according to our needs
// the function which does this comparison, is called comparator function.

// the STL sort comparator function is written in such a way that
// the way want to sort, you have to return false when the condition of your need comes.
// means, if comparator return false, in that case sorting will take place
// so, how we remember when to return false or true???
// solution: just return what you want to get after sort in your written comprator function
// for instance, if you want ascending order sort, which means a < b, just return a < b;(in the function)
// for descennding order: return a > b; that's it.

// comparator function to sort in descending order
bool shouldISwap(int a, int b)
{
    return a > b;
}

// function to sort pairs where first element will be in ascending order
// and second element will be in descending order
// if their first element is equal

bool pairSwap(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        // first element will be in ascending order
        return a.first < b.first;
    }
    // second element will be in descending order
    return a.second > b.second;
}
int main()
{
    vector<int> v = {10, 100, 50, 20, 5};
    // now sort the vector using built in sort
    sort(v.begin(), v.end());
    cout << "ascending order vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // now we can use built in comparator function to sort in descending order
    // sort(v.begin(), v.end(), greater<int>());
    sort(v.begin(), v.end(), shouldISwap);
    cout << "descending order vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    vector<pair<int, int>> vpair = {{18, 20}, {1, 1}, {8, 13}, {5, 22}, {20, 17},{18,9}, {18,8}, {18,100}};
    sort(vpair.begin(), vpair.end(), pairSwap);
    // printing pair
    cout << "sorting pair: " << endl;
    for (int i = 0; i < vpair.size(); i++)
    {
        cout << vpair[i].first << " " << vpair[i].second << endl;
    }

    return 0;
}