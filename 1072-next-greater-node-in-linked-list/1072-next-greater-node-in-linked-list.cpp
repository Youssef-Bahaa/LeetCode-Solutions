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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        while (head) {
            ListNode* inner = head;
            bool has_ans = false;

            while (inner) {
                if (inner->val > head->val) {
                    has_ans = true;
                    ans.push_back(inner->val);
                    break;
                }
                inner = inner->next;
            }

            if (!has_ans)
                ans.push_back(0);

            head = head->next;
        }
        return ans;
    }
};