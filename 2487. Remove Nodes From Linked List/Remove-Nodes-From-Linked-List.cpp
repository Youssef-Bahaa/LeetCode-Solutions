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
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        vector<int> v;
        ListNode* temp = head;
        while (head) {
            if (st.size() == 0) {
                st.push(head->val);
                head = head->next;
                continue;
            }
            while (st.size() and head->val > st.top()) {
                st.pop();
            }
            st.push(head->val);
            head = head->next;
        }
        while (st.size()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        head = temp;
        for (int i = 0; i < v.size(); i++) {
            if (i == v.size() - 1)
                head->next = nullptr;
            head->val = v[i];
            if (head->next)
                head = head->next;
        }
        return temp;
    }
};