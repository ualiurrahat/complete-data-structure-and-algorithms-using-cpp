/**
 * @file 01_shortestJobFirstScheduling.cpp
 * @brief Greedy Algorithm — Shortest Job First (Non-Preemptive) Average Waiting Time
 *
 * Problem:
 * Given the burst times of 'n' processes, compute the average waiting time
 * following the non-preemptive Shortest Job First (SJF) scheduling policy.
 *
 * Important:
 * - All processes arrive at time 0.
 * - SJF selects the process with the smallest burst time first.
 * - You must return the floor of the average waiting time
 *   (i.e., the nearest integer smaller or equal to the exact result).
 *
 * Example 1:
 * n = 5
 * bt = [4, 3, 7, 1, 2]
 * After sorting = [1, 2, 3, 4, 7]
 * Waiting times = [0,1,3,6,10] → Average = 20/5 = 4
 *
 * Example 2:
 * n = 4
 * bt = [1,2,3,4]
 * Waiting times = [0,1,3,6] → Average = 10/4 = 2
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Computes the average waiting time using non-preemptive SJF.
 *
 * @param bt Vector containing burst times of the processes.
 * @return long long Average waiting time (floored).
 *
 * @details
 * Logic Explanation (Your original logic preserved and rewritten professionally):
 * -------------------------------------------------------------------------------
 * - Since all processes arrive at time 0, SJF reduces to simply sorting burst times.
 * - After sorting, each process waits for the sum of all previous burst times.
 * - Maintain:
 *      • totalTime → cumulative CPU time completed so far
 *      • waitTime  → sum of waiting times of all processes
 * - For each burst time:
 *      waitTime += totalTime        (time spent waiting)
 *      totalTime += bt[i]           (execute current process)
 *
 * - Finally return waitTime / n (floor division).
 *
 * Time Complexity: O(n log n) due to sorting.
 * Space Complexity: O(1) extra space (sorting is in-place).
 */
long long solve(vector<int> &bt)
{

    // Sort burst times as required by SJF (shortest job executes first)
    sort(bt.begin(), bt.end());

    int n = bt.size();
    long long waitTime = 0;
    long long totalTime = 0;

    // Accumulate waiting times
    for (int i = 0; i < n; i++)
    {
        waitTime += totalTime; // waiting time for current process
        totalTime += bt[i];    // update total elapsed time
    }

    // Return floor of the average waiting time
    return waitTime / n;
}

int main()
{

    // Test Case 1
    vector<int> bt1 = {4, 3, 7, 1, 2};
    cout << "Output (Expected 4): " << solve(bt1) << endl;

    // Test Case 2
    vector<int> bt2 = {1, 2, 3, 4};
    cout << "Output (Expected 2): " << solve(bt2) << endl;

    return 0;
}
