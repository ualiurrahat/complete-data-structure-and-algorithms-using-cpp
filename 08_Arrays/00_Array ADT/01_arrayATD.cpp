#include <iostream>
using namespace std;

/*
====================================
      Array Abstract Data Type
====================================

📘 What is an ADT?
------------------
An Abstract Data Type (ADT) defines a data structure *by behavior* (what operations can be performed on it),
not by implementation. It hides the details of how the data is stored or how the operations are carried out.

This example demonstrates a simple Array ADT implementation in C++ that supports:
- Append
- Insert
- Delete
- Display
- Linear Search (with Transposition)
- Get/Set
- Max/Min/Sum/Average
- Reverse (two ways)
- Binary Search (Iterative and Recursive)
- Union, Intersection, Difference, Merge
*/

// Class representing an Array ADT
class Array
{
public:
    int A[20];
    int size;   // Maximum number of elements that can be stored
    int length; // Current number of valid elements
};

// 📌 Function: display()
// -----------------------
// Displays all the elements of the array
void display(const Array &arr)
{
    cout << "Elements are: ";
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;

    // Time Complexity: O(n), where n = arr.length
    // Space Complexity: O(1)
}

// 📌 Function: append()
// -----------------------
// Adds an element at the end of the array, if space permits
void append(Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
    else
    {
        cout << "Append failed: Array is full." << endl;
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)
}

// 📌 Function: insert()
// -----------------------
// Inserts an element at a specific index, shifting elements to the right
void insert(Array *arr, int index, int x)
{
    // Valid index check AND ensure there's room to insert
    if (index >= 0 && index <= arr->length && arr->length < arr->size)
    {
        // Shift elements rightward from end to index
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }

        // Insert new element at target index
        arr->A[index] = x;
        arr->length++;
    }
    else
    {
        cout << "Invalid index! Insertion not possible!" << endl;
    }

    // Time Complexity: O(n), where n = elements shifted
    // Space Complexity: O(1)
}
// 📌 Function: deleteElement()
// ----------------------------
// Deletes the element at the specified index in the array,
// shifts remaining elements left to fill the gap,
// updates the length, and returns the deleted element.
// If index is invalid, returns 0.

int deleteElement(Array *arr, int index)
{
    int x = 0; // Variable to store deleted element

    // Validate index: must be within current length bounds
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index]; // Store element to be deleted

        // Shift elements left starting from index+1 to end
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }

        arr->length--; // Reduce length after deletion

        return x; // Return deleted element
    }

    // Invalid index: no deletion, return 0
    return x;

    // Time Complexity: O(n), where n = number of elements shifted (length - index - 1)
    // Space Complexity: O(1)
}
// 📌 Function: swap()
// -------------------
// Swaps the values of two integers using pointers.
// Returns: void (modifies values in-place)
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

    // Time Complexity: O(1)
    // Space Complexity: O(1)
}

// 📌 Function: linearSearch()
// ----------------------------
// Performs a linear search to find the key in the array.
// If the key is found, swaps it with its immediate left neighbor (transposition)
// to improve search efficiency in subsequent searches.
// Returns:
//   Index of the found key after transposition.
//   Returns -1 if key is not found.
//
// ⚠️ Note: Transposition is applied only if the key is not at index 0.
int linearSearch(Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            // Apply transposition (swap with previous element if not at index 0)
            if (i > 0)
                swap(&arr->A[i], &arr->A[i - 1]);

            return i; // Return index where key was found
        }
    }

    return -1; // Key not found

    // Time Complexity: O(n), where n = arr->length
    // Space Complexity: O(1)
}

// 📌 Function: get()
// ------------------
// Retrieves the element at the specified index from the array.
// Returns -1 if the index is invalid.

int get(Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
    // Time Complexity: O(1)
    // Space Complexity: O(1)
}

// 📌 Function: set()
// ------------------
// Updates the element at a given index with a new value.
// Does nothing if the index is invalid.
void set(Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
    // Time Complexity: O(1)
    // Space Complexity: O(1)
}

