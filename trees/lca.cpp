#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;
//problem description here
// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
//iterative
Node* lca(Node* root, Node* p, Node* q){
    if(!root)return NULL;
    while(root){
        if(root->val>p->val && root->val>q->val)root=root->left;
        else if(root->val<p->val && root->val<q->val)root=root->right;
        else break;
    }
    return root;
}
//recursive
Node* lca(Node* root, Node* p, Node* q){
    if(!root)return root;
    if(root->val>p->val && root->val>q->val)return lca(root->left, p, q);
    if(root->val<p->val && root->val<q->val)return lca(root->right, p, q);
    return root;//will reach here if one of the values of p, q is root->val || when root is lca
}
int main()
{
    
    return 0;
}