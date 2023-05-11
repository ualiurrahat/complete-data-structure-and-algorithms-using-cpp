#include <bits/stdc++.h>

using namespace std;
/*
C++ STL has an inbuilt sort function
sort(starting address, next address to end address)
this sort algorithm is a mixture of 3 sorting algos: quick,heap and insertion sorts
if the container has less no. of elements, it uses insertion sort
in general, it uses quick sort
but if the sorting gets deep, then it works using heap sort
T:O(nlogn) at worst,
It is also known as intro sort
considered as the best sorting algorithm
*/
int main()
{
    int n;
    cout << "Total no. of elements in array: ";
    cin >> n;
    int a[n];
    cout << "Insert array elements: ";
    // int x;
    for(int i = 0; i < n; i++)
    {
        cin >>a[i];
        
    }
    cout << endl;
    cout << "Printing given array: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    // now sorting whole array
    sort(a, a+n);
    // we can use this between any two index of an array
    // like: sort(a, a+3);
    // this will sort first 3 elements, a[0] to a[2]
    cout << "Printing sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}