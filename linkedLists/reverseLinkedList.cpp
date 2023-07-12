#include <bits/stdc++.h>
using namespace std;
//problem description here
// Given the head of a singly linked list, reverse the list, and return the reversed list.
struct Node{
    int val;
    Node* next;
    Node(int value){
        val=value;
        next=NULL;
    }
    Node(int value, Node* n){
        next=n;
        val=value;
    }
};
Node* brute(Node*head){
    stack<int>s;
    Node* dup=head;
    while(dup){
        s.push(dup->val);
        dup=dup->next;
    }
    dup=head;
    while(s.size()){
        dup->val=s.top();
        s.pop();
        dup=dup->next;
    }
    return head;
    
}
//O(n) O(1)
Node* reverseList(Node* head){
    Node* prev=NULL;
    while(head){
        Node* newNode=head->next;
        head->next=prev;
        prev=head;
        head=newNode;
    }
    return prev;
}
Node* rev(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead=rev(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}
void printList(Node* head){
    if(!head)return;
    cout<<head->val<<" ";
    printList(head->next);
}
int main()
{
    int n;cin>>n;
    Node* head=new Node(-1), *dup=head;
    for(int i=0; i<n; i++){
        int x;cin>>x;
        dup->next=new Node(x);
        dup=dup->next;
    }
    head=head->next;
    // head=brute(head);
    head=rev(head);
    printList(head);
    return 0;
}