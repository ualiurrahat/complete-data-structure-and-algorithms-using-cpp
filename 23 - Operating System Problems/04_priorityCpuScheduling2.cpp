/**
 * @file priorityScheduling.cpp
 * @brief Implementation of Non-Preemptive Priority Based CPU Scheduling Algorithm.
 *
 * @problem
 * You are given the arrival times, the burst times, and the priority of ‘N’ processes in a CPU.
 * You need to find the order of process scheduling according to Priority Based CPU Scheduling.
 * Along with the order, also find the individual waiting and turnaround time for all the processes
 * in order of their schedule.
 *
 * @note
 * 1. The processes are numbered from 1 to 'N'.
 * 2. The process with the lowest arrival time will be scheduled first.
 * 3. If two processes have the same arrival time, the process with higher priority executes first.
 * 4. If both arrival time and priority are same, execute the process with the lowest process number.
 *
 * @example
 * Input:
 * 1
 * 5
 * 0 1 3 2 4
 * 3 6 1 2 4
 * 3 4 9 7 8
 *
 * Output:
 * 1 2 4 3 5
 * 0 2 7 8 8
 * 3 8 9 9 12
 *
 * @constraints
 * 1 <= T <= 10
 * 1 <= N <= 10^4
 * 1 <= X, Y, Z <= 10^4
 * Time Limit: 1 sec
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -----------------------------------------------------------
// Comparator to sort processes based on arrival, priority, and ID
// -----------------------------------------------------------
bool compare(vector<int> &firstProcess, vector<int> &secondProcess)
{
    // Case 1: If arrival time is same
    if (firstProcess[1] == secondProcess[1])
    {
        // Case 2: If priority is same
        if (firstProcess[3] == secondProcess[3])
        {
            // Sort by process ID (ascending)
            return firstProcess[0] < secondProcess[0];
        }
        // Otherwise, sort by priority (higher first)
        return firstProcess[3] > secondProcess[3];
    }
    // Otherwise, sort by arrival time (earlier first)
    return firstProcess[1] < secondProcess[1];
}

/**
 * @brief Returns the order of scheduled processes.
 * @param processDetails A 2D vector of processes [ID, Arrival, Burst, Priority].
 * @return Vector containing the process execution order.
 */
vector<int> findOrder(vector<vector<int>> &processDetails)
{
    vector<int> order;
    for (auto &p : processDetails)
        order.push_back(p[0]);
    return order;
}

/**
 * @brief Calculates waiting times for all processes.
 * @param processDetails A 2D vector of processes [ID, Arrival, Burst, Priority].
 * @return Vector containing waiting times for each process.
 *
 * @note
 * Waiting Time = Start Time - Arrival Time
 */
vector<int> findWaitingTime(vector<vector<int>> &processDetails)
{
    int n = processDetails.size();
    vector<int> startTime(n), waitTime(n);

    // First process starts at its arrival time
    startTime[0] = processDetails[0][1];
    waitTime[0] = 0;

    // For subsequent processes
    for (int i = 1; i < n; i++)
    {
        // Next process starts when the previous one finishes
        startTime[i] = startTime[i - 1] + processDetails[i - 1][2];
        // Waiting time = Start - Arrival
        waitTime[i] = startTime[i] - processDetails[i][1];
        if (waitTime[i] < 0)
            waitTime[i] = 0; // No negative waiting time
    }
    return waitTime;
}

/**
 * @brief Calculates turnaround times for all processes.
 * @param processDetails A 2D vector of processes [ID, Arrival, Burst, Priority].
 * @param waitTime Corresponding waiting times.
 * @return Vector containing turnaround times.
 *
 * @note
 * Turnaround Time = Waiting Time + Burst Time
 */
vector<int> findTurnTime(vector<vector<int>> &processDetails, vector<int> &waitTime)
{
    int n = processDetails.size();
    vector<int> turnTime(n);
    for (int i = 0; i < n; i++)
    {
        turnTime[i] = waitTime[i] + processDetails[i][2];
    }
    return turnTime;
}

/**
 * @brief Implements Priority Based Non-Preemptive Scheduling Algorithm.
 * @param arrivalTime Vector of process arrival times.
 * @param burstTime Vector of process burst times.
 * @param priority Vector of process priorities.
 * @return A 2D vector:
 *         [0] → Process execution order
 *         [1] → Waiting times
 *         [2] → Turnaround times
 *
 * @note
 * @timecomplexity O(3n log n) due to sorting and linear traversals.
 * @spacecomplexity O(3n) for storing process details, waiting, and turnaround times.
 */
vector<vector<int>> priorityScheduling(vector<int> &arrivalTime,
                                       vector<int> &burstTime,
                                       vector<int> &priority)
{
    int n = arrivalTime.size();

    // Store process details in the form [ID, Arrival, Burst, Priority]
    vector<vector<int>> processDetails(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        processDetails[i][0] = i + 1;
        processDetails[i][1] = arrivalTime[i];
        processDetails[i][2] = burstTime[i];
        processDetails[i][3] = priority[i];
    }

    // Sort processes by arrival time, then priority, then ID
    sort(processDetails.begin(), processDetails.end(), compare);

    // Compute required results
    vector<int> order = findOrder(processDetails);
    vector<int> waitTime = findWaitingTime(processDetails);
    vector<int> turnTime = findTurnTime(processDetails, waitTime);

    return {order, waitTime, turnTime};
}

// -----------------------------------------------------------
// Main Function (Example Demonstration)
// -----------------------------------------------------------
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> arrival(N), burst(N), priority(N);

        for (int i = 0; i < N; i++)
            cin >> arrival[i];
        for (int i = 0; i < N; i++)
            cin >> burst[i];
        for (int i = 0; i < N; i++)
            cin >> priority[i];

        vector<vector<int>> result = priorityScheduling(arrival, burst, priority);

        // Output process order
        for (int x : result[0])
            cout << x << " ";
        cout << "\n";

        // Output waiting times
        for (int x : result[1])
            cout << x << " ";
        cout << "\n";

        // Output turnaround times
        for (int x : result[2])
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}

/**
 * @example
 * Input:
 * 1
 * 5
 * 0 1 3 2 4
 * 3 6 1 2 4
 * 3 4 9 7 8
 *
 * Output:
 * 1 2 4 3 5
 * 0 2 7 8 8
 * 3 8 9 9 12
 *
 * @note
 * This program implements non-preemptive scheduling,
 * meaning once a process starts, it runs until completion.
 */
