#include <bits/stdc++.h>
using namespace std;
//problem description here
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


//optimal
    int idk(vector<int>&v){
        int n=v.size();
        vector<int>dp(n);
        dp[0]=v[0];
        dp[1]=max(v[1], v[0]);
        dp[2]=max(v[2]+v[0], v[1]);
        for(int i=3; i<n; i++){
            dp[i]=max(dp[i-1], dp[i-2]+v[i]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& v) {
         int n = v.size();
    vector<int> dp(n);
    if (n == 1)
        return v[0];
    if (n == 2)
        return max(v[0], v[1]);
    if (n == 3)
    {
        return max(v[1], max(v[2], v[0]));
    }
   vector<int>t1, t2;
        for(int i=0; i<n; i++){
            if(i!=0)t1.push_back(v[i]);
            if(i!=n-1)t2.push_back(v[i]);
        }

    return max(idk(t1), idk(t2));
    }
int main()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    return 0;
}