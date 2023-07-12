#include <bits/stdc++.h>
using namespace std;
// problem description here
//  ou are given an array prices where prices[i] is the price of a given stock on the ith day.
//  You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//  Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// O(n^2) O(1)
int maxProfit(vector<int> &prices)
{
    if (prices.size() == 1)
    {
        return 0;
    }

    int mp = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i; j < prices.size(); j++)
        {
            mp = max(mp, prices[j] - prices[i]);
        }
    }

    return mp;
}

// sliding window
// O(n) O(1)
int maxProfit(vector<int> &v)
{
    int n = v.size();
    int mp = INT_MIN;
    int l = 0, r = 1;
    while (r < n)
    {
        if (v[r] < v[l])
        {
            l = r;
            r++;
        }
        else
        {
            mp = max(mp, v[r] - v[l]);
            r++;
        }
    }
    return mp;
}

// O(n) O(n)
int maxProfit(vector<int> &v)
{
    int n = v.size();
    vector<int> arr(n + 1, 0);
    arr[0] = INT_MAX;
    int profit = 0;
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = min(arr[i - 1], v[i - 1]);
        profit = max(profit, v[i - 1] - arr[i]);
    }
    return profit;
}
// O(n) O(1)
int maxProfit(vector<int> &v)
{
    int n = v.size();
    int minPrice = v[0], maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        minPrice = min(minPrice, v[i]);
        maxProfit = max(maxProfit, v[i] - minPrice);
    }
    return maxProfit;
}

// O(n) O(1)
int kindaBest(vector<int> &v)
{

    int n = v.size();
    int buy = INT_MAX;
    int profit = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (buy > v[i])
        {
            buy = v[i];
        }
        else
            profit = max(profit, v[i] - buy);
    }
    // if else is the reason this solution is slightlty faster than the previous solution coz less number of statements are executed
    return profit == INT_MIN ? 0 : profit;
}
