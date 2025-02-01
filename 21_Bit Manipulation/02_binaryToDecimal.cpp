#include <bits/stdc++.h>
using namespace std;

// Function to convert a binary string to its decimal equivalent
int convertBinary2Decimal(string &str)
{
    int decimal = 0;      // Initialize decimal result
    int power = 1;        // Initialize power of 2 (starting from 2^0)
    int n = str.length(); // Get the length of the binary string

    // Traverse the binary string from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == '1') // If the character is '1', add the corresponding power of 2
        {
            decimal = decimal + 1 * power;
        }
        power *= 2; // Update power of 2 for the next position
    }
    return decimal; // Return the computed decimal value
    // T:O(N)-->O(size of string)
    // S:O(1)
}

int main()
{
    int n;
    cout << "Total Enquiry: ";
    cin >> n; // Number of test cases

    while (n--)
    {
        string binary;
        cout << "Enter binary number: ";
        cin >> binary; // Read binary number as string

        int decimal = convertBinary2Decimal(binary); // Convert binary to decimal
        cout << "Equivalent Decimal: " << decimal << endl
             << endl; // Output the decimal equivalent
    }

    return 0; // End of program
}
