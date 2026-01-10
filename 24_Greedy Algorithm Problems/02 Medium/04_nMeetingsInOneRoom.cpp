/************************************************************
 *  File: 04_nMeetingsInOneRoom.cpp
 *
 *  Problem Statement:
 *  -------------------
 *  You are given timings of 'n' meetings in the form of
 *  (start[i], end[i]) where start[i] is the start time of
 *  meeting i and end[i] is the finish time of meeting i.
 *
 *  You must find the maximum number of meetings that can be
 *  accommodated in a single meeting room. Only one meeting
 *  can take place at a time.
 *
 *  NOTE:
 *  - The start time of a meeting CANNOT be equal to the
 *    end time of the previous meeting.
 *
 *  Example:
 *  Input:  start = [1, 3, 0, 5, 8, 5]
 *          end   = [2, 4, 6, 7, 9, 9]
 *  Output: 4
 *  Explanation: Meetings selected → (1,2), (3,4), (5,7), (8,9)
 *
 *  Constraints:
 *  1 ≤ n ≤ 100000
 *  0 ≤ start[i] < end[i] ≤ 1000000
 ************************************************************/

#include <iostream>  // for input/output in main()
#include <vector>    // for using std::vector
#include <algorithm> // for sort()

using namespace std;

/**
 * @brief Comparator function used to sort meetings by their end time.
 *
 * We sort meetings primarily based on ending time in ascending order.
 * This is the greedy strategy for selecting maximum non-overlapping meetings.
 *
 * @param a First meeting pair (start, end).
 * @param b Second meeting pair (start, end).
 * @return true if meeting 'a' ends before meeting 'b'.
 */
static bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

/**
 * @brief Function to calculate maximum number of meetings that can be held.
 *
 * This function implements the greedy algorithm for interval scheduling:
 * 1. Build a vector of meeting pairs (start, end).
 * 2. Sort meetings by their end time.
 * 3. Choose the earliest finishing meeting first.
 * 4. For each next meeting, pick it only if:
 *        start_time > last_meeting_end_time
 *    (Strictly greater because equal is not allowed.)
 *
 * @param start Vector containing start times of meetings.
 * @param end   Vector containing end times of meetings.
 * @return int  Maximum number of meetings that can be held.
 */
int maxMeetings(vector<int> &start, vector<int> &end)
{

    // Step 1: Create a list of meetings as (start, end) pairs
    vector<pair<int, int>> meetings;
    int numberOfMeetings = start.size();

    for (int index = 0; index < numberOfMeetings; index++)
    {
        meetings.push_back({start[index], end[index]});
    }

    // Step 2: Sort all meetings based on their ending time
    // Greedy rule: pick the meeting that ends earliest
    sort(meetings.begin(), meetings.end(), comp);

    // 'totalMeetings' counts how many meetings we can accommodate
    int totalMeetings = 0;

    // 'lastEndingTime' tracks the ending time of the last chosen meeting
    // Set to -1 so the very first meeting always gets considered
    int lastEndingTime = -1;

    // Step 3: Loop through all sorted meetings and choose valid ones
    for (int index = 0; index < numberOfMeetings; index++)
    {

        int currentStart = meetings[index].first;
        int currentEnd = meetings[index].second;

        // To take a meeting:
        // Start time MUST BE strictly greater than last selected meeting's end time
        if (currentStart > lastEndingTime)
        {

            // This meeting can be conducted successfully
            totalMeetings++;

            // Update the tracker to this meeting's ending time
            lastEndingTime = currentEnd;
        }
    }

    // Return the total number of meetings that can be held
    return totalMeetings;
}

/************************************************************
 *                         MAIN FUNCTION
 *  Demonstrates example usage of maxMeetings() function with
 *  sample inputs and expected outputs.
 ************************************************************/
int main()
{

    vector<int> start1 = {1, 3, 0, 5, 8, 5};
    vector<int> end1 = {2, 4, 6, 7, 9, 9};

    cout << "Test Case 1 → Expected: 4, Output: "
         << maxMeetings(start1, end1) << endl; // Expected: 4

    vector<int> start2 = {10, 12, 20};
    vector<int> end2 = {20, 25, 30};

    cout << "Test Case 2 → Expected: 1, Output: "
         << maxMeetings(start2, end2) << endl; // Expected: 1

    vector<int> start3 = {1, 2};
    vector<int> end3 = {100, 99};

    cout << "Test Case 3 → Expected: 1, Output: "
         << maxMeetings(start3, end3) << endl; // Expected: 1

    return 0;
}
