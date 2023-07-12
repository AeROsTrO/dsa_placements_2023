#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an integer array nums, find the subarray
//  with the largest sum, and return its sum.

//brute
int brute(vector<int>&v){
    int n=v.size();
    int ans=INT_MIN;
    for(int i=0; i<n; i++){
        int sum=max(0, v[i]);
        for(int j=i+1; j<n; j++){
            ans=max(sum+=v[j], ans);
        }
    }
    return ans;
}
//opt
int sol(vector<int>&nums){
    int n=nums.size();
    int currSum=0, maxSum=INT_MIN;
    for(int i=0; i<n; i++){
        currSum=max(currSum+nums[i], nums[i]);
        maxSum=max(maxSum, currSum);
    }
    return maxSum;
}
int main()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<sol(v);
    return 0;
}