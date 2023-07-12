#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;
//problem description here
// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
int inorder(Node* root, int &k){
  if(!root)return INT_MAX;
    int left=inorder(root->left, k);
    k--;
    if(k==0)return root->val;
    int right=inorder(root->right, k);
    return min(right, left);
    
}
 priority_queue<int>q;
 int ele=-1;
void usingq(Node* root, int k){
    if(!root)return;
    usingq(root->left, k);
    q.push(root->val);
    if(q.size()>k)q.pop();
    usingq(root->right, k);
}
//after this👆 in main function, return top of queue
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
int main()
{
    Node* root=NULL;
    int n;cin>>n;
    for(int i=0; i<n; i++){
    int x;cin>>x;
    insert(root, x);
    }
    int k;cin>>k;
    cout<<inorder(root, k);
    return 0;
}