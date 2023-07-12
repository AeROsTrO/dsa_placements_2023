#include <bits/stdc++.h>
using namespace std;
//problem description here
//  Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 
 void dfs(int x, int y, vector<vector<char>>&grid, vector<vector<bool>>&vis){
        stack<pair<int,int>>s;
        s.push({x, y});
        int m=grid.size(), n=grid[0].size();
        // vis[x][y]=true;
        while(!s.empty()){
           int tx=s.top().first, ty=s.top().second;
            s.pop();
            vis[tx][ty]=true;
            if(tx+1<m && !vis[tx+1][ty]){
                if(grid[tx+1][ty]=='1')s.push({tx+1, ty});
            }
            if(ty+1<n && !vis[tx][ty+1]){
                 if(grid[tx][ty+1]=='1')s.push({tx, ty+1});
            }
            if(ty-1>=0 && !vis[tx][ty-1]){
                 if(grid[tx][ty-1]=='1')s.push({tx, ty-1});
            }
            if(tx-1>=0 && !vis[tx-1][ty]){
                 if(grid[tx-1][ty]=='1')s.push({tx-1, ty});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        int c=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] || grid[i][j]=='0'){
                    continue;
                }
                else {dfs(i, j, grid, vis);++c;}
            }
        }
        return c;
}