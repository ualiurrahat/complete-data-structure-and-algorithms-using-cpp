/**
 * @file 01_fcfsScheduling.cpp
 * @brief Implementation of FCFS CPU Scheduling Algorithm.
 *
 * Problem Statement:
 * You are given 'N' processes with their burst times.
 * All processes arrive at time 0.
 * You must compute the waiting time and turn-around time using the FCFS scheduling algorithm.
 *
 * @details
 * - The process that comes first (lowest ID) executes first.
 * - The next process starts only after the previous process finishes.
 *
 * Constraints:
 * 1 <= N <= 10^6
 * 1 <= BURST[i] <= 1000
 *
 * @author
 * MD. Ualiur Rahman Rahat
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Computes the waiting time and turn-around time for FCFS scheduling.
 *
 * @param n Number of processes
 * @param burstTime Vector of burst times of all processes
 * @return vector<vector<int>> 2D vector: [waitingTimes, turnAroundTimes]
 *
 * @note
 * Time Complexity: O(2n) → (O(n) for waiting + O(n) for TAT)
 * Space Complexity: O(2n) → (O(n) for waiting + O(n) for TAT)
 */
vector<vector<int>> findScheduling(int n, vector<int> &burstTime)
{
    vector<int> waitingTime(n, 0);
    vector<int> turnAroundTime(n, 0);

    // ---------------------- Compute Waiting Times ----------------------
    waitingTime[0] = 0; // First process starts at time 0
    for (int i = 1; i < n; i++)
    {
        // Waiting time = waiting time of previous + burst time of previous
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    // ---------------------- Compute Turn-Around Times ----------------------
    for (int i = 0; i < n; i++)
    {
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
    }

    return {waitingTime, turnAroundTime};
}

// ---------------------- Main Function (Test Example) ----------------------
int main()
{
    int t;
    cin >> t; // number of test cases

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> burstTime(n);
        for (int i = 0; i < n; i++)
        {
            cin >> burstTime[i];
        }

        vector<vector<int>> result = findScheduling(n, burstTime);

        // Print waiting times
        for (int time : result[0])
            cout << time << " ";
        cout << endl;

        // Print turn-around times
        for (int time : result[1])
            cout << time << " ";
        cout << endl;
    }

    return 0;
}

/*
---------------------- Example Input ----------------------
1
5
4 6 7 2 1

---------------------- Example Output ----------------------
0 4 10 17 19
4 10 17 19 20

---------------------- Explanation ----------------------
P1 starts at 0 and ends at 4 → WT=0, TAT=4
P2 starts at 4 and ends at 10 → WT=4, TAT=10
P3 starts at 10 and ends at 17 → WT=10, TAT=17
P4 starts at 17 and ends at 19 → WT=17, TAT=19
P5 starts at 19 and ends at 20 → WT=19, TAT=20
*/
