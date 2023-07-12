#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
int sol2(vector<int>&nums){
    //O(nlogn) O(n)
    int n=nums.size();
    set<int>s;
    for(int i:nums)s.insert(i);
    for(int i=0; i<=n; i++)if(s.find(i)==s.end())return i;
    return -1;
}
int sol1(vector<int>&nums){
    //O(n) O(n)
    int n=nums.size();
    vector<bool>check(n+1,0);
    for(int i:nums){
        check[i]=true;
    }
    for(int i=0; i<=n; i++)if(check[i]==false)return i;
    return -1;
}
int sol3(vector<int>&nums){
    int n=nums.size();
    //c=xor of all numbers
    //b=xor of numbers in the array
    //a=c^b->number that is missing
    int xorArray=0;
    for(int i:nums)xorArray^=i;
    int xorNums=0;
    for(int i=0; i<=n; i++)xorNums^=i;
    return xorNums^xorArray;
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<sol1(v)<<" "<<sol2(v)<<" "<<sol3(v);
    return 0;
}