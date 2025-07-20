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
        int idx = 0;
        ListNode *temp = list1, *h1, *t1;
        while (temp) {
            if (idx + 1 == a)
                h1 = temp;
            if (idx == b)
                t1 = temp->next;

            if (idx >= a and idx <= b) {
                ListNode* tmp = temp->next;
                delete temp;
                temp = tmp;
                idx++;
                continue;
            }
            idx++;
            temp = temp->next;
        }

        h1->next = list2;

        while (list2->next)
            list2 = list2->next;

        list2->next = t1;

        return list1;
    }
};