#include <bits/stdc++.h>
using namespace std;
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

bool tsort(vector<vector<int>> &graph, int source, vector<bool> &visM)
{
    int n = graph.size();
    vector<int> ans, indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int nei : graph[i])
            indeg[nei]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        visM[node] = true;
        for (int nei : graph[node])
            if (--indeg[nei] == 0)
                q.push(nei);
    }
    return ans.size() == n;
}
bool canFinish(int numCourses, vector<vector<int>> &pre)
{
    if (pre.empty())
        return true;
    vector<vector<int>> graph(numCourses);
    for (int i = 0; i < pre.size(); i++)
    {
        graph[pre[i][1]].push_back(pre[i][0]);
    }
    int n = graph.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (!tsort(graph, i, vis))
                return false;
        }
    }
    for (int i = 0; i < n; i++)
        if (!vis[i])
            return false;
    return true;
}
