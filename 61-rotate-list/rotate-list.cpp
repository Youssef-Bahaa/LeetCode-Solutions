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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head or !k)
            return head;

        int sz = 1;
        ListNode *cur = head, *tail = head;

        while (tail->next) {
            tail = tail->next;
            sz++;
        }

        k = k % sz;
        if (!k)
            return head;

        for (int i = 0; i < sz - k - 1; i++)
            cur = cur->next;

        tail->next = head;
        head = cur->next;
        cur->next = nullptr;

        return head;
    }
};