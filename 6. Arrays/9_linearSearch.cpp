/*
find if a number exists in the array or not.
if exists, return its index. if not, return -1
ex:a[] = [18,1,8,5,20], num = 5
output = 3(index of 5)
b[] = [20,1,13,1,14,14,1], num = 18
output = -1(18 does not exist)
*/

#include <iostream>
using namespace std;

// funciton to perform linear search
// takes array,its size and a number as parameters
int linearSearch(int arr[], int n, int num)
{
    // traverse the array
    for (int i = 0; i < n; i++)
    {
        // check if num is found
        if (arr[i] == num)
        {
            // return its index
            return i;
        }
    }
    // number does not exist in the array
    return -1;
}
int main()
{

    int n; // size of array
    // taking array size from user
    cout << "Enter array size: ";
    cin >> n;
    // constructing array with size n
    int arr[n];
    // inserting elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int num;
    cout << "Enter the number you wanna search: ";
    cin >> num;
    cout << linearSearch(arr, n, num) << endl;
    return 0;
}