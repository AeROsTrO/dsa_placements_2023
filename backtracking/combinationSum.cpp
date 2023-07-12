#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency
//  of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
set<vector<int>>ans;
// O(2^n)
void rec(vector<int>&v, int ind, int currSum, int target, vector<int>&curr){
    
    if(ind>=v.size())return;
    if(currSum==target){
        ans.insert(curr);
        return;
    }
    if(currSum>target)return;
    curr.push_back(v[ind]);
    rec(v, ind, currSum+v[ind], target, curr);//take
    curr.pop_back();
    rec(v, ind+1, currSum, target, curr);//not take
}
int main()
{
    int n; cin>>n;
    vector<int>v(n), curr;
    for(int i=0; i<n; i++)cin>>v[i];
    int target;cin>>target;
    sort(v.begin(), v.end());
    rec(v, 0, 0, target, curr);
    for(auto i:ans){
        for(int j:i)cout<<j<<" ";
        cout<<endl;
    }
    
    return 0;
}