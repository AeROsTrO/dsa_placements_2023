#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.
int brute(vector<int>&nums){
    sort(nums.begin(), nums.end());
    int n=nums.size();
    int ans=1;
    int ct=1;
    for(int i=0; i+1<n;i++){
        if(nums[i]+1==nums[i+1])ct++;
        ans=max(ans,ct);
    }
    return max(ct, ans);
}
int better(vector<int>&nums){
    int n=nums.size();
    set<int>s;
    for(int i=0; i<n; i++)s.insert(nums[i]);
    int ans=1;
    for(int i:nums){
        int curr=i;
        int currCt=1;
        
        if(s.find(i-1)==s.end()){
            while(s.find(curr+1)!=s.end()){
            curr+=1;
            currCt+=1;
            }
        }
        ans=max(currCt, ans);
    }
    return ans;
}
int main()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<better(v);
    return 0;
}