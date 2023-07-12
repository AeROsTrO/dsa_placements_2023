#include <bits/stdc++.h>
using namespace std;
// problem description here
//  You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//  Merge all the linked-lists into one sorted linked-list and return it.

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeMe(ListNode *l1, ListNode *l2)
{
    ListNode *ptr = new ListNode(0), *curr = ptr;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    if (l1)
    {
        curr->next = l1;
        curr = curr->next;
    }
    if (l2)
    {
        curr->next = l2;
        curr = curr->next;
    }
    return ptr->next;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int k = lists.size();
    if (lists.empty())
        return NULL;
    ListNode *l = lists[0];
    for (int i = 1; i < k; i++)
    {
        l = mergeMe(l, lists[i]);
    }
    return l;
}
int main()
{

    return 0;
}