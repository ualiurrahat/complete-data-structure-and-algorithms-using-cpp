/*
----------------------------------------------------------
File: 23_DynamicArrayClass.cpp
Topic: Implementation of a Dynamic Array Class (like STL vector)
----------------------------------------------------------
This program implements a custom DynamicArray class similar to
the C++ STL vector container.

Functionalities included:
1️⃣ Automatically increases the array size dynamically.
    ➤ If the array becomes full, it doubles its capacity.
2️⃣ add(element) — Adds an element to the array.
3️⃣ add(element, index) — Inserts an element at the user-specified index.
4️⃣ get(i) — Returns the element at the i-th index.
----------------------------------------------------------
*/

#include <iostream>
using namespace std;

/*
----------------------------------------------------------
DynamicArray Class
----------------------------------------------------------
A class that demonstrates dynamic memory allocation,
deep copy, and dynamic resizing of arrays.
----------------------------------------------------------
*/
class DynamicArray
{
    int *data;     // Pointer to the dynamic array
    int nextIndex; // Index of the next element to be inserted
    int capacity;  // Total current capacity of the array

public:
    /**
     * @brief Constructor initializes the dynamic array with size 5.
     */
    DynamicArray()
    {
        data = new int[5]; // Initially allocate space for 5 elements
        nextIndex = 0;     // First available index is 0
        capacity = 5;      // Initial capacity is 5
    }

    /**
     * @brief Adds an element at the end of the array.
     *        If array is full, capacity is doubled.
     */
    void add(int element)
    {
        // Check if array is full
        if (nextIndex == capacity)
        {
            // Create a new array with double capacity
            int *newData = new int[2 * capacity];

            // Copy all elements from old array to new one
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }

            // Delete old memory and reassign pointer
            delete[] data;
            data = newData;

            // Update capacity to new doubled value
            capacity = 2 * capacity;
        }

        // Add element and move to next index
        data[nextIndex] = element;
        nextIndex++;
    }

    /**
     * @brief Returns element at index i (if valid).
     * @param i Index position
     * @return Element value or -1 if invalid index
     */
    int get(int i) const
    {
        if (i < nextIndex)
            return data[i];
        else
            return -1; // Invalid index
    }

    /**
     * @brief Adds element at a particular index.
     *
     * Cases handled:
     *   1️⃣ If index < nextIndex → Replace element at index.
     *   2️⃣ If index == nextIndex → Append using add().
     *   3️⃣ If index > nextIndex → Invalid index, do nothing.
     */
    void add(int ind, int element)
    {
        if (ind < nextIndex)
        {
            // Valid index — replace element
            data[ind] = element;
        }
        else if (ind == nextIndex)
        {
            // Add at the end of array
            add(element);
        }
        else
        {
            // Invalid index — do nothing
            return;
        }
    }

    /**
     * @brief Prints all current elements of the array.
     */
    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    /**
     * @brief Returns total current capacity of the array.
     */
    int getSize()
    {
        return capacity;
    }

    /**
     * @brief Copy Constructor (performs deep copy)
     *
     * Creates a new DynamicArray with its own copy of data,
     * preventing shared memory (shallow copy).
     */
    DynamicArray(DynamicArray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    /**
     * @brief Copy Assignment Operator Overloading (deep copy)
     *
     * Example:
     * DynamicArray d2 = d1;
     */
    void operator=(DynamicArray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }
};

/*
----------------------------------------------------------
Main Function
----------------------------------------------------------
Demonstrates all features of the DynamicArray class.
----------------------------------------------------------
*/
int main()
{
    DynamicArray d;

    d.add(10);
    d.add(20);
    d.add(30);
    d.add(40);
    d.add(50);

    d.print(); // Output: 10 20 30 40 50

    d.add(3, 100);
    d.print(); // Output: 10 20 30 100 50

    d.add(7, 255); // Invalid index → no change
    d.print();     // Output: 10 20 30 100 50

    cout << "Size of the array: " << d.getSize() << endl; // 5

    // Add one more element — triggers resizing
    d.add(420);
    cout << "Size of the array: " << d.getSize() << endl; // 10

    // Demonstrate copy constructor
    DynamicArray c(d);
    cout << "Printing array c: ";
    c.print();

    // Modify c without affecting d
    c.add(0, -25);
    d.print();
    c.print();

    // Demonstrate copy assignment operator
    DynamicArray b = d;
    b.print();

    b.add(307);
    d.print();
    b.print();
    c.print();

    return 0;
}
