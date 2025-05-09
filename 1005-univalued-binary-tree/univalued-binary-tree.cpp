/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    int nodes = 0 ;
    void dfs(TreeNode* root){
        if(!root)return;
        sum += root->val;
        nodes++;
        dfs(root->left);
        dfs(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        dfs(root);
        if(root->val * nodes !=sum)
            return false;
        return true;
    }
};