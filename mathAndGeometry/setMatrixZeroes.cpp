#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.
// 1 1 1
// 1 0 1
// 1 1 1

// 1 0 1
// 0 0 0
// 1 0 1

//out-of-place
void sol1(vector<vector<int>>&v, int row, int col){
        //set row and cols to 0
        int rows=v.size(), cols=v[0].size();
        for(int j=0; j<cols; j++)v[row][j]=0;
        for(int i=0; i<rows; i++)v[i][col]=0;
}
void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>>what;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]==0)what.push_back({j, i});
            }
        }
        for(int i=0; i<what.size(); i++){
            sol1(matrix, what[i].first, what[i].second);
        }
}
//in-place
void sol2(vector<vector<int>>&v){
    int rows=v.size(), cols=v[0].size();
    bool fr=false, fc=false;

    for(int i=0; i<cols; i++){
        if(v[0][i]==0)fr=true;
    }
    for(int i=0;i<rows; i++)if(v[i][0]==0)fc=true;
    for(int i=1; i<rows; i++){
        for(int j=1; j<cols; j++)if(v[i][j]==0){
            v[i][0]=0;
            v[0][j]=0;
        }
    }
    for(int i=1; i<rows; i++){
        for(int j=1; j<cols; j++){
            if(v[i][0]==0 || v[0][j]==0)v[i][j]=0;
        }
    }
    if(fr){
        for(int i=0; i<cols; i++)v[0][i]=0;
    }
    if(fc){
        for(int i=0; i<rows; i++)v[i][0]=0;
    }
    for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++)cout<<v[i][j]<<' ';
    cout<<endl;
    }
    
}
int main()
{
    int m, n;cin>>m>>n;
    vector<vector<int>>v(m, vector<int>(n));
    for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
        cin>>v[i][j];
    sol2(v);
    return 0;
}