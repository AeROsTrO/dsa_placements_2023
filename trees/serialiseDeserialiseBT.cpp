#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;
//problem description here
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

string serialise(Node* root){
    string res="";
    queue<Node*>q;
    q.push(root);
    while(q.size()){
        int n=q.size();
        for(int i=0; i<n; i++){
            root=q.front();
            q.pop();
            if(root==NULL)res+="# ";
            else {res+=to_string(root->val)+" ";
            q.push(root->left);
            q.push(root->right);}
        }
    }
    return res;
}
Node* deSerialise(string &s){
    int i=0;
    int n=s.length();
    queue<Node*>q;
    vector<string>v;//to store the values of string
    string val="";
    for(int i=0; i<s.length(); i++){
        if(s[i]!=' ')val+=s[i];
        else{
            v.push_back(val);
            val="";
        }
    }
    Node* root= new Node(stoi(v[0]));
    queue<Node*>q;
    q.push(root);
    i++;
    while(q.size()){
        Node* curr=q.front();
        q.pop();
        if(v[i]=="#")curr->left=NULL;
        else{
            Node* lnode=new Node(stoi(v[i]));
            curr->left=lnode;
            q.push(lnode);
        }
        i++;
        if(i<n){
            if(v[i]=="#")curr->right=NULL;
            else{
                Node* rnode=new Node(stoi(v[i]));
                curr->right=rnode;
                q.push(rnode);
            }
        }else break;
        i++;
    }return root;

}

int main()
{
 
    return 0;
}