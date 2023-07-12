#include <bits/stdc++.h>
using namespace std;
//problem description here
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.
int brute(vector<int>&nums, int ind, int amount){
    if(amount==0)return 0;
    if(ind==nums.size())return 1e8;
    int take=1e8, dontTake=brute(nums, ind+1, amount);
    if(amount>=nums[ind])take=1+brute(nums, ind, amount-nums[ind]);
    return min(take, dontTake);
}

int main()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    int k;cin>>k;
    cout<<brute(v, 0, k);
    return 0;
}