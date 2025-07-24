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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next )return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        int idx = 0;
        while(head->next){
            idx++;
            if(idx % 2 == 1 and !head->next->next)break;
            ListNode* temp = head->next;
            head->next = head->next->next;
            head = temp;
        }
        head->next = even;
        return odd;
    }
};