/**
 * @file 03_priorityCpuScheduling1.cpp
 * @brief Implementation of Priority CPU Scheduling Algorithm (Non-preemptive).
 *
 * Problem Statement:
 * ------------------
 * You are given ‘N’ processes with their “burst times” and “priorities”.
 * The arrival time for all processes is assumed to be 0.
 * Your task is to find the “waiting time” and “turnaround time” of each process
 * using the Priority CPU Scheduling algorithm.
 *
 * Rules:
 * -------
 * 1. The highest priority process is executed first.
 * 2. If two processes have the same priority, the one with the lower ID executes first.
 *
 * Definitions:
 * -------------
 * Waiting Time (WT) = Time spent by process waiting before execution.
 * Turnaround Time (TAT) = Total time from start till completion.
 *
 * Constraints:
 * -------------
 * 1 <= T <= 10
 * 1 <= N <= 10^4
 * 1 <= BURST[i], PRIORITY[i] <= 10^4
 *
 * Example:
 * --------
 * Input:
 *   N = 5
 *   burstTime = [2, 1, 3, 2, 1]
 *   priority   = [3, 4, 1, 2, 5]
 *
 * Output:
 *   Waiting Time:    2 1 6 4 0
 *   Turnaround Time: 4 2 9 6 1
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ------------------------------------------------------------
// Structure to represent a process
// ------------------------------------------------------------
/**
 * @brief Represents a process with priority, ID, and burst time.
 */
struct Process
{
    int priority;  ///< Priority of the process (higher value = higher priority)
    int id;        ///< Process ID (0-based index)
    int burstTime; ///< CPU burst time for the process

    Process(int p, int i, int b) : priority(p), id(i), burstTime(b) {}
};

// ------------------------------------------------------------
// Core Function
// ------------------------------------------------------------
/**
 * @brief Simulates Priority CPU Scheduling and calculates waiting and turnaround times.
 *
 * @param burstTime Vector containing burst times of all processes.
 * @param priority  Vector containing priorities of all processes.
 * @return vector<vector<int>>
 *         - First vector contains waiting times of all processes.
 *         - Second vector contains turnaround times of all processes.
 *
 * @note
 * Time Complexity: O(3n log n)
 *  - Sorting processes by priority and ID takes O(n log n),
 *    calculating times takes O(n).
 * Space Complexity: O(3n)
 *  - Storing process info, waiting, and turnaround times.
 */
vector<vector<int>> priorityCpuScheduling(vector<int> &burstTime, vector<int> &priority)
{
    int n = burstTime.size();

    // Step 1: Create a list of processes with (priority, id, burst time)
    vector<Process> processes;
    for (int i = 0; i < n; i++)
    {
        processes.push_back(Process(priority[i], i, burstTime[i]));
    }

    // Step 2: Sort by priority (descending) → if same, by process ID (ascending)
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         {
             if (a.priority != b.priority)
                 return a.priority > b.priority; // Higher priority first
             return a.id < b.id;                 // Lower ID first if priority same
         });

    // Step 3: Initialize waiting and turnaround time vectors
    vector<int> waitingTime(n);
    vector<int> turnaroundTime(n);

    // Step 4: Simulate CPU execution
    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        int processId = processes[i].id;
        int burst = processes[i].burstTime;

        // Waiting time = total time elapsed before the process starts
        waitingTime[processId] = currentTime;

        // CPU executes the current process
        currentTime += burst;

        // Turnaround time = total time from start till completion
        turnaroundTime[processId] = currentTime;
    }

    // Step 5: Return both result vectors
    return {waitingTime, turnaroundTime};
}

// ------------------------------------------------------------
// Driver Code
// ------------------------------------------------------------
int main()
{
    int n = 5;
    vector<int> burstTime = {2, 1, 3, 2, 1};
    vector<int> priority = {3, 4, 1, 2, 5};

    vector<vector<int>> result = priorityCpuScheduling(burstTime, priority);

    cout << "Waiting Time: ";
    for (int wt : result[0])
        cout << wt << " ";
    cout << endl;

    cout << "Turnaround Time: ";
    for (int tat : result[1])
        cout << tat << " ";
    cout << endl;

    /*
        Expected Output:
        Waiting Time:    2 1 6 4 0
        Turnaround Time: 4 2 9 6 1
    */
    return 0;
}
