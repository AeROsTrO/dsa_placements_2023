#include <bits/stdc++.h>
using namespace std;
//problem description here
struct ListNode{
    int val;
    ListNode* next;
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
   ListNode* head=new ListNode(), *ptr=head;
        while(l1 && l2){
            if(l1->val<=l2->val){
                ptr->next=l1;
                l1=l1->next;
            }else{
                ptr->next=l2;
                l2=l2->next;
            }
            ptr=ptr->next;
        }
       if(l1)ptr->next=l1,ptr=ptr->next;
       if(l2)ptr->next=l2, ptr=ptr->next;
        return head->next;
}
int main()
{
 
return 0;
}