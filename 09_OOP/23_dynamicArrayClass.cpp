/*
here, we will create a dynamic array class.
It is just like C++ STL vector container.
in this dynamic array,we will be able to
1)increase array size dynamically.
if array is filled, a double sized array will be created.
2)add(element) -> function to add the element in the array.
3)add(element,index) -> funciton to add element in the user given index.
4)get(i) -> function to get ith index element


*/

#include <iostream>
using namespace std;

// Dynamic array class
class DynamicArray
{
    // dynamic array pointer
    int *data;
    // to check index of the next elements needs to be added in the array.
    int nextIndex;
    // total size of the array.
    int capacity;

public:
    // constructor
    DynamicArray()
    {
        // initially, an array for 5 elements is created.
        data = new int[5];
        // first element's index will be zero
        nextIndex = 0;
        // initial capacity
        capacity = 5;
    }

    // function to add element in the array
    // ex: a[] = {1,2,3};
    // a.add(10); now, a[] = {1,2,3,10}
    void add(int element)
    {
        // condition to check if array is full
        if (nextIndex == capacity)
        {
            // creating new array having double size of the previous array
            int *newData = new int[2 * capacity];
            // coping elements from old to new array
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }

            // deleting old array
            delete[] data;
            // assigning new array as the data array
            data = newData;
            // update the capacity*2 since double sized array is created.
            capacity = 2 * capacity;
        }
        // add the element in the data array
        data[nextIndex] = element;
        // update the index
        nextIndex++;
    }

    // function to get an element of a particular index
    // takes a paramter i denoting index value
    // return the element if index is valid
    // otherwise -1.
    int get(int i) const
    {
        // for valid index i, it should be less than the next index
        if (i < nextIndex)
        {
            // index is valid. return the element.
            return data[i];
        }
        else
        {
            // returning -1 as a sign that
            // no element exists in this index
            return -1;
        }
    }
    // funciton to add an element in a particular index
    // takes two parameter:ind denoting index, and an element
    // case1: assign element at the ind index if ind is valid.
    // case 2: if ind == nextIndex, then we call add(element) funciton
    // case 3: if ind is invalid, simply just return.
    void add(int ind, int element)
    {
        // case 1: condition to check if ind is a valid index
        if (ind < nextIndex)
        {
            // index is valid. assigning the element.
            data[ind] = element;
        }
        // case 2: ind == index.
        // so it is just adding the element in the array
        else if (ind == nextIndex)
        {
            // calling the add function.
            add(element);
        }
        // case 3: ind position is higher than last index of the array
        // since ind is invalid, just returning from the function.
        else
        {
            return;
        }
    }
    // funciton to print array
    void print()
    {
        // array has up to nextIndex element.loop goes from 0 to nextIndex value.
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    // funciton to get size of the array
    int getSize()
    {
        return capacity;
    }
    // copy constructor: to create new array from already created one.
    // ex: DynamicArray d2(d1);
    // d2 will have same values for all properties as d1
    DynamicArray(DynamicArray const &d)
    {
        // shallow copy
        // this->data = d.data;

        // deep copy
        // create dynamic array with the size of the array d
        this->data = new int[d.capacity];
        // copy all the elements for d array
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }

        // this part is same for shallow and deep copy
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }
    // copy assignment operator overloading
    // ex: DynamicArray d2 = d1;
    // so new array d2 will have same values for all properties
    // as the values in the array d1.
    void operator=(DynamicArray const &d)
    {
        // shallow copy
        // this->data = d.data;

        // deep copy
        // create dynamic array with the size of the array d
        this->data = new int[d.capacity];
        // copy all the elements for d array
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }

        // this part is same for shallow and deep copy
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }
};
int main()
{

    DynamicArray d;
    d.add(10);
    d.add(20);
    d.add(30);
    d.add(40);
    d.add(50);
    // printing the array
    d.print(); // 10 20 30 40 50
    // chaning index 3 value to 100
    d.add(3, 100);
    // printing again
    d.print(); // 10 20 30 100 50

    // trying to add 1000 in index 7 which is out of scope
    d.add(7, 255); // add() should do nothing and return
    d.print();     // 10 20 30 100 50
    // printing capacity
    cout << "size of the array:" << d.getSize() << endl; // 5

    // now adding 6th element in the array
    d.add(420);
    // since initial size is 5 and if
    // further element is added, array size will become double
    // let's check array size now
    cout << "size of the array:" << d.getSize() << endl; // 5

    // creating another array c using copy constructor
    DynamicArray c(d);
    cout << "printing array c: ";
    c.print();

    // now changing in c
    c.add(0, -25);
    d.print();
    c.print();

    // creating a new array using copy assignment operator
    DynamicArray b = d;
    b.print();
    b.add(307);
    d.print();
    b.print();
    c.print();

    return 0;
}