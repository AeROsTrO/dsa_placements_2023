#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

struct Node{
    int val;
    Node* next;
    bool flag=false;
    Node(int value){
        val=value;
        next=NULL;
    }
    Node(int value, Node* n){
        next=n;
        val=value;
    }
};
bool brute(Node* head){
    if(!head)return false;
    unordered_set<Node*>s;
    while(head){
        if(s.find(head)!=s.end())return true;
        else s.insert(head);
        head=head->next;
    }
    return false;
}
//or we can also change the structure of the node by adding a flag as the member variable to it to mark it as visited
bool better(Node* head){
    if(!head)return false;
    while(head){
        if(head->flag)return true;
        head->flag=true;
        head=head->next;
    }
    return false;
}
bool opt(Node* head){
    if(!head)return false;
    Node* slow, *fast=head;
    slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)return true;
    }
    return false;
}
int main()
{
 
return 0;
}