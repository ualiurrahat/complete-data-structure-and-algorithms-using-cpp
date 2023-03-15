#include <iostream>
#include <vector>
using namespace std;

template <class T>
// function to print vector
void printVector(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter total no. of array in the vector: ";
    cin >> n;

    // taking an array of vector with size n
    vector<int> v[n];
    // an array of vector is like a 2d array with varying column size for each row
    // for ex: int arr[10][10] is a 2d array with 10 row each row having 10 column
    // so both row and col size are fixed.

    // but , vector<int>v(10) is an array of vector
    // where row is 10, but col size of each row is varying.
    // as each vector can have any number of elements.

    // take input for each array of vector
    // loop for n arrays of vector
    for (int i = 0; i < n; i++)
    {
        cout << "Enter size of the vector " << i + 1 << " : ";
        int size;
        cin >> size;
        cout << "enter the vector: ";
        // fill up ith array of vector
        for (int j = 0; j < size; j++)
        {

            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    // print all the vectors
    for (int i = 0; i < n; i++)
    {
        printVector(v[i]);
    }

    return 0;
}