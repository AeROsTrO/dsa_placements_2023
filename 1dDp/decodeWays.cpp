#include <bits/stdc++.h>
using namespace std;
// problem description here
//  A message containing letters from A-Z can be encoded into numbers using the following mapping:
//  'A' -> "1"
//  'B' -> "2"
//  .
//  .
//  .
//  'Z' -> "26"
//  To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)
// Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

// Given a string s containing only digits, return the number of ways to decode it.

// The test cases are generated so that the answer fits in a 32-bit integer.
int rec(string &s, int ind)
{
    int n = s.length();
    if (ind == n || ind == n - 1)
        return 1;
    if (s[ind] == '0')
        return 0;
    int takeAsSingleDigitAndMoveOn = rec(s, ind + 1), takeAsDoubleDigitsAndGoToNextIndex = 0;
    if (ind + 1 < n)
    {
        int nextTwo = 10 * (s[ind] - '0') + s[ind + 1] - '0';
        if (nextTwo >= 1 && nextTwo <= 26)
            takeAsDoubleDigitsAndGoToNextIndex = rec(s, ind + 2);
    }
    return takeAsDoubleDigitsAndGoToNextIndex + takeAsSingleDigitAndMoveOn;
}
int mem(string &s, int ind, vector<int> &dp)
{
    int n = s.length();
    if (ind == n || ind == n - 1)
        return 1;
    if (s[ind] == '0')
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    dp[ind] = mem(s, ind + 1, dp);
    int nextTwo = 10 * (s[ind] - '0') + s[ind + 1] - '0';

    if (nextTwo >= 1 && nextTwo <= 26)
        dp[ind] += mem(s, ind + 2, dp);
    return dp[ind];
}
int tab(string &s, int ind)
{
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = (s[1] == '0') ? 0 : 1;
    for (int i = 2; i < n; i++)
    {
        int op1 = s[i - 1] - '0';
        int op2 = 10 * (s[i - 2] - '0') + s[i - 1] - '0';
        if (op1 >= 1)
            dp[i] += dp[i - 1];
        if (op2 >= 10 && op2 <= 26)
            dp[i] += dp[i - 2];
    }
    return dp[n];
}
//O(n) O(n)
int tab2(string &s)
{
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0') // single digit 0
            dp[i] += dp[i + 1];
        if (i + 1 < n && s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')
        {
            dp[i] += dp[i + 2];
        }
    }
    return dp[0];
}
//O(n) O(1)
int bottomUp(string &s)
{
    int n = s.length();
    int dp = 0, dp1 = 1, dp2 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')//single digit
            dp += dp1;
        if (i + 1 < n && s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')//double digits
            dp += dp2;
        dp2 = dp1;
        dp1 = dp;
        dp = 0;
    }
    return dp1;
}
int main()
{
    string s;
    cin >> s;
    vector<int> dp(s.length(), -1);
    cout << mem(s, 0, dp);
    return 0;
}