#include <bits/stdc++.h>
using namespace std;
// problem description here
//  You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// O(2^n) O(n{stack space})
long long rec(int i, int n)
{
    if (i > n)
        return 0;
    if (i == n)
        return 1;
    return rec(i + 1, n) + rec(i + 2, n);
}
long recc(int n)
{
    if (n < 2)
        return 1;
    return recc(n - 1) + recc(n - 2);
}
// O(less than 2^n but more than n^n) O(stack space+array space)
long long mem(int n, vector<int> &dp)
{
    if (n < 2)
        return 1; // number of ways is 1 for both 0 and 1 steps
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = mem(n - 1, dp) + mem(n - 2, dp);
}
// O(n) O(n)
long long dpp(int n, vector<int> dp)
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// O(n) O(1)
int climbStairs(int n)
{
    if (n <= 2)
        return n;
    int first = 1, second = 2;
    int ans = first + second;
    for (int i = 3; i <= n; i++)
    {
        int spare = second;
        second += first;
        first = spare;
    }
    return second;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout<<dpp(n, dp);
    // cout<<mem(n, dp);
    // cout<<recc(n);

    return 0;
}