#include <bits/stdc++.h>
using namespace std;
//problem description here
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.

// greedy solution
bool solve(vector<int>&nums){
    int n=nums.size();
    int reachable=0;
    for(int i=0; i<n; i++){
     if(i>reachable)return false;
        reachable=max(i+nums[i], reachable);   
    }
    return true;
}
//dp solutions
bool recursive(vector<int>&v, int currIndex){
    //O(n^n) O(stack space)
    if(currIndex>=v.size())return true;
    for(int step=1; step<=v[currIndex]; step++){
        if(recursive(v, currIndex+step))return true;
    }
    return false;
}
bool opt(vector<int>&v, int currIndex, vector<int>&dp){
    if(currIndex>=v.size())return true;
    if(dp[currIndex]!=-1)return dp[currIndex];
    for(int step=1; step<=v[currIndex]; step++){
        if(opt(v, currIndex+step, dp))dp[currIndex] = true;
    }
    return dp[currIndex]=false;
}
bool solveOpt(vector<int>&v){
    //O(n^2) O(n)+stack space
    int n=v.size();
    vector<int>dp(n, -1);
    return opt(v, 0, dp);
}
bool dp(vector<int>&v){
    //O(n^2) O(n)
    int n=v.size();
    vector<bool>dp(n, 0);
    dp[0]=true;
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(dp[j]&& j+v[j]>=i){
                dp[i]=true;
                break;
            }
        }
    }
    return dp[n-1];
}
int main()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<recursive(v, 0);
    return 0;
}