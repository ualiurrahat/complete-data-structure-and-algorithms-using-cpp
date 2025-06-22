/**

 * Problem Statement:
 * ---------------------------------------------------------------
 * Design a stack that supports push, pop, top, and retrieving
 * the minimum element in constant time.
 *
 * Implement the MinStack class:
 * - MinStack() initializes the stack object.
 * - void push(int val) pushes the element val onto the stack.
 * - void pop() removes the element on the top of the stack.
 * - int top() gets the top element of the stack.
 * - int getMin() retrieves the minimum element in the stack.
 *
 * All operations must run in O(1) time.
 */
#include <iostream>
#include <stack>
#include <utility>

using namespace std;
// ---------------------- Brute Force Approach ----------------------

/**
 * @class MinStack
 * @brief Brute force solution using a pair stack to store current value and current minimum.
 *        This results in O(1) time and O(2N) space (since we store two integers per element).
 */

class MinStack
{
    // In each pair: first -> value, second -> minimum till this point
    stack<pair<int, int>> st;

public:
    /** Initialize the stack */
    MinStack() {}

    /**
     * @brief Push a value onto the stack
     * @param val The value to push
     */
    void push(int val)
    {
        if (st.empty())
        {
            // First element; it's the minimum
            st.push({val, val});
        }
        else
        {
            // Compare with current minimum
            int currentMin = min(val, st.top().second);
            st.push({val, currentMin});
        }
    }

    /**
     * @brief Remove the top element
     */
    void pop()
    {
        st.pop();
    }

    /**
     * @brief Get the top value
     * @return The value at the top of the stack
     */
    int top()
    {
        return st.top().first;
    }

    /**
     * @brief Get the current minimum
     * @return Minimum value in the stack
     */
    int getMin()
    {
        return st.top().second;
    }
};

/**
 * @note
 * ✅ Time Complexity: O(1) for all operations
 * ❌ Space Complexity: O(2N) since each element stores (value, minTillNow)
 */

// ---------------------- Optimized Approach ----------------------

/**
 * @class MinStack
 * @brief Optimized solution using a single stack and encoding technique to store minimum values.
 *        Achieves O(1) time and O(N) space.
 */
class MinStack
{
    stack<long long> st; // Stores values or encoded values
    long long mini;      // Tracks the current minimum

public:
    /** Initialize the stack */
    MinStack() {}

    /**
     * @brief Push a value onto the stack
     * @param val The value to push
     */
    void push(int val)
    {
        long long value = val;

        if (st.empty())
        {
            mini = value;
            st.push(value); // First value, no encoding needed
        }
        else if (value >= mini)
        {
            st.push(value); // Normal value
        }
        else
        {
            // Encode the value to store the previous minimum
            long long encoded = 2LL * value - mini;
            st.push(encoded);
            mini = value; // Update the current minimum
        }
    }

    /**
     * @brief Remove the top element
     */
    void pop()
    {
        if (st.empty())
            return;

        long long topVal = st.top();
        st.pop();

        if (topVal < mini)
        {
            // It was an encoded value, decode to get previous min
            mini = 2LL * mini - topVal;
        }
    }

    /**
     * @brief Get the top element
     * @return Top value (decoded if it was encoded)
     */
    int top()
    {
        long long topVal = st.top();

        if (topVal >= mini)
        {
            return topVal;
        }
        else
        {
            // This was an encoded value; actual value is mini
            return mini;
        }
    }

    /**
     * @brief Retrieve the minimum value in the stack
     * @return Current minimum
     */
    int getMin()
    {
        return mini;
    }
};

/**
 * @note
 * ✅ Time Complexity: O(1) for push, pop, top, and getMin
 * ✅ Space Complexity: O(N), using just one stack
 *
 * 💡 Why this works:
 * When pushing a new minimum, we encode it using:
 *     encoded = 2 * newMin - oldMin
 * During pop, we decode previous min as:
 *     oldMin = 2 * currentMin - encoded
 * This trick allows us to avoid an extra stack.
 */
