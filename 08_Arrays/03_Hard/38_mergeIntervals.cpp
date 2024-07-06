/*You are given N number of intervals, where each interval contains two integers denoting the start time and the end time for the interval.

The task is to merge all the overlapping intervals and return the list of merged intervals sorted by increasing order of their start time.

Two intervals [A,B] and [C,D] are said to be overlapping with each other if there is at least one integer that is covered by both of them.

For example:

For the given 5 intervals - [1, 4], [3, 5], [6, 8], [10, 12], [8, 9].

Since intervals [1, 4] and [3, 5] overlap with each other, we will merge them into a single interval as [1, 5].

Similarly, [6, 8] and [8, 9] overlap, merge them into [6,9].

Interval [10, 12] does not overlap with any interval.

Final List after merging overlapping intervals: [1, 5], [6, 9], [10, 12].*/

#include <bits/stdc++.h>

using namespace std;

// brute force solution
vector<vector<int>> mergeIntervalsBrute(vector<vector<int>> &intervals)
{
    // to store merged intervals
    vector<vector<int>> ans;
    // size of given vector
    int n = intervals.size();
    // sort the vector
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < n; i++)
    {
        // select the interval
        int start = intervals[i][0];
        int end = intervals[i][1];

        // skip all the merged intervals
        // check if end is lesser or equal to
        // the last entered interval's end value
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        // check the rest of the intervals
        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
    // S:O(N)
    // T:O(NlogN) + O(2N)
    // here, 2N is cause of 2 for loop
    // it should have been O(N^2), but here each element
    // is traversed twice. so it is O(N^2)
}
// optimal solution
vector<vector<int>> mergeIntervalsOptimal(vector<vector<int>> &intervals)
{
    // to store merged intervals
    vector<vector<int>> ans;
    // size of given vector
    int n = intervals.size();
    // sort the vector
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < n; i++)
    {
        // if the current interval
        // does not lie in the last interval
        if (ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        // if the current interval lies in
        // the last interval
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
    // T:O(NlogN)+O(N)
    // S:O(N)
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    // vector<vector<int>> ans = mergeIntervalsBrute(arr);
    vector<vector<int>> ans = mergeIntervalsOptimal(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}