// Dynamic memory allocation for a 2D array
#include <iostream>

using namespace std;

int main()
{
    // Dynamically allocating a 2D array (10 rows, 20 columns)
    int **p = new int *[10]; // Allocating memory for 10 rows
    for (int i = 0; i < 10; i++)
    {
        p[i] = new int[20]; // Allocating memory for 20 columns in each row
    }

    // Deallocating the dynamically allocated 2D array
    // It is essential to delete each allocated memory location using delete to prevent memory leaks.

    // Step 1: Deleting the rows (the individual 1D arrays)
    for (int i = 0; i < 10; i++)
    {
        // Delete memory for each row (like p[0], p[1], ..., p[9])
        delete[] p[i];
    }

    // Step 2: Deleting the pointer array (the array of pointers to the rows)
    delete[] p;

    return 0;
}
