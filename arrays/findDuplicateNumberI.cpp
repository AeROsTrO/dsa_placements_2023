#include <bits/stdc++.h>
using namespace std;
//problem description here
// iven an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.(in-place)
int brutee(vector<int>&v){
int n=v.size();
for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++)if(v[j]==v[i])return v[j];
}
return -1;
}
int etTuBrute(vector<int>&v){
    int x=-1;
    sort(v.begin(), v.end());
    int n=v.size();
    for(int i=0; i<n; i++)if(v[i]==v[i+1])x=v[i];
    return x;
    //O(nlogn) O(1)
}
int better(vector<int>&v){
    unordered_map<int, int>m;
    for(int i:v)m[i]++;
    for(auto p:m)if(p.second>1)return p.first;
    return -1;
    //O(n) o(n)
}
int optimal(vector<int>&v){
   int n=v.size();
   int i=0;
   while(i<n){
    if(v[i]==-1)return i;
    int next=v[i];
    v[i]=-1;
    i=next;
   }
   return -1;
    //O(n) O(1)
}
int opt(vector<int>&v){
    //floyd's algo
    int slow=v[0];
    int fast=v[0];
    while(1){
        slow=v[slow];
        fast=v[v[fast]];
        if(slow==fast)break;
    }
   // cout<<slow<<" "<<fast<<endl;
    int ptr1=v[0];
    int ptr2=slow;
    while(ptr1!=ptr2){
        ptr1=v[ptr1];
        ptr2=v[ptr2];
    }
    return ptr1;
}
int main()
{
    // int n;cin>>n;
    // vector<int>v(n);
    // for(int i=0; i<n; i++)cin>>v[i];
    // cout<<opt(v);
    // int nums[3]={2, 4, 3};
    // cout<<(nums[0]<<nums[1]<<nums[2])<<endl;

    return 0;
}