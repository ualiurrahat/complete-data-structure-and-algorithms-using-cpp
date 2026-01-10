/**
 * @file 06_minRotationsToUnlockCircularLock.cpp
 *
 * @brief Problem Statement:
 * Given a lock made up of N circular rings. Each ring has digits from 0 to 9.
 * You are given:
 *     R → current (random) lock configuration
 *     D → desired (target) lock configuration
 *
 * Each ring can be rotated in:
 *     - clockwise direction
 *     - anti-clockwise direction
 *
 * Rotating any ring by 1 step takes 1 unit of time.
 *
 * The task is to compute the **minimum number of rotations** required to convert
 * configuration R into configuration D.
 *
 * Examples:
 *
 * Example 1:
 *     Input : R = 222, D = 333
 *     Output: 3
 *     Explanation:
 *         Each 2 → 3 requires exactly 1 step.
 *         Total = 1 + 1 + 1 = 3 rotations.
 *
 * Example 2:
 *     Input : R = 2345, D = 5432
 *     Output: 8
 *     Explanation:
 *         Transform pairs (digit by digit from right side):
 *             5 ↔ 2 → 3 steps
 *             4 ↔ 3 → 1 step
 *             3 ↔ 4 → 1 step
 *             2 ↔ 5 → 3 steps
 *         Total = 3 + 1 + 1 + 3 = 8 steps.
 *
 * Constraints:
 *     1 ≤ R, D < 10^18
 *
 * Expected Time Complexity:
 *     O(log R) — because we process each digit of R
 *
 * Expected Auxiliary Space:
 *     O(1)
 */

#include <iostream> // For input/output operations
#include <cstdlib>  // For abs() function
using namespace std;

/**
 * @brief Computes the minimum number of rotations needed to turn lock R into D.
 *
 * @param R The current lock configuration (random numeric sequence).
 * @param D The desired lock configuration (target numeric sequence).
 *
 * @return Minimum number of rotations required to make R equal to D.
 *
 * @details
 * We treat both R and D as numbers and compare them digit-by-digit from the RIGHT.
 * For every ring:
 *     - Extract the last digit of R → this is the current ring position.
 *     - Extract the last digit of D → this is the target ring position.
 *
 * The rotation cost between digits a and b is:
 *       min( |a - b| , 10 - |a - b| )
 *
 * Because:
 *     - |a - b| = clockwise distance
 *     - 10 - |a - b| = anti-clockwise distance
 *
 * We always choose the smaller one.
 *
 * After processing a digit, divide R and D by 10 to move to the next ring.
 *
 * Time Complexity:
 *     O(log R) — proportional to number of digits in R.
 *
 * Space Complexity:
 *     O(1) — constant extra memory.
 */
int rotationCount(long long R, long long D)
{

    int totalRotations = 0; // Will store the sum of all minimum rotations

    // Loop continues as long as R has digits left.
    // (No need to check D separately because constraints guarantee equal length.)
    while (R > 0)
    {

        // Extract last digits (ring positions)
        int currentRing = R % 10; // Current digit of R
        int targetRing = D % 10;  // Expected digit of D

        // Absolute (straight) clockwise distance
        int directRotation = abs(currentRing - targetRing);

        // Circular anti-clockwise distance
        int reverseRotation = 10 - directRotation;

        // Minimum of the two — optimal rotation for this ring
        int optimalStep = min(directRotation, reverseRotation);

        // Add to total rotation count
        totalRotations += optimalStep;

        // Remove last digit to process next ring
        R /= 10;
        D /= 10;
    }

    return totalRotations;
}

int main()
{

    // Example Test Case 1
    long long R1 = 222;
    long long D1 = 333;
    cout << rotationCount(R1, D1) << "  <-- Expected Output: 3" << endl;

    // Example Test Case 2
    long long R2 = 2345;
    long long D2 = 5432;
    cout << rotationCount(R2, D2) << "  <-- Expected Output: 8" << endl;

    // Custom Test Case
    long long R3 = 9081;
    long long D3 = 1209;
    cout << rotationCount(R3, D3) << "  <-- Custom Example Output" << endl;

    return 0;
}
