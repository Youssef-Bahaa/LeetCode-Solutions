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
        if (!head or !head->next or !head->next->next)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* eventemp = even;

        while (eventemp and eventemp->next) {
            odd->next = odd->next->next;
            odd = odd->next;
            eventemp->next = eventemp->next->next;
            eventemp = eventemp->next;
        }
        odd->next = even;
        return head;
    }
};