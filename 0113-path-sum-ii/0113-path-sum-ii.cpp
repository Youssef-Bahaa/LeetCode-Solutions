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
    vector<vector<int>> ans;
    vector<int> path;
    bool isleaf(TreeNode* root) { return !root->left and !root->right; }
    void dfs(TreeNode* root, int targetsum, int cursum, vector<int> cpath) {
        if (!root)
            return;
        cursum += root->val;
        cpath.push_back(root->val);
        if (isleaf(root) and targetsum == cursum)
            ans.push_back(cpath);

        dfs(root->left, targetsum, cursum, cpath);
        dfs(root->right, targetsum, cursum, cpath);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, 0, {});
        return ans;
    }
};