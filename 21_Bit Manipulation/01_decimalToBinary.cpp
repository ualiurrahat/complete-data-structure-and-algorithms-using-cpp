#include <bits/stdc++.h>
using namespace std;

// Function to reverse the binary string

void reverse(string &str)
{
    int len = str.length();
    for (int i = 0; i < (len / 2); i++)
    {
        swap(str[i], str[len - i - 1]); // Swapping characters to reverse the string
    }
    // T:O(len /2)
    // S:O(1)
}

// Function to convert a decimal number to its binary representation
string convertDecimal2Binary(int n)
{
    string res = ""; // Initialize an empty string to store the binary representation

    // Convert decimal to binary (in reverse order)
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            res += "1"; // Append '1' if remainder is 1
        }
        else
        {
            res += "0"; // Append '0' if remainder is 0
        }
        n = n / 2; // Reduce n by dividing by 2
    }

    reverse(res); // Call the reverse function (but it does not modify `res` due to pass-by-value)

    return res; // Return the binary string (still in reverse order)
    // T:O(log2base*n)
    // S:O(log2base *n)
}

int main()
{
    int n;
    cout << "Total Enquiry: ";
    cin >> n; // Number of test cases

    while (n--)
    {
        int decimal;
        cout << "Enter decimal number: ";
        cin >> decimal; // Read decimal number input

        string binary = convertDecimal2Binary(decimal); // Convert to binary
        cout << "Equivalent Binary: " << binary << endl
             << endl; // Print the binary representation
    }

    return 0; // End of program
}
