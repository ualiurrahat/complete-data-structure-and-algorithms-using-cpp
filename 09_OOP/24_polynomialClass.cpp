/*
----------------------------------------------------------
File: 24_polynomialClass.cpp
Topic: Implementation of a Polynomial Class in C++
----------------------------------------------------------
This program demonstrates how to implement a custom Polynomial class
that supports setting coefficients, printing, addition, subtraction,
and multiplication of two polynomials.

Each polynomial is internally represented as an array (degCoeff)
where index = degree of x and value = coefficient for that degree.

For example:
    P(x) = 3x² + 2x + 5
is represented as:
    degCoeff[0] = 5
    degCoeff[1] = 2
    degCoeff[2] = 3
----------------------------------------------------------
*/

#include <iostream>
using namespace std;

/*
----------------------------------------------------------
Polynomial Class Definition
----------------------------------------------------------
This class stores polynomial coefficients dynamically.
Supports:
1️⃣ Setting coefficients for any degree.
2️⃣ Resizing when a degree exceeds current capacity.
3️⃣ Performing deep copy to avoid shared memory.
4️⃣ Overloading +, -, * operators for polynomial operations.
----------------------------------------------------------
*/
class Polynomial
{
public:
    int *degCoeff; // Dynamic array storing coefficients
    int capacity;  // Size of the array (maximum degree + 1)

    /**
     * @brief Default constructor initializes polynomial
     * with degree capacity = 5 (supports 0 to 4 degrees).
     */
    Polynomial()
    {
        capacity = 5;
        degCoeff = new int[capacity];

        // Initialize all coefficients to zero
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = 0;
        }
    }

    /**
     * @brief Copy Constructor (Deep Copy)
     *
     * Important Concept:
     * If we simply assign pointers (shallow copy),
     * both objects will share the same memory.
     * Deleting one will affect the other.
     *
     * Deep copy creates new memory and duplicates all data.
     */
    Polynomial(Polynomial const &p2)
    {
        capacity = p2.capacity;
        degCoeff = new int[capacity];

        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = p2.degCoeff[i];
        }
    }

    /**
     * @brief Copy Assignment Operator Overloading (=)
     *
     * Ensures proper deep copying when one object is assigned to another.
     * Example:
     *      Polynomial p2;
     *      p2 = p1;
     */
    void operator=(Polynomial const &p2)
    {
        // Delete old memory to prevent memory leak
        delete[] degCoeff;

        // Allocate new memory for target object
        capacity = p2.capacity;
        degCoeff = new int[capacity];

        // Copy all coefficients
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = p2.degCoeff[i];
        }
    }

    /**
     * @brief Set the coefficient for a specific degree.
     *
     * If degree exceeds current capacity, the array is resized
     * dynamically to hold the new degree.
     */
    void setCoefficient(int degree, int coeff)
    {
        if (degree >= capacity)
        {
            // Create new array with larger size (degree + 1)
            int *newDegCoeff = new int[degree + 1];

            // Copy old coefficients to new array
            for (int i = 0; i < capacity; i++)
            {
                newDegCoeff[i] = degCoeff[i];
            }

            // Initialize newly added spaces to 0
            for (int i = capacity; i <= degree; i++)
            {
                newDegCoeff[i] = 0;
            }

            // Delete old array and update pointer
            delete[] degCoeff;
            degCoeff = newDegCoeff;

            // Update capacity
            capacity = degree + 1;
        }

        // Finally, assign the coefficient
        degCoeff[degree] = coeff;
    }

    /**
     * @brief Prints polynomial in readable form.
     * Example:
     *   For coefficients {5, 0, 2}, prints: 5x0 2x2
     */
    void print() const
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }

    /**
     * @brief Overloaded + Operator for Polynomial Addition
     *
     * Logic:
     * - Create a new polynomial with capacity = max(capacity of both)
     * - Add coefficients of same degrees
     * - Copy remaining terms from longer polynomial
     *
     * Time Complexity: O(max(n, m))
     */
    Polynomial operator+(Polynomial const &p2)
    {
        Polynomial result;

        // Maximum degree among both polynomials
        int maxCap = max(capacity, p2.capacity);
        result.capacity = maxCap;
        result.degCoeff = new int[maxCap];

        for (int i = 0; i < maxCap; i++)
        {
            int val1 = (i < capacity) ? degCoeff[i] : 0;
            int val2 = (i < p2.capacity) ? p2.degCoeff[i] : 0;
            result.degCoeff[i] = val1 + val2;
        }

        return result;
    }

    /**
     * @brief Overloaded - Operator for Polynomial Subtraction
     *
     * Logic similar to addition, except we subtract coefficients.
     *
     * Time Complexity: O(max(n, m))
     */
    Polynomial operator-(Polynomial const &p2)
    {
        Polynomial result;
        int maxCap = max(capacity, p2.capacity);
        result.capacity = maxCap;
        result.degCoeff = new int[maxCap];

        for (int i = 0; i < maxCap; i++)
        {
            int val1 = (i < capacity) ? degCoeff[i] : 0;
            int val2 = (i < p2.capacity) ? p2.degCoeff[i] : 0;
            result.degCoeff[i] = val1 - val2;
        }

        return result;
    }

    /**
     * @brief Overloaded * Operator for Polynomial Multiplication
     *
     * Logic:
     * - Degree of result = sum of degrees (i + j)
     * - For each term in P1 and P2, multiply and add to correct position
     *
     * Example:
     *   (2x + 3) * (x + 4)
     *   = 2x² + 11x + 12
     *
     * Time Complexity: O(n × m)
     */
    Polynomial operator*(Polynomial const &p2)
    {
        Polynomial result;
        result.capacity = capacity + p2.capacity;
        result.degCoeff = new int[result.capacity];

        // Initialize result coefficients to 0
        for (int i = 0; i < result.capacity; i++)
        {
            result.degCoeff[i] = 0;
        }

        // Multiply each term of P1 with each term of P2
        for (int i = 0; i < capacity; i++)
        {
            for (int j = 0; j < p2.capacity; j++)
            {
                result.degCoeff[i + j] += degCoeff[i] * p2.degCoeff[j];
            }
        }

        return result;
    }
};

