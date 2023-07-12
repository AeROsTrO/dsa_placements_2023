#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;
// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
void insert(Node*&root, int val){
    if(!root){
        root=new Node(val);
        return;
    }
    if(root->val>val){
        insert(root->left, val);
    }
    else insert(root->right, val);
}
void inorder(Node* root){
    if(!root)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int height(Node* root){
    if(!root)return 0;
    int leftHeight=height(root->left),
        rightHeight=height(root->right);
    return 1+max(leftHeight,rightHeight);
    // return !root?0:1+max(height(root->left),height(root->right));
}

int main(){
    Node* root=NULL;
    int n;cin>>n;
    for(int i=0; i<n; i++){
        int x;cin>>x;
        insert(root, x);
    }
    cout<<height(root);
    return 0;
}