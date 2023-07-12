#include <bits/stdc++.h>
using namespace std;
// problem description here
//  Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 static bool cmp(pair<int, int>p1, pair<int, int>p2){
return p1.first>p2.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty())return {};
        if(nums.size()==1 && k==1)return nums;
  map<int, int>m;
        for(int x:nums)m[x]++;
        vector<pair<int, int>>v;
        for(auto p:m)v.push_back({p.second, p.first});
        m.clear();
        sort(v.begin(), v.end(), cmp);
        vector<int>res;
       for(int i=0; i<k; i++){
           res.push_back(v[i].second);
       }       
        v.clear();
    }
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    for (int i : nums)
        m[i]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (auto p : m)
    {
        q.push({p.second, p.first});
        if (q.size() > k)
            q.pop();
    }
    vector<int> res;
    while (q.size())
    {
        res.push_back(q.top().second);
        q.pop();
    }
    return res;
}
int main()
{

    return 0;
}