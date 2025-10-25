// Dynamic memory allocation for a 2D array
#include <iostream>

using namespace std;

int main()
{
    /*There is no way we can access 2D array memory from heap like this:
    int ** 2dAarray = new int[10][20]; XXXXX not allowed.
    Suppose we need to make a 2d array of 10 rows and 20 columns.
    So what should We do?
    Solution:
     We will take an array of 10 integer pointers.
    Each integer pointer will then represen a rwo of the 2D array
    array of integer pointer: let's say p = [int*, int*, int*,...., up to 10th int*];
    since each element is an integer pointer, and we want to save the address of first element,
    so that has to be integer double pointer.
    like: int **p = [int*, int*,int *, ..., up to 10th int*];
    */
    // Dynamically allocating a 2D array (10 rows, 20 columns)
    int **p = new int *[10]; // Allocating memory for 10 rows
    for (int i = 0; i < 10; i++)
    {
        p[i] = new int[20]; // Allocating memory for 20 columns in each row
    }

    /* Memory Discussion (32-bit system):
       - Stack memory:
         * 'p' pointer variable itself -> 4 bytes
       - Heap memory:
         * Array of 10 row pointers -> 10 * 4 = 40 bytes
         * 10 rows * 20 ints each -> 10 * 20 * 4 = 800 bytes
       - Total memory: 844 bytes (4 stack + 840 heap)
    */

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

    // take user input for 2D arrays
    int m, n; // m -> rows, n -> columns
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    // creating 2D array on heap using user input data
    int **d_arr = new int *[m];
    // now allocating n elements of memory space for each rows
    for (int i = 0; i < m; i++)
    {
        d_arr[i] = new int[n];
    }
    // Take user input for m*n 2D arrays
    cout << "Enter data for 2D array: ";
    for (int i = 0; i < m; i++)
    {
        cout << "Row number: " << i << endl;
        for (int j = i; j < n; j++)
        {
            cin >> d_arr[i][j];
        }
    }
    // now deleting the d_arr array
    for (int i = 0; i < m; i++)
    {
        // deleting each row
        delete[] d_arr[i];
    }
    // deleting integer pointer d_arr array;
    delete[] d_arr;

    /* Additional Example: Jagged Array (rows of different column sizes)
       Using int** we can create rows with varying column sizes
    */
    int rows = 3;

    // Step 1: Create array of integer pointers for rows
    int **jaggedArray = new int *[rows];

    // Step 2: Allocate different number of columns for each row
    jaggedArray[0] = new int[2]; // Row 0 has 2 columns
    jaggedArray[1] = new int[4]; // Row 1 has 4 columns
    jaggedArray[2] = new int[3]; // Row 2 has 3 columns

    // Step 3: You can now access jaggedArray[i][j] like a normal 2D array

    // Step 4: Deallocate memory
    for (int i = 0; i < rows; i++)
    {
        delete[] jaggedArray[i]; // Delete each row
    }
    delete[] jaggedArray; // Delete array of pointers

    return 0;
}
