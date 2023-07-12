#include <bits/stdc++.h>
using namespace std;
// problem description here
// find the number of connected components in an undirected graph
void dfs(vector<int> adj[], int source, vector<bool> &vis)
{
    stack<int> s;
    s.push(source);
    vis[source] = true;
    while (s.size())
    {
        int node = s.top();
        s.pop();
        vis[node] = true;
        for (int nei : adj[node])
        {
            if (!vis[nei])
                vis[nei] = true, s.push(nei);
        }
    }
}
int numConnectedComponents(vector<int> adj[], int n)
{
    vector<bool> vis(n, false);
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(adj, i, vis), ct++;
    }
    return ct;
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<numConnectedComponents(adj, v);
    return 0;
}