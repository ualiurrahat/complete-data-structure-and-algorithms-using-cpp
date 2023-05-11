// Find the last occurence of an element in array using STL
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int a[] = {1,5,7,7,8,10,10,10,11,11,12};
    // last occurrence of 10 -- 7th index
    // last occurence of 6 -- does not exist

    // finding last occurence of 10
    int index = upper_bound(a, a + 11, 10 ) - a;
    index -= 1;

    if(index >= 0 && a[index] == 10)
    {
        cout << "last occurence of 10 at index: " << index << endl;
    }
    else
    {
        cout << "element does not exist" << endl;
    }
    return 0;
}