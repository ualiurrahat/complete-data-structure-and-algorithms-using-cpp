// vectors in cpp STL
/*
difference between vector and array:
1. size of array is fixed but vector is dynamic.
2. can create copy of vector but not in array.
3. array  cannot be returned by function but vector can be.
*/
#include <iostream>
#include <string>
#include <vector>    // to use vectors.
#include <algorithm> // to use sort, reverse function.

using namespace std;

template <class T>
// function to print vector
void display(vector<T> &v)
{
    cout << "\nDisplaying  this vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " "; // same: cout << v.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    // vector is like resizable array.
    // vector sytnax:
    // vector<dataType>vectorName;
    // vector<containerName>vectorName;

    // ways to create a vector.
    vector<int> vec;
    // interger type zero length vector.
    // take a vector with size 10
    // vector<int>v(10);
    // take a vector with size 5 each element having value 10;
    // vector<int>(5,10);
    display(vec); // there is no element in vec. so will show the message only.

    vector<int> vec1; // integer type zero length vector.

    // var to store info about vec1.
    int element, size;
    cout << "Enter the size of your vector: " << endl;
    cin >> size;
    // adding element to vector.
    cout << "Enter elements to add to the vector: " << endl;
    for (int i = 0; i < size; i++)
    {

        cin >> element;
        // storing element to the vector vec1.
        vec1.push_back(element); // O(1)
    }

    // displaying user input vec1.
    cout << "user's input vector: ";
    display(vec1);
    cout << endl;

    // declaring an iterator to insert an element in the first place.
    vector<int>::iterator iter = vec1.begin();
    // note: if vec1={18,1,8,25,20} declared like this
    // then iteration use shows error.

    // inserting 420 as the first vector element.
    vec1.insert(iter, 420);

    cout << "vector elements after inserting an element: ";
    display(vec1);
    cout << endl;

    // inserting some more element.
    vec1.insert(iter, 200); // will insert 200 after the first two element.
    cout << "inserting 200: ";
    display(vec1);
    cout << endl;

    // inserting one element several times.
    vec1.insert(vec1.end(), 3, 100); //  keeping 100 for 3 times.
    cout << "inserting 8 three times in the end: ";
    display(vec1);
    cout << endl;

    // popping out the last element.
    vec1.pop_back(); // O(1)
    cout << "after popping out the last element: ";
    display(vec1);
    cout << endl;

    // sorting the vector vec1.
    cout << "vec1 before sorting: ";
    display(vec1);

    sort(vec1.begin(), vec1.end());
    // takes two parameters. the begin and end location of the vector.
    cout << endl
         << "vec1 after sorting: ";
    display(vec1);

    cout << endl;

    // reversing the vector vec1;
    cout << "vec1 before reversing: ";
    display(vec1);

    reverse(vec1.begin(), vec1.end());
    // takes two parameters. the begin and end location of the vector.
    cout << endl
         << "vec1 after reversing: ";
    display(vec1);

    cout << endl;

    vector<char> vec2(4); // 4 element character vector.
    vec2.push_back('m');
    vec2.push_back('o');
    vec2.push_back('h');
    vec2.push_back('o');
    display(vec2);           // will show these characters.
    vector<char> vec3(vec2); // 4 element character vector from vec2.
    display(vec3);
    vector<int> vec4(6, 25); // 6 element vector of 25s.
    display(vec4);           // will show 25 for 6 times.

    // copy vector of vec1 in vec5;
    // shallow copy
    vector<int> vec5 = vec1;
    display(vec5);
    vec5.push_back(1000);
    display(vec1);
    display(vec5);

    cout << endl;
    cout << "size of vec5: " << vec5.size() << endl;

    return 0;
}
