#include <bits/stdc++.h>
using namespace std;


struct Node{
    int val; 
    Node* left=NULL, *right=NULL;
    Node(int value){
        val=value;
        left=NULL;
        right=NULL;
    }
};