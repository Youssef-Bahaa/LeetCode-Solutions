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
    ListNode* doubleIt(ListNode* head) {
        if(head->val > 4){
            ListNode* temp = new ListNode(0);
            temp->next = head;
            head = temp;
        }
        ListNode* temp = head;
        while(head){
            head->val = (head->val * 2) % 10;
            if(head->next and head->next->val > 4)head->val++;
            head = head->next;
        }
        return temp;
    }
};