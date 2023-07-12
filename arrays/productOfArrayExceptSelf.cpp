#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

  vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n, 1), suf(n, 1);
        for(int i=1; i<n; i++)
        {
            pre[i]=pre[i-1]*nums[i-1];
        }
        for(int i=n-2; i>=0; i--)suf[i]=suf[i+1]*nums[i+1];
        for(int i=0;i<n;i++)
        {
            nums[i]=suf[i]*pre[i];
        }
        return nums;
    }
     vector<int> productExceptSelff(vector<int>& nums){
        int n=nums.size();
        vector<int>ans(n);
        ans[0]=1;
        for(int i=1; i<n; i++){
            ans[i]=nums[i-1]*ans[i-1];
        }
        int right=1;
        for(int i=n-1; i>=0; i--){
            ans[i]*=right;
            right*=nums[i];
        }
        for(int i:ans)cout<<i<<" ";
        return ans;
     }
int main()
{
 int n; cin>>n;
 vector<int>v(n);
 for(int i=0; i<n; i++)cin>>v[i];
 productExceptSelff(v);
    return 0;
}