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
    vector<int> tvr;
    void inorder(TreeNode* root ){
        if(!root)return;
        inorder(root->left);
        tvr.push_back(root->val);
        inorder(root->right);
    }
    void recover(TreeNode* root,int& i ){
        if(!root)return;
        recover(root->left,i);
        root->val = tvr[i++];
        recover(root->right,i);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(tvr.begin(),tvr.end());
        for(auto i :tvr)cout<<i<<" ";
        int l = 0 ;
        recover(root,l);
        
    }
};