/*
move all the zeores of an array to the end of the array
ex: a[] = [1,2,0,0,3,17,0,0 9]
output: a[] = [1,2,3,17,9,0,0,0,0]
*/

#include <bits/stdc++.h>
using namespace std;

// brute force approach
// 1. copy all the non-zero elements into a temporary array
// 2. insert all the elements of temporary array into the given array from starting
// 3. given array has n-tempArraySize no. of zeroes. fill them in the array
void moveZeroesToEndBrute(vector<int> &arr)
{
    // size of arr
    int n = arr.size();
    // take a temporary array.
    vector<int> temp;
    // 1. coping all the non-zero elements into it
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
        {
            temp.push_back(arr[i]);
        }
    }
    // 2. copying elements of temp array into the given array from starting
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    // 3. fill the zeroes in the array
    for (int i = temp.size(); i < n; i++)
    {
        arr[i] = 0;
    }
}
// T:O(N)
// S:O(N)

// optimal approach
// 1. find first index of zero. save it
// 2. iterate from the next index to whole array
// 3. if non-zero element if found, swap their position with the previously saved indexed 0 element.
// done
void moveZerosToEndOptimal(vector<int> &a)
{
    // index position to save non-zero element
    int index = 0;
    // find first index of 0
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
        {
            index = i;
            break;
        }
    }
    // now traverse the array and swap non-zero elements with zeroes
    for (int i = index + 1; i < a.size(); i++)
    {
        if (a[i])
        {
            swap(a[i], a[index]);
            // update index
            index++;
        }
    }
}
// T:O(N)
// S:O(1), hence it takes no extra space like previous function
int main()
{

    int n;
    cout << "Enter number total elements in the array:";
    cin >> n;

    // take a vector
    vector<int> arr;
    // inserting elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // moving the zeroes using the funciton
    // moveZeroesToEndBrute(arr);
    moveZerosToEndOptimal(arr);
    cout << "array after moving zeroes: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}