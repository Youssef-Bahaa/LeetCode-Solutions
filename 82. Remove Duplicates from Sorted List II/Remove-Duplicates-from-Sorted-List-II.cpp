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
        ListNode* prev = dummy;
        while (head) {
            if (head->next and head->val == head->next->val) {
                int dp = head->val;
                while (head and head->val == dp)
                    head = head->next;

                prev->next = head;
            } else {
                prev = head;
                head = head->next;
            }
        }

        return dummy->next;
    }
};