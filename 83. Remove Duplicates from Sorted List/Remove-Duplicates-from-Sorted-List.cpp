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
        
        for(ListNode* cur=head; cur&& cur->next ;){
            if(cur->val==cur->next->val){
                ListNode* temp=cur->next;
                cur->next=temp->next;
                
                delete temp;
            }
            else
            cur=cur->next;
        }
        return head;

    }
};