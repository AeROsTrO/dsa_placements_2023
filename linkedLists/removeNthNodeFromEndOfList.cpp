#include <bits/stdc++.h>
using namespace std;
// problem description here
//  Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//brute force
 ListNode* removeNthFromEnd(ListNode* head, int n) {
  int ct=0;
        if(head->next==NULL and n==1)return NULL;
        ListNode* dup=head, *one=head;
        while(dup){
            ++ct;
            dup=dup->next;
        }
        if(n==ct)return head->next;
        n=ct-n;
        
        while(one and n-->1){
            one=one->next;
}
        // cout<<head->val;
        dup=one;
        if(dup->next){
            dup->next=dup->next->next;
        }
        return head;
 }
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // let m be the total number of nodes in the linked list
    // nth node from the end means (m-n+1)th node from the start
    if (!head)
        return NULL;
    ListNode *fast = head, *slow = head;
    // fast will have travelled n nodes
    for (int i = 0; i < n; i++)
        fast = fast->next;
    if (!fast)
        return head->next; // this happens when n==m, covered all m nodes,so removing mth node from end means first node, return head->next;
    // now traversing `fast` till the end of the list would make it travel m-n nodes
    // so along with that if we keep a `slow` pointer(which is initially at the head of the linked list) that would travel as many places as it does, we would cover m-n nodes, at this point the `slow` pointer is (m-n)th node from the beginning- before the node to be removed (m-n+1)th node from the beginning(nth node from the end)
    while (fast->next)
        fast = fast->next, slow = slow->next;
    // now all we have to do is remove the node, we do this by changing the link between this node and node after (m-n+1)th node
    slow->next = slow->next->next;
    return head;
}
int main()
{

    return 0;
}