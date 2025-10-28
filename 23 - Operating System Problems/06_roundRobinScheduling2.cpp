/**
 * @file roundRobinCompletionTime.cpp
 * @brief Program to find completion time of processes using Round Robin CPU Scheduling.
 *
 * @details
 * Problem Statement:
 * You have been given 'N' processes with process IDs from 1 to 'N'.
 * For each process, you are given the arrival time and burst time.
 * You are also provided with a time quantum.
 *
 * You must execute the Round Robin scheduling algorithm and find the
 * completion time for each process.
 *
 * Rules:
 * - Each process receives CPU for a fixed quantum.
 * - If a process’s remaining time exceeds the quantum, it is re-added
 *   to the ready queue.
 * - If two processes arrive at the same time, the one with the smaller
 *   process ID executes first.
 *
 * @note
 * Arrival Time = Time when the process becomes ready.
 * Burst Time = Total execution time required by process.
 * Completion Time = Time when the process finishes execution.
 *
 * @constraints
 * 1 <= T <= 5
 * 1 <= N <= 1000
 * 1 <= M <= 1000
 * 1 <= ARRIVALTIME[i], BURSTTIME[i] <= 1000
 *
 * @example
 * Input:
 * 2
 * 4 2
 * 0 5
 * 1 4
 * 2 2
 * 3 1
 * 1 4
 * 3 5
 *
 * Output:
 * 12 11 6 9
 * 8
 *
 * @explanation
 * For first test case, Round Robin execution order:
 * {0, (0:2)} → {1, (2:4)} → {2, (4:6)} → {0, (6:8)} → {3, (8:9)} → {1, (9:11)} → {0, (11:12)}
 * Hence completion times = [12, 11, 6, 9].
 *
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Comparison function to sort processes by arrival time, then by ID.
 * @param a Process 1 (vector<int>)
 * @param b Process 2 (vector<int>)
 * @return true if process 'a' should come before 'b'
 */
bool compare(vector<int> &a, vector<int> &b)
{
    if (a[1] != b[1])
        return a[1] < b[1]; // Sort by arrival time
    else
        return a[0] < b[0]; // If tie, sort by process ID
}

/**
 * @brief Finds the completion time of each process using Round Robin Scheduling.
 *
 * @param arrivalTime Vector of process arrival times
 * @param burstTime Vector of process burst times
 * @param n Number of processes
 * @param quantum Time quantum for Round Robin
 * @return vector<int> Containing completion time of each process
 *
 * @note
 * - Time Complexity: O(4n) ≈ O(n), since each process may be revisited multiple times
 * - Space Complexity: O(3n) ≈ O(n), for queues and tracking arrays
 */
vector<int> getCompletionTime(vector<int> &arrivalTime, vector<int> &burstTime, int n, int quantum)
{
    // ---------------------- Step 1: Prepare process data ----------------------
    vector<vector<int>> process(n, vector<int>(3)); // {id, arrivalTime, burstTime}
    vector<int> remTime(n);                         // Remaining burst time
    vector<int> completionTime(n, 0);               // Final completion times

    for (int i = 0; i < n; i++)
    {
        process[i][0] = i;              // Process ID (0-indexed)
        process[i][1] = arrivalTime[i]; // Arrival Time
        process[i][2] = burstTime[i];   // Burst Time
        remTime[i] = burstTime[i];      // Initialize remaining time
    }

    // Sort processes by arrival time and ID
    sort(process.begin(), process.end(), compare);

    // ---------------------- Step 2: Initialize variables ----------------------
    int currentTime = process[0][1]; // Start from first process arrival
    int lastID = 1;                  // Next process to be added to queue
    int completed = 0;               // Completed process count
    queue<int> readyQueue;           // Ready queue (holds process IDs)
    readyQueue.push(process[0][0]);

    // ---------------------- Step 3: Round Robin Execution ----------------------
    while (completed != n)
    {
        int id = readyQueue.front();
        readyQueue.pop();

        // If remaining time > quantum, execute for one quantum
        if (remTime[id] > quantum)
        {
            remTime[id] -= quantum;
            currentTime += quantum;
        }
        else
        {
            // Process completes
            currentTime += remTime[id];
            completionTime[id] = currentTime;
            remTime[id] = 0;
            completed++;
        }

        // Add newly arrived processes to ready queue
        while (lastID < n && process[lastID][1] <= currentTime)
        {
            readyQueue.push(process[lastID][0]);
            lastID++;
        }

        // If current process not finished, requeue it
        if (remTime[id] > 0)
            readyQueue.push(id);

        // If queue empty but some processes left, jump to next arrival
        if (readyQueue.empty() && lastID < n)
        {
            currentTime = process[lastID][1];
            readyQueue.push(process[lastID][0]);
            lastID++;
        }
    }

    return completionTime;
}

// ---------------------- Main Function (Demonstration) ----------------------
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, quantum;
        cin >> n >> quantum;

        vector<int> arrivalTime(n), burstTime(n);

        for (int i = 0; i < n; i++)
            cin >> arrivalTime[i] >> burstTime[i];

        vector<int> result = getCompletionTime(arrivalTime, burstTime, n, quantum);

        for (int time : result)
            cout << time << " ";
        cout << endl;
    }

    return 0;
}
