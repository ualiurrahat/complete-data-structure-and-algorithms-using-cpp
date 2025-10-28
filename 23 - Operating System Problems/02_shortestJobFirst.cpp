/**
 * @file 02_shortestJobFirst.cpp
 * @brief Implementation of Shortest Job First (Non-preemptive) Scheduling Algorithm.
 *
 * Problem Statement:
 * ------------------
 * You are given ‘N’ processes with their respective process id, arrival time, and burst time.
 * Your task is to schedule the given ‘N’ processes using the Shortest Job First (SJF) scheduling algorithm
 * and find their respective waiting time and turnaround time.
 *
 * Shortest Job First is a scheduling algorithm in which the process having the shortest execution time
 * is chosen for the next execution. Here, we implement a non-preemptive version — once a process starts
 * execution, it runs till completion.
 *
 * Formulas:
 * ----------
 * Completion Time = Time at which the process finishes execution
 * Turnaround Time = Completion Time – Arrival Time
 * Waiting Time     = Turnaround Time – Burst Time
 *
 * Example:
 * --------
 * Input:
 *   N = 3
 *   processId = [1, 3, 2]
 *   arrivalTime = [3, 1, 4]
 *   burstTime = [2, 5, 1]
 *
 * Output:
 *   3 1 5 0 5
 *   2 4 1 2 3
 *   1 3 2 4 6
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ------------------------------------------------------------
// Comparator Function
// ------------------------------------------------------------
/**
 * @brief Comparator for sorting processes by arrival time, then burst time, then process ID.
 *
 * @param process1 Vector containing details of first process
 * @param process2 Vector containing details of second process
 * @return true if process1 should appear before process2
 */
bool compareProcess(const vector<int> &process1, const vector<int> &process2)
{
    if (process1[1] != process2[1])
        return process1[1] < process2[1]; // Sort by arrival time
    else if (process1[2] != process2[2])
        return process1[2] < process2[2]; // Then by burst time
    else
        return process1[0] < process2[0]; // Then by process ID
}

// ------------------------------------------------------------
// Core Function
// ------------------------------------------------------------
/**
 * @brief Computes the scheduling order and times for SJF (Non-preemptive).
 *
 * @param n Number of processes
 * @param processId Vector of process IDs
 * @param arrivalTime Vector of arrival times
 * @param burstTime Vector of burst times
 * @return vector<vector<int>> Each inner vector contains:
 *         [processId, arrivalTime, burstTime, waitingTime, turnaroundTime]
 *
 * @note
 * Time Complexity: O(4n²)
 * - Outer loop O(n), inner selection loop O(n), sorting O(n log n) but dominated by nested loop.
 * Space Complexity: O(6n)
 * - For storing process details and results.
 */
vector<vector<int>> shortestJobFirst(int n, vector<int> &processId,
                                     vector<int> &arrivalTime, vector<int> &burstTime)
{
    // processDetails[i] = {processId, arrivalTime, burstTime, completionTime, waitingTime, turnaroundTime}
    vector<vector<int>> processDetails(n, vector<int>(6));

    // Step 1: Initialize process details
    for (int i = 0; i < n; i++)
    {
        processDetails[i][0] = processId[i];
        processDetails[i][1] = arrivalTime[i];
        processDetails[i][2] = burstTime[i];
    }

    // Step 2: Sort processes by arrival time → burst time → processId
    sort(processDetails.begin(), processDetails.end(), compareProcess);

    // Step 3: Assign times for the first process
    processDetails[0][3] = processDetails[0][1] + processDetails[0][2]; // Completion Time
    processDetails[0][5] = processDetails[0][3] - processDetails[0][1]; // Turnaround Time
    processDetails[0][4] = processDetails[0][5] - processDetails[0][2]; // Waiting Time

    // Step 4: Schedule remaining processes
    for (int i = 1; i < n; i++)
    {
        int prevCompTime = processDetails[i - 1][3]; // Completion time of last executed process
        int currBurstTime = processDetails[i][2];
        int currId = processDetails[i][0];
        int index = i;

        // Find process with smallest burst time among those that have arrived
        for (int j = i; j < n; j++)
        {
            if (processDetails[j][1] <= prevCompTime)
            {
                if (processDetails[j][2] < currBurstTime ||
                    (processDetails[j][2] == currBurstTime && processDetails[j][0] < currId))
                {
                    currBurstTime = processDetails[j][2];
                    currId = processDetails[j][0];
                    index = j;
                }
            }
        }

        // Compute timing metrics for the selected process
        processDetails[index][3] = max(prevCompTime, processDetails[index][1]) + processDetails[index][2];
        processDetails[index][5] = processDetails[index][3] - processDetails[index][1]; // Turnaround Time
        processDetails[index][4] = processDetails[index][5] - processDetails[index][2]; // Waiting Time

        // Swap the selected process into the current position
        swap(processDetails[index], processDetails[i]);
    }

    // Step 5: Prepare final result excluding completion time
    vector<vector<int>> result(n, vector<int>(5));
    for (int i = 0; i < n; i++)
    {
        int idx = 0;
        for (int j = 0; j < 6; j++)
        {
            if (j != 3)
            { // Exclude completion time
                result[i][idx++] = processDetails[i][j];
            }
        }
    }

    return result;
}

// ------------------------------------------------------------
// Driver Code
// ------------------------------------------------------------
int main()
{
    int n = 3;
    vector<int> processId = {1, 3, 2};
    vector<int> arrivalTime = {3, 1, 4};
    vector<int> burstTime = {2, 5, 1};

    vector<vector<int>> result = shortestJobFirst(n, processId, arrivalTime, burstTime);

    cout << "ProcessID  Arrival  Burst  Waiting  Turnaround" << endl;
    for (auto &row : result)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    /*
        Expected Output:
        3 1 5 0 5
        2 4 1 2 3
        1 3 2 4 6
    */
    return 0;
}
