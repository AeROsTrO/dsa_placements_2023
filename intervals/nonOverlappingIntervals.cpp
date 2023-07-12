#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
bool cmp(vector<int>&a, vector<int>&b){
    return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
}
void solution(vector<vector<int>>&v){
    int rows=v.size(), cols=v[0].size();
    sort(v.begin(), v.end(), cmp);
    vector<vector<int>>mer;
    for(auto i:v){
        if(mer.empty())mer.push_back(i);
        else{
            if(mer.back().back()>i[0])mer.back().back()=min(mer.back().back(),i[1]);
            else mer.push_back(i);
        }
    }
    cout<<v.size()-mer.size();
}
int main()
{
    int m, n;cin>>m>>n;
    vector<vector<int>>v(m, vector<int>(n));
    for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)cin>>v[i][j];
    solution(v);
    return 0;
}