// 📌 Function: max()
// ------------------
// Returns the maximum value present in the array.
// Assumes the array has at least one element.
int max(Array arr)
{
    int maxi = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > maxi)
        {
            maxi = arr.A[i];
        }
    }
    return maxi;
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

// 📌 Function: min()
// ------------------
// Returns the minimum value present in the array.
// Assumes the array has at least one element.
int min(Array arr)
{
    int mini = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < mini)
        {
            mini = arr.A[i];
        }
    }
    return mini;
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

// 📌 Function: sum()
// ------------------
// Computes and returns the sum of all elements in the array.
int sum(Array arr)
{
    int s = 0;
    for (int i = 0; i < arr.length; i++)
    {
        s += arr.A[i];
    }
    return s;
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

// 📌 Function: avg()
// ------------------
// Computes the average value of the array elements.
// Utilizes the sum() function internally.

float avg(Array arr)
{
    return (float)sum(arr) / arr.length;
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

// 📌 Function: reverse1()
// ------------------------
// Reverses the array using an auxiliary array.
// 1. Copies elements from original array to temp in reverse order
// 2. Copies reversed temp back to original array
void reverse1(Array *arr)
{
    int *temp;
    temp = new int[arr->length * sizeof(int)];

    // Copy input array arr in reverse order into temp array
    for (int i = 0, j = arr->length - 1; j >= 0; i++, j--)
    {
        temp[j] = arr->A[i];
    }

    // Now copy temp array into input array arr
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = temp[i];
    }

    delete[] temp;
    // Time Complexity: O(n)
    // Space Complexity: O(n)
}

// 📌 Function: reverse2()
// ------------------------
// Reverses the array in-place by swapping symmetric elements.
// Uses two-pointer technique.

void reverse2(Array *arr)
{
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
    // Time Complexity: O(n/2) ≈ O(n)
    // Space Complexity: O(1)
}

// 📌 Function: binarySearchIterative()
// 🔍 Searches for a key in a sorted array using the iterative binary search method.

int binarySearchIterative(Array arr, int key)
{
    int l = 0, h = arr.length - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid; // key found at index mid
        else if (key < arr.A[mid])
            h = mid - 1; // key lies in left subarray
        else
            l = mid + 1; // key lies in right subarray
    }
    return -1; // key not found
    // ✅ Time Complexity: O(log n), Space Complexity: O(1)
}

// 📌 Function: binarySearchRecursive()
// 🔍 Searches for a key in a sorted array using recursion.

int binarySearchRecursive(Array arr, int l, int h, int key)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid; // key found
        else if (key < arr.A[mid])
            return binarySearchRecursive(arr, l, mid - 1, key); // search in left half
        else
            return binarySearchRecursive(arr, mid + 1, h, key); // search in right half
    }
    return -1; // key not found
    // ✅ Time Complexity: O(log n), Space Complexity: O(log n) due to recursion stack
}

// 📌 Function: merge()
// 🔄 Merges two sorted arrays into a new sorted array.

Array merge(Array arr1, Array arr2)
{
    Array arr3;
    int i = 0, j = 0, k = 0;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else
            arr3.A[k++] = arr2.A[j++];
    }
    // Copy remaining elements
    while (i < arr1.length)
        arr3.A[k++] = arr1.A[i++];
    while (j < arr2.length)
        arr3.A[k++] = arr2.A[j++];
    arr3.length = k;
    arr3.size = 10;
    return arr3;
    // ✅ Time Complexity: O(n + m), Space Complexity: O(n + m)
}

// 📌 Function: unionArr()
// 🔗 Returns the union of two sorted arrays (without duplicates).

Array unionArr(Array arr1, Array arr2)
{
    Array arr3;
    int i = 0, j = 0, k = 0;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else if (arr2.A[j] < arr1.A[i])
            arr3.A[k++] = arr2.A[j++];
        else // elements are equal, add only one
        {
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
    }
    // Copy remaining elements
    while (i < arr1.length)
        arr3.A[k++] = arr1.A[i++];
    while (j < arr2.length)
        arr3.A[k++] = arr2.A[j++];
    arr3.length = k;
    arr3.size = 10;
    return arr3;
    // ✅ Time Complexity: O(n + m), Space Complexity: O(n + m)
}

