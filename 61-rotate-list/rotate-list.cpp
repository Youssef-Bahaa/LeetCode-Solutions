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
        if(!k or !head)return head;

        int rot = 0;
        int size = 0;
        deque<ListNode*> dq;
        while(head){
            dq.push_back(head);
            head = head->next;
            size++;
        }
        rot = k % size;

        while(rot--){
            dq.back()->next = dq.front();
            dq.push_front(dq.back());
            dq.pop_back();
            dq.back()->next = nullptr;
        }

        return dq.front();

    }
};