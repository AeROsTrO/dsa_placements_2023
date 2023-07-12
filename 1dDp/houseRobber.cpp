#include <bits/stdc++.h>
using namespace std;
//problem description here
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

int rec(vector<int>&v, int ind){
    if(ind>=v.size())return 0;
    return max(v[ind]+rec(v, ind+2), rec(v, ind+1));
}
int mem(vector<int>&v, int ind, vector<int>&dp){
    if(ind>=v.size())return 0;
    if(dp[ind]!=-1)return dp[ind];
    return dp[ind]=max(v[ind]+mem(v, ind+2, dp), mem(v, ind+1, dp));
}
int dpp(vector<int>&v){
        int n=v.size();
    vector<int>dp(n+1);
    dp[0]=v[0];
    if(n==1)return dp[0];
    dp[1]=max(v[1], v[0]);
    if(n==2)return dp[1];
    dp[2]=max(dp[1], v[0]+v[2]);
    if(n==3)return dp[2];
    for(int i=3; i<n; i++){
        dp[i]=max(dp[i-1], v[i]+dp[i-2]);
    }
    return max(dp[n-1], dp[n-2]);
}
int optDp(vector<int>&v){
    int n=v.size();
    int maxIncludingLastHouse=v[0];
    int maxExcludingLastHouse=0;
    for(int i=1; i<n; i++){
        int moneyInCurrentHouse=v[i];
        int lootIncludingCurrentHouse=moneyInCurrentHouse+maxExcludingLastHouse;
        int lootExcludingCurrentHouse=max(maxExcludingLastHouse, maxIncludingLastHouse);
        maxIncludingLastHouse=lootIncludingCurrentHouse;
        maxExcludingLastHouse=lootExcludingCurrentHouse;
    }
    return max(maxIncludingLastHouse, maxExcludingLastHouse);
}
int main()
{
    int n; cin>>n;
    vector<int>v(n), dp(n, -1);
    for(int i=0; i<n; i++)cin>>v[i];
    // cout<<rec(v, 0);
    cout<<optDp(v);
    return 0;
}