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
    vector<TreeNode*> s;
    int sum(TreeNode* root){
        if(!root)return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        s.push_back(root);
        inorder(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int v = sum(root);
        TreeNode* temp = root;
        inorder(temp);
        for(auto i : s){
            int bf = i->val;
            i->val = v;
            v -= bf;
        }
        return root;
    }
};