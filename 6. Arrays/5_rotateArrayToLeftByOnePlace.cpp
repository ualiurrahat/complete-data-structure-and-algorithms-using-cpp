/*
rotate a given array to the left by one place.
ex: a[] = [1,2,3,4,5]
output: a[] = [2,3,4,5]
*/
#include <iostream>
using namespace std;

// funcion to rotate array to left by one place
// optimal approach
void rotateArrayToLeftByOnePlace(int arr[], int n)
{
    // reserve the first element
    int firstElement = arr[0];
    // now from index 1 to before last index
    // place them to one index before their actual position
    for (int i = 1; i < n; i++)
    {
        // left rotating by one place
        arr[i - 1] = arr[i];
    }
    // insert first element to the last index
    arr[n - 1] = firstElement;
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
    // rotating array to left by one place using the funciton
    rotateArrayToLeftByOnePlace(arr, n);
    // now printing the array
    cout << "Rotating Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}