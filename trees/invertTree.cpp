
#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given the root of a binary tree, invert the tree, and return its root.
class Node{
    public:
    int val;
    Node* left, *right;
    Node(int value){
        val=value;
        left=NULL;
        right=NULL;
    }
};
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
void preorder(Node* root){
    if(!root)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

void rec(Node* &root){
    if(!root)return;
    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;
    rec(root->left);
    rec(root->right);
}
Node* invertTree(Node*root){
    rec(root);
    return root;
}
int main()
{
    int n;cin>>n;
    Node* root=NULL;
    for(int i=0; i<n; i++){
        int x;cin>>x;
        insert(root, x);
    }
    root=invertTree(root);
    inorder(root);

    return 0;
}