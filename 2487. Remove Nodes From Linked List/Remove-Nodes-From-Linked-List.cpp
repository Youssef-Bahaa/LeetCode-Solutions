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
    ListNode* removeNodes(ListNode* h) {
        stack<ListNode*> st;
        ListNode *prev = 0, *temp = 0;
        while (h) {
            temp = h->next;
            h->next = prev;
            prev = h;
            h = temp;
        }
        h = prev;
        while (h) {
            if (!st.size() or (st.size() and h->val >= st.top()->val))
                st.push(h);
            h = h->next;
        }

        h = st.top();
        while (st.size()) {
            ListNode* cur = st.top();
            st.pop();
            if (st.size())
                cur->next = st.top();
            else
                cur->next = nullptr;
        }
        return h;
    }
};