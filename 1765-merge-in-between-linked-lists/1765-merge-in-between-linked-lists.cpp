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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1 , *h , *t;
        int idx = 0;
        while(temp){
            if(idx + 1 == a)h = temp;
            if(idx == b)t = temp->next;
            idx++;
            temp = temp->next;
        }

        ListNode* ht = h->next , *tt = t;
        while(ht != tt){
            ListNode* tempo = ht->next;
            delete ht;
            ht = tempo;
        }
        h->next = list2;
        ListNode* t2 = list2;
        while(t2->next)t2 = t2->next;
        t2->next = t;
        return list1;
    }
};