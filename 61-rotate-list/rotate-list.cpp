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
        if(!head or !k)return head;
        ListNode* temp = head;
        
        int sz = 0 ;
        int rot = 0;

        while(temp){
            sz++;
            temp = temp ->next;
        }


        rot = k % sz;

        while(rot--){
            ListNode* tail = head;
            ListNode* newTail = head;

            while(tail->next){
                tail = tail->next;
            }

            while(newTail->next != tail){
                newTail = newTail->next;
            }
            
            tail->next = head;
            newTail->next = nullptr;
            head = tail;
            
        }

        return head;

    }
};