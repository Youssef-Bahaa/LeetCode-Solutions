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
        while (h) {
            while (st.size() and h->val > st.top()->val)
                st.pop();
            st.push(h);
            h = h->next;
        }

        ListNode* head = nullptr;
        while (st.size()) {
            st.top()->next = head;
            head = st.top();
            st.pop();
        }
        return head;
    }
};