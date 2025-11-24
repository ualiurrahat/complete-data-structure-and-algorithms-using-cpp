/**
 * @file 02_lemonadeChange.cpp
 * @brief Greedy Algorithm — Lemonade Change
 *
 * You run a lemonade stand where each lemonade costs $5.
 * Customers are in a queue and each customer pays using a $5, $10, or $20 bill.
 * You must return correct change for each customer.
 *
 * You start with $0.
 * Return true if you can serve all customers with correct change, otherwise false.
 *
 * Example 1:
 * bills = [5,5,5,10,20]
 * Output: true
 *
 * Example 2:
 * bills = [5,5,10,10,20]
 * Output: false
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Determines if correct change can be given to every customer.
 *
 * @param bills Vector of bills customers pay in order.
 * @return true If all customers can be served with proper change.
 * @return false Otherwise.
 *
 * @details
 * Logic (Your original explanation preserved professionally):
 * -----------------------------------------------------------
 * - Maintain counters for $5 bills and $10 bills.
 * - For each customer:
 *      • If they pay $5 → increase five-dollar count.
 *      • If they pay $10 → must give back one $5.
 *      • If they pay $20 → must give $15 change, using:
 *              1) one $10 + one $5 (preferred)
 *              2) otherwise, three $5 bills
 *
 * - If at any point change cannot be given → return false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
bool lemonadeChange(vector<int> &bills)
{

    // to keep track of number of five and ten dollara available
    int fives = 0, tens = 0;

    int n = bills.size();

    for (int i = 0; i < n; i++)
    {
        if (bills[i] == 5)
        {
            // update five
            fives++;
        }
        else if (bills[i] == 10)
        {
            // check if $5 note is available
            if (fives)
            {
                // take the $10 note and return one $5 note
                tens++;
                fives--;
            }
            // if $5 note not available, customer cannot be served
            else
            {
                return false;
            }
        }
        // case for customer giving $20
        else
        {
            // need to give change i.e. $15 to the customer
            // way 1: one $10 + one $5
            if (tens && fives)
            {
                tens--;
                fives--;
            }
            // way 2: three $5 (when $10 is not available)
            else if (fives >= 3)
            {
                fives = fives - 3;
            }
            // no way giving change to customer is possible
            else
            {
                return false;
            }
        }
    }

    // if loop has rung till here, means all the customers have been served
    // successfully. so return true
    return true;
}

int main()
{

    vector<int> b1 = {5, 5, 5, 10, 20};
    cout << "Output (Expected true): " << (lemonadeChange(b1) ? "true" : "false") << endl;

    vector<int> b2 = {5, 5, 10, 10, 20};
    cout << "Output (Expected false): " << (lemonadeChange(b2) ? "true" : "false") << endl;

    return 0;
}
