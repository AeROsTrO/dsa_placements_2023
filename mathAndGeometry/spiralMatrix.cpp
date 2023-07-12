#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an m x n matrix, return all elements of the matrix in spiral order.

void sol1(vector<vector<int>>v){
    int rows=v.size(), cols=v[0].size();
    int k=rows*cols;
    int ct=0;
    int minr=0, minc=0, maxr=rows-1, maxc=cols-1;
    vector<int>ans;
    while(ct<k){
        for(int i=minc; i<=maxc; i++)ans.push_back(v[minr][i]),ct++;
        minr++;
        for(int i=minr; i<=maxr; i++)ans.push_back(v[i][maxc]),ct++;
        maxc--;
        for(int i=maxc; i>=minc; i--)ans.push_back(v[maxr][i]),ct++;
        maxr--;
        for(int i=maxr; i>=minr; i--)ans.push_back(v[i][minc]),ct++;
        minc++;
    }
    for(int i:ans)cout<<i<<' ';
}
int main()
{
    int m, n;cin>>m>>n;
    vector<vector<int>>v(m, vector<int>(n));
    for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)cin>>v[i][j];
    sol1(v);
    return 0;
}