/*
----------------------------------------------------------
Main Function — Demonstration & Test Cases
----------------------------------------------------------
We will:
1️⃣ Create and initialize two polynomials.
2️⃣ Perform addition, subtraction, and multiplication.
3️⃣ Display results.
----------------------------------------------------------
*/
int main()
{
    // Create first polynomial p1 = 3x² + 2x + 5
    Polynomial p1;
    p1.setCoefficient(0, 5); // 5x⁰
    p1.setCoefficient(1, 2); // 2x¹
    p1.setCoefficient(2, 3); // 3x²

    cout << "Polynomial p1: ";
    p1.print(); // Expected: 5x0 2x1 3x2

    // Create second polynomial p2 = 4x³ + 1x + 1
    Polynomial p2;
    p2.setCoefficient(0, 1); // 1x⁰
    p2.setCoefficient(1, 1); // 1x¹
    p2.setCoefficient(3, 4); // 4x³

    cout << "Polynomial p2: ";
    p2.print(); // Expected: 1x0 1x1 4x3

    // --------------------------------------------------
    // Addition: (3x² + 2x + 5) + (4x³ + 1x + 1)
    // Expected = 4x³ + 3x² + 3x + 6
    // --------------------------------------------------
    Polynomial sum = p1 + p2;
    cout << "p1 + p2 = ";
    sum.print(); // Expected: 6x0 3x1 3x2 4x3

    // --------------------------------------------------
    // Subtraction: (3x² + 2x + 5) - (4x³ + 1x + 1)
    // Expected = -4x³ + 3x² + 1x + 4
    // --------------------------------------------------
    Polynomial diff = p1 - p2;
    cout << "p1 - p2 = ";
    diff.print(); // Expected: 4x0 1x1 3x2 -4x3

    // --------------------------------------------------
    // Multiplication: (3x² + 2x + 5) * (4x³ + 1x + 1)
    // --------------------------------------------------
    Polynomial prod = p1 * p2;
    cout << "p1 * p2 = ";
    prod.print();

    /*
        Detailed expansion:
        (3x² + 2x + 5)(4x³ + 1x + 1)
        = (3x² * 4x³) + (3x² * 1x) + (3x² * 1)
        + (2x * 4x³) + (2x * 1x) + (2x * 1)
        + (5 * 4x³) + (5 * 1x) + (5 * 1)
        = 12x⁵ + 3x³ + 3x² + 8x⁴ + 2x² + 2x + 20x³ + 5x + 5
        Combine like terms:
        = 12x⁵ + 8x⁴ + 23x³ + 5x² + 7x + 5
    */

    cout << "Expected product: 5x0 7x1 5x2 23x3 8x4 12x5" << endl;

    return 0;
}
