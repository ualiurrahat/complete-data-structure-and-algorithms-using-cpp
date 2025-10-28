/**
 * @file roundRobinScheduling.cpp
 * @brief Implementation of Round Robin CPU Scheduling Algorithm.
 *
 * @problem
 * In an operating system, processes are scheduled using many algorithms.
 * One such algorithm is the **Round Robin Algorithm**, which ensures equal CPU sharing.
 * Each process gets a fixed time quantum `t` for execution. After using its time,
 * the process moves to the end of the ready queue, and the next process executes.
 *
 * The goal is to simulate the Round Robin CPU scheduling, compute:
 * - Waiting time for each process
 * - Turnaround time for each process
 * - Average waiting and turnaround times
 *
 * @example
 * Input:
 * 1
 * 3 2
 * 1 2 3
 * 10 5 8
 *
 * Output:
 * 12 19
 *
 * @explanation
 * Average Waiting Time = (13 + 10 + 13) / 3 = 12
 * Average Turnaround Time = (23 + 15 + 21) / 3 = 19
 *
 * @constraints
 * 1 <= T <= 10
 * 1 <= N <= 10^4
 * 1 <= Burst[i], Quantum <= 10^4
 * Time Limit: 1 sec
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ------------------------------------------------------------
// Function to compute waiting times for all processes
// ------------------------------------------------------------
/**
 * @brief Calculates waiting times using Round Robin scheduling.
 * @param processes Vector of process IDs.
 * @param n Number of processes.
 * @param bt Vector of burst times.
 * @param wt Vector to store waiting times.
 * @param quantum Time quantum (time slice).
 *
 * @note
 * Waiting time is the total time a process waits in the ready queue
 * before getting CPU time for execution.
 *
 * @timecomplexity O(k * n), where k = average number of cycles until all finish.
 * @spacecomplexity O(n)
 */
void findWaitingTime(vector<int> &processes, int n, vector<int> &bt, vector<ll> &wt, int quantum)
{
    vector<ll> rem_bt(n, 0);

    // Step 1: Copy burst times into a separate array for remaining times
    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }

    // Step 2: Initialize current time
    ll t = 0;

    // Step 3: Keep looping until all processes are done
    while (true)
    {
        bool done = true;

        // Traverse all processes one by one
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false; // Still a process pending

                if (rem_bt[i] > quantum)
                {
                    // Process executes for one full quantum
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    // Process finishes in this cycle
                    t += rem_bt[i];
                    wt[i] = t - bt[i]; // Waiting time = total time - burst
                    rem_bt[i] = 0;
                }
            }
        }

        // If all processes finished, break
        if (done)
            break;
    }
}

// ------------------------------------------------------------
// Function to compute Turnaround Time
// ------------------------------------------------------------
/**
 * @brief Calculates turnaround time for each process.
 * @param bt Burst times.
 * @param wt Waiting times.
 * @param tat Vector to store turnaround times.
 *
 * @note
 * Turnaround Time = Burst Time + Waiting Time
 */
void findTurnAroundTime(vector<int> &bt, vector<ll> &wt, vector<ll> &tat)
{
    int n = bt.size();
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

// ------------------------------------------------------------
// Function to compute Average Waiting and Turnaround Times
// ------------------------------------------------------------
/**
 * @brief Calculates average waiting and turnaround time for all processes.
 * @param processes Vector of process IDs.
 * @param bt Vector of burst times.
 * @param quantum Time quantum.
 * @return A vector {avg_waiting_time, avg_turnaround_time}.
 */
vector<ll> findAverageTime(vector<int> &processes, vector<int> &bt, int quantum)
{
    int n = processes.size();
    vector<ll> wt(n, 0), tat(n, 0);

    // Compute waiting and turnaround times
    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(bt, wt, tat);

    // Compute total and average values
    ll total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    return {total_wt / n, total_tat / n};
}

// ------------------------------------------------------------
// Main Function (Demonstration)
// ------------------------------------------------------------
int main()
{
    int T;
    cin >> T; // Number of test cases

    while (T--)
    {
        int N, quantum;
        cin >> N >> quantum;

        vector<int> processes(N), burst(N);

        for (int i = 0; i < N; i++)
            cin >> processes[i];
        for (int i = 0; i < N; i++)
            cin >> burst[i];

        vector<ll> result = findAverageTime(processes, burst, quantum);

        // Output average waiting and turnaround time
        cout << result[0] << " " << result[1] << "\n";
    }

    return 0;
}

/**
 * @example
 * Input:
 * 2
 * 4 4
 * 1 2 3 4
 * 5 3 8 9
 * 3 1
 * 1 2 3
 * 3 4 3
 *
 * Output:
 * 10 17
 * 5 8
 *
 * @note
 * Average Waiting Time = (11 + 4 + 12 + 16) / 4 = 10
 * Average Turnaround Time = (16 + 7 + 20 + 25) / 4 = 17
 *
 * Average Waiting Time = (4 + 6 + 6) / 3 = 5
 * Average Turnaround Time = (7 + 10 + 9) / 3 = 8
 */
