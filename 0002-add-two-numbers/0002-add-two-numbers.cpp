/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* cur=dummy;
        int carry=0;
        while(l1 or l2 or carry){
            int v1,v2;
            if(!l1)v1=0;
            else v1=l1->val;
            if(!l2)v2=0;
            else v2=l2->val;

            int v=v1+v2+carry;
            carry=v/10;
            v=v%10;
            cur->next=new ListNode(v);
            cur=cur->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }

    return dummy->next;

    }

};