#include <bits/stdc++.h>
using namespace std;
//problem description here
// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

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
Node* reverseList(Node* head){
    Node* prev=NULL;
    while(head){
        Node* newHead=head->next;
        head->next=prev;
        prev=head;
        head=newHead;
    }
    return prev;
}

Node* middle(Node* head){
    Node* sl=head, *fa=head;
    Node* tmp=head;
    while(fa&& fa->next){
        tmp=sl;
        sl=sl->next;
        fa=fa->next->next; 
    }
    tmp->next=NULL;
    return sl;
}
void printList(Node* head);
void solve(Node* head){
    //find the middle of the node
    //why? to make a left list n right
    //reverse the right
    //then alternate intertwine them
    //example: 1 2 3 4 5 6
    //left list: 1 2 3
    //right list(after reversing): 6 5 4
    //after intertwining: 1->6->2->5->3->4
    // if(!head || !head->next)return;
    Node* l=head->next;
    Node* r=middle(head);
    r=reverseList(r);

    int i=0;
    while(l!=r){
        if(i&1){
            //odd count
            head->next=l;
            l=l->next;
        }
        else{
            head->next=r;
            r=r->next;
        }
        ++i;
        head=head->next;
    }
   
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
    solve(head);
    printList(head);
    return 0;
}