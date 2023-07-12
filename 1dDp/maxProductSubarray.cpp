#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an integer array nums, find a 
// subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.
int brute(vector<int>&nums){
    int mp=INT_MIN;
        if(nums.size()==1)return nums[0];
        for(int i=0; i<nums.size(); i++)
        {
            int p=1;
            for(int j=i; j<nums.size(); j++)
            {
            p*=nums[j];
                mp=max(p, mp);
            }
        }
       return mp;
}
  
int better(vector<int>&nums){
    int n=nums.size();
    int pro=1;
    int maxpr=1;
   for(int i:nums){
    pro*=i;
    maxpr=max(pro, maxpr);
    if(pro==0)pro=1;
   }
   pro=1;
   for(int i=n-1; i>=0; i--){
    pro*=nums[i];
    maxpr=max(pro, maxpr);
    if(pro==0)pro=1;
   }
   return maxpr;
}
int better(vector<int>&nums){
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}
int main()
{
    
    return 0;
}