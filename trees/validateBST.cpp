#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;
// problem description here
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//  A valid BST is defined as follows:
//  The left subtree of a node contains only nodes with keys less than the node's key.
//  The right subtree of a node contains only nodes with keys greater than the node's key.
//  Both the left and right subtrees must also be binary search trees.

bool validate(Node *root, long maxi, long mini)
{
    if (!root)
        return true;
    if (root->val >= maxi || root->val <= mini)
        return false;
    return validate(root->left, root->val, mini) && validate(root->right, maxi, root->val);
}
bool isValidBST(Node *root)
{
    return validate(root, LONG_MAX, LONG_MIN);
}

int main()
{

    return 0;
}
