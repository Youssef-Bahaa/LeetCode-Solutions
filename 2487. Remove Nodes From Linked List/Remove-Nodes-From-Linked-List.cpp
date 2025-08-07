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
        stack<int> st;
        vector<int> v;
        ListNode *prev = 0, *temp = 0;
        while (h) {
            temp = h->next;
            h->next = prev;
            prev = h;
            h = temp;
        }
        h = prev;
        while (h) {
            if (!st.size() or (st.size() and h->val >= st.top()))
                st.push(h->val);
            h = h->next;
        }
        while (st.size()) {
            v.push_back(st.top());
            st.pop();
        }

        h = prev;
        for (int i = 0; i < v.size(); i++) {
            if (i == v.size() - 1)
                h->next = nullptr;
            h->val = v[i];
            if (h->next)
                h = h->next;
        }
        return prev;
    }
};