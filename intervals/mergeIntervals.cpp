#include <bits/stdc++.h>
using namespace std;
// problem description here
//  Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
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
