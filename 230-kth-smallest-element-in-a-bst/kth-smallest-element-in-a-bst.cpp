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
    vector<int> temp;
    void dfs(TreeNode* root){
        if(!root)return;
        temp.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        sort(temp.begin() , temp.end());
        return temp[k - 1];
    }
};