/*
reverse an array recursively.
input = a[] = {10,20,30,40,50};
output = a[] = {50,40,30,20,10};
*/

#include <bits/stdc++.h>
using namespace std;

void reverseArray(int a[],int firstIndex,int lastIndex)
{
    // base case
    if(firstIndex == lastIndex)
    {
        return;
    }
    // small calculation: swap element
    swap(a[lastIndex], a[firstIndex]);
    // recursive call
    reverseArray(a, firstIndex+1, lastIndex-1);
}

int main()
{
    int a[] = {10,20,30,40,50};
    reverseArray(a,0,4);
    for(int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}