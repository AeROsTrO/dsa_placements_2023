#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;
//problem description here
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


bool sameTree(Node* root1, Node* root2){
    if(!root1 || !root2)return root1==root2;
    return root1->val==root2->val && sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right);
}
int main()
{

   return 0;
}