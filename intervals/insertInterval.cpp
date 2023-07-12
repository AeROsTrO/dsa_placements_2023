// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.
#include <bits/stdc++.h>
using namespace std;
// problem description here
static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    intervals.push_back(newInterval);
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(), cmp);
    for (auto i : intervals)
    {
        if (ans.empty())
            ans.push_back(i);
        else
        {
            if (ans.back().back() >= i[0])
                ans.back().back() = max(i[1], ans.back().back());
            else
                ans.push_back(i);
        }
    }
    return ans;
}