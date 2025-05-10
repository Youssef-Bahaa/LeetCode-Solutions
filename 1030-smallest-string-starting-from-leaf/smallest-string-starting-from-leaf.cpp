/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    string mini = "";
    int cnt = 0;

    bool is_leaf(TreeNode* root) { return !root->left and !root->right; }

    void dfs(TreeNode* root, string s) {

        if (is_leaf(root)) {
            string cur = char(root->val + 'a') + s;
            if (!cnt) {
                cnt++;
                mini = cur;
                return;
            }
            mini = min(cur, mini);
        }

        if (root->left)
            dfs(root->left, char(root->val + 'a') + s);

        if (root->right)
            dfs(root->right, char(root->val + 'a') + s);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return mini;
    }
};