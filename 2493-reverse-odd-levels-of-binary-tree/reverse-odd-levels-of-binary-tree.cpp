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
    void dfs(TreeNode* root1 , TreeNode* root2,  int level) {
        if(!root1 or !root2)return;
        if(root1->left and (level + 1)%2)swap(root1->left->val ,root2->right->val);
        dfs(root1->left , root2->right, level + 1);
        dfs(root1->right , root2->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root ,root, 0);
        return root;
    }
};