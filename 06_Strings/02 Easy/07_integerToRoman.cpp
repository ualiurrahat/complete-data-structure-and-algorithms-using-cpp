/**
 * @file 02_integerToRoman.cpp
 * @brief Convert an integer to a Roman numeral.
 *
 * Roman numerals are represented by seven symbols with specific values:
 * Symbol | Value
 * -------|-------
 * I      | 1
 * V      | 5
 * X      | 10
 * L      | 50
 * C      | 100
 * D      | 500
 * M      | 1000
 *
 * Roman numerals are constructed by appending values from highest to lowest.
 *
 * Rules:
 * - Use subtractive notation for values starting with 4 or 9 in any decimal place.
 * - Valid subtractive forms: IV (4), IX (9), XL (40), XC (90), CD (400), CM (900).
 * - I, X, C, and M can be repeated up to three times.
 *
 * Given an integer from 1 to 3999, convert it to the corresponding Roman numeral.
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Converts an integer to a Roman numeral.
 *
 * @param num Integer in the range [1, 3999]
 * @return string Roman numeral representation
 *
 * @note Time Complexity: O(1) — constant number of operations for max 4 digits
 * @note Space Complexity: O(1) — constant space used for lookup tables
 */
string intToRoman(int num)
{
    // ---------------------- Lookup Tables ----------------------
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string thousands[] = {"", "M", "MM", "MMM"};

    // ---------------------- Construct Roman Numeral ----------------------
    string roman = thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];

    return roman;
}

// ---------------------- Driver Code ----------------------
int main()
{
    // Sample test cases
    int n1 = 3749;
    int n2 = 58;
    int n3 = 1994;

    cout << "Input: " << n1 << "\nOutput: " << intToRoman(n1) << "\n\n";
    cout << "Input: " << n2 << "\nOutput: " << intToRoman(n2) << "\n\n";
    cout << "Input: " << n3 << "\nOutput: " << intToRoman(n3) << "\n";

    return 0;
}
