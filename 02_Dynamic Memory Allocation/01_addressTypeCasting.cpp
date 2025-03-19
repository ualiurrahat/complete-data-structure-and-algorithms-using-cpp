// Introduction to Typecasting: Converting one data type into another.
// - Implicit Typecasting: Performed automatically by the compiler.
// - Explicit Typecasting: Performed manually by the programmer.

// Best practice: Always use explicit typecasting when necessary.

#include <iostream>

using namespace std;

int main()
{
    int i = 65;
    char c = i;        // Implicit typecasting: The integer 65 is automatically converted to a character ('A').
    cout << c << endl; // Output: A

    int *p = &i;
    // char *pc = p; // This line would cause a compilation error.
    // Reason: Directly assigning an integer pointer to a character pointer is not allowed.
    // However, explicit typecasting can be used to achieve this.

    char *pc = (char *)p; // Explicit typecasting: Converting an integer pointer to a character pointer.

    cout << *p << endl;  // Output: 65 (integer value stored at the address)
    cout << *pc << endl; // Output: 'A' (interpreted from the first byte of integer memory)

    // Why does *pc print 'A' (ASCII 65) instead of *(pc + 3)?
    // Answer: It depends on how integers are stored in memory.
    // Two memory storage formats exist:
    // 1) Little Endian: Least significant byte is stored first (lower memory address).
    // 2) Big Endian: Most significant byte is stored first.

    // Most modern architectures use Little Endian format.
    // In Little Endian, an integer is stored starting from the lowest memory address.
    // Hence, the first byte of 'i' (which contains 65 or ASCII 'A') is accessed first.

    cout << *(pc + 1) << endl; // Output: 0 (next byte in memory, since '65' fits in one byte)
    cout << *(pc + 2) << endl; // Output: 0 (next byte in memory)
    cout << *(pc + 3) << endl; // Output: 0 (next byte in memory)

    cout << p << endl;  // Output: Address of 'i' (integer variable).
    cout << pc << endl; // Output: The content of 'i' as a character array until a null character ('\0') is encountered.
                        // Since 'i' is 65 ('A'), and the following bytes are zero, it prints 'A' only.

    return 0;
}