// 📌 Function: intersection()
// 🎯 Returns the common elements of two sorted arrays.

Array intersection(Array arr1, Array arr2)
{
    Array arr3;
    int i = 0, j = 0, k = 0;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < arr1.A[i])
            j++;
        else // common element found
        {
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
    }
    arr3.length = k;
    arr3.size = 10;
    return arr3;
    // ✅ Time Complexity: O(n + m), Space Complexity: O(min(n, m))
}

// 📌 Function: difference()
// ➖ Returns the elements present in arr1 but not in arr2.

Array difference(Array arr1, Array arr2)
{
    Array arr3;
    int i = 0, j = 0, k = 0;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else if (arr2.A[j] < arr1.A[i])
            j++;
        else // elements are equal, skip them
        {
            i++;
            j++;
        }
    }
    // Copy remaining elements from arr1
    while (i < arr1.length)
        arr3.A[k++] = arr1.A[i++];
    arr3.length = k;
    arr3.size = 10;
    return arr3;
    // ✅ Time Complexity: O(n + m), Space Complexity: O(n)
}

// 📌 Main function: Demonstrates the usage of Array ADT
int main()
{
    // Initialize an Array structure with some values and predefined size/length
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    int choice, x, index;

    do
    {
        // 📌 Display the menu for user interaction
        cout << "\n===== Menu =====\n";
        cout << "1. Display\n2. Append\n3. Insert\n4. Delete\n5. Linear Search\n6. Binary Search\n7. Get/Set\n8. Max/Min\n9. Sum/Avg\n10. Reverse\n11. Exit\nEnter choice: ";
        cin >> choice;

        // 📌 Perform operations based on user's choice
        switch (choice)
        {
        case 1:
            // Display the elements of the array
            display(arr);
            break;

        case 2:
            // Take input and append element to the end of the array
            cout << "Enter element to append: ";
            cin >> x;
            append(&arr, x);
            break;

        case 3:
            // Insert an element at a specific index
            cout << "Enter index and element to insert: ";
            cin >> index >> x;
            insert(&arr, index, x);
            break;

        case 4:
            // Delete an element from a given index
            cout << "Enter index to delete: ";
            cin >> index;
            cout << "Deleted: " << deleteElement(&arr, index) << endl;
            break;

        case 5:
            // Perform linear search on the array
            cout << "Enter element to search: ";
            cin >> x;
            cout << "Found at: " << linearSearch(&arr, x) << endl;
            break;

        case 6:
            // Perform both iterative and recursive binary search
            cout << "Enter element to binary search: ";
            cin >> x;
            cout << "(Iterative) Found at: " << binarySearchIterative(arr, x) << endl;
            cout << "(Recursive) Found at: " << binarySearchRecursive(arr, 0, arr.length - 1, x) << endl;
            break;

        case 7:
            // Get and set operations on array
            cout << "Enter index to get and set: ";
            cin >> index;
            cout << "Current value: " << get(arr, index) << endl;
            cout << "Enter new value: ";
            cin >> x;
            set(&arr, index, x);
            break;

        case 8:
            // Display maximum and minimum element of the array
            cout << "Max: " << max(arr) << ", Min: " << min(arr) << endl;
            break;

        case 9:
            // Display sum and average of all elements
            cout << "Sum: " << sum(arr) << ", Average: " << avg(arr) << endl;
            break;

        case 10:
            // Reverse the array using swapping logic
            reverse2(&arr);
            cout << "Array reversed!\n";
            break;

        case 11:
            // Exit the loop/program
            cout << "Exiting...\n";
            break;

        default:
            // Handle invalid input
            cout << "Invalid choice!\n";
        }

    } while (choice != 11); // Repeat menu until user chooses to exit

    return 0;
}
