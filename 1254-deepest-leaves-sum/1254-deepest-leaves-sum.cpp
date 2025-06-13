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
    int maxi = 0;

    int depth(TreeNode* root) {
        if (!root)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    bool isleaf(TreeNode* root) {
        return root and !root->right and !root->left;
    }

    void dfs(TreeNode* root, int cur, int maxdepth) {
        if (!root)
            return;
        if (isleaf(root) and cur == maxdepth)
            maxi += root->val;

        dfs(root->left, cur + 1, maxdepth);
        dfs(root->right, cur + 1, maxdepth);
    }

    int deepestLeavesSum(TreeNode* root) {
        int maxdepth = depth(root);
        dfs(root, 1, maxdepth);
        return maxi;
    }
};