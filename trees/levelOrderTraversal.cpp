#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;
//problem description here
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
vector<vector<int>>levels;
void bfs(Node* root){
    if(!root)return;
    queue<Node*>q;
    while(q.size()){
        int n=q.size();
        vector<int>level;
        for(int i=0;i<n; i++){
            root=q.front();
            level.push_back(root->val);
            q.pop();
            if(root->left)q.push(root->left);
            if(root->right)q.push(root->right);
        }
        levels.push_back(level);
    }
}
int main()
{
   
    return 0;
}