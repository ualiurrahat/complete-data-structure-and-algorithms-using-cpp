// create a dynamic array
#include <bits/stdc++.h>

using namespace std;

class DynamicArray
{
    int *data;
    int index;
    int capacity;

public:
    DynamicArray()
    {
        data = new int[5]; // 5 size array in initial stage
        index = 0;
        capacity = 5;
    }

    void add(int element)
    {
        // when ara is full
        // creating new ara with double size of the previous ara
        if (index == capacity)
        {
            int *newData = new int[2 * capacity];
            // coping elements from old to new ara
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            // capacity needs to be updated
            capacity = 2 * capacity;
            // deleting old array
            delete[] data;
            // assigning new ara as the data ara
            data = newData;
        }
        data[index] = element;
        index++;
    }

    // function to get an element by index
    int get(int i) const
    {
        // check if ith index has any valid element
        if (i < index)
        {
            // index
            return data[i];
        }
        else
        {
            // returning -1 as a sign that
            // no element exists in this index
            return -1;
        }
    }

    // add an element in a particular index
    void add(int ind, int element)
    {
        // updating value of an index.
        if (ind < index)
        {
            data[ind] = element;
        }
        // adding an element in the last position
        else if (ind == index)
        {
            add(element);
        }
        // ind position is higher than last index of the array
        // so returning without adding the element
        else
        {
            return;
        }
    }

    // copy constructor
    DynamicArray(DynamicArray const &d)
    {
        // shallow copy
        // this->data = d.data;

        // deep copy
        this->data = new int[d.capacity];
        for (int i = 0; i < d.capacity; i++)
        {
            this->data[i] = d.data[i];
        }

        // this part is same for shallow and deep copy
        this->index = d.index;
        this->capacity = d.capacity;
    }
    void operator=(DynamicArray const &d)
    {
        // shallow copy
        // this->data = d.data;

        // deep copy
        this->data = new int[d.capacity];
        for (int i = 0; i < d.capacity; i++)
        {
            this->data[i] = d.data[i];
        }
        // this part is same for shallow and deep copy
        this->index = d.index;
        this->capacity = d.capacity;
    }
    // print array
    void display()
    {
        for (int i = 0; i < index; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray d;
    d.add(20);
    d.add(1);
    d.add(13);
    d.add(1);
    d.add(14);
    d.add(14);
    d.add(1);

    d.display();

    // inbuilt copy constructo always does shallow copy
    DynamicArray d2(d);
    // copy assignment also does shallow copy
    DynamicArray d3;
    d3 = d;
    d3.display();
    d.add(0, 100); // d[0] = 100
    d.display();
    d2.display(); // d2[0] also became 100 due to shallow copy

    return 0;
}