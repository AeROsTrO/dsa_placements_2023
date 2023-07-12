#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
//O(n^2) O(1)
pair<int, int> brute(vector<int>&nums, int k){
    for(int i = 0; i < nums.size(); i++){
        for(int j=i+1;j < nums.size(); j++){
            if(nums[i]+nums[j]==k)return {i,j};
        }
    }
    return {-1, -1};
}

//O(nlogn) O(n)
static bool cmp(pair<int, int>&p1,pair<int, int>&p2){
        return p1.first==p2.first?p1.second<p2.second:p1.first<p2.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>>v;
        for(int i=0; i<nums.size(); i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end(), cmp);
        int n=nums.size();
        int l=0, r=n-1;
        while(l<r){
            if(v[l].first+v[r].first==target)return{v[l].second, v[r].second};
            else if(v[l].first+v[r].first<target)l++;
            else r--;
        }
        return {-1, -1};
}
//two pointer
//O(nlogn) O(n)
vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int a[n];
        //3 2 4
    //sorted arr 2 3 4 //l=0,r=2 check value at l and r and match with the copy of given array element 
     for(int i=0;i<nums.size();i++){
         a[i]=nums[i];
     }
        vector<int>v;
        sort(nums.begin(),nums.end());
               int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]==target){
              
             break;
            }
            else if(nums[l]+nums[r]>target){
                r--;
            }
            else{
                l++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[l]==a[i]){
                v.push_back(i);
            }
            else if(nums[r]==a[i]){
                v.push_back(i);
            }
        }
        
        return v;
}
 
//O(n) O(n)
vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> visited;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int n = nums[i];
            int complement = target - n;
            if (visited.count(complement)) {
                return {visited[complement], i};
            }
            visited[n] = i;  // assume that each input would have exactly one solution
        }
        return {};
    }
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> m;
       for(int i = 0; i < nums.size(); i++){
           if(m.find(target - nums[i]) == m.end()){
               m[nums[i]] = i;
           }
           else{
               return{m[target - nums[i]] , i};
           }
       }
       return {-1 , -1};
    }
int main()
{
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    return 0;
}