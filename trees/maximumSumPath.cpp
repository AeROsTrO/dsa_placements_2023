#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;
//problem description here
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.
int getSum(Node* root, int &maxi){
    if(!root)return 0;
    int lsum=max(0, getSum(root->left, maxi)),
        rsum=max(0, getSum(root->right, maxi));
    maxi=max(maxi, lsum+rsum+root->val);
    return root->val+max(lsum, rsum);
}
int maxPath(Node* root)
{
    int m=INT_MIN;
    getSum(root, m);
    return m;
}
int main()
{
 
return 0;
}