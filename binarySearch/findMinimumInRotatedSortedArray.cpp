#include <bits/stdc++.h>
using namespace std;
//problem description here
// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// You must write an algorithm that runs in O(log n) time.

//O(nlogn)
int brute(vector<int>&v){
    int n=v.size();
    sort(v.begin(), v.end());
    return v[0];
}
//O(n)
int moreBrute(vector<int>&v){
    int minEle=INT_MAX;
    int n=v.size();
    for(int i=0; i<n; i++)minEle=min(minEle,v[i]);
    return minEle;
}
//O(logn)
int sol(vector<int>&v){
    int n=v.size();
    int l=0, r=n-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(v[l]<v[r])return v[l];
        if(v[mid]>=v[r])l=mid+1;
        else r=mid;
    }
    return v[l];
    //l is the pivot
}

int main()
{
 set<int>s;
 s.insert({1,2, 3, 4});
 auto it=s.begin(), last=s.find(3);
 int num=distance(it, last);
 cout<<num;
return 0;
}