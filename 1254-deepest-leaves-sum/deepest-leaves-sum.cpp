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
    int sum = 0;
    int maxi = INT_MIN;

    bool isleaf(TreeNode* root) {
        return root and !root->right and !root->left;
    }

    void dfs(TreeNode* root, int cur) {
        if (!root)
            return;

        if (isleaf(root) and cur == maxi)
            sum += root->val;

        if (isleaf(root) and cur > maxi){
            sum = root->val;
            maxi = cur;
        }

        dfs(root->left, cur + 1);
        dfs(root->right, cur + 1);
    }

    int deepestLeavesSum(TreeNode* root) {

        dfs(root, 0);
        return sum;
    }
};