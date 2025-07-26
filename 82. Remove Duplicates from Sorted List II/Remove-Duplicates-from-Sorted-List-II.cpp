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

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_set <int> s;
        while(head and head->next){
            if(head->val == head->next->val){
                head->next = head->next->next;
                s.insert(head->val);
            }
            else
                head = head->next;
        }
        ListNode* cur = dummy;
        while(cur and cur->next){
            if(s.count(cur->next->val)){
                cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};