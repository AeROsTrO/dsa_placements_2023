#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

 vector<Node*>v;
    void findRoot(Node* root, int val){
        if(!root)return;
        if(val==root->val)v.push_back(root);
        findRoot(root->left, val);
        findRoot(root->right, val);
    }
    bool same(Node* root1, Node* root2){
    if(!root1 || !root2)return root1==root2;
    return root1->val==root2->val && same(root1->left, root2->left) && same(root1->right, root2->right);
}
    bool isSub(Node* root, Node* subRoot) {
        
        findRoot(root, subRoot->val);
        for(auto i:v){
            if(same(i, subRoot))return true;
        }
        return false;
    }