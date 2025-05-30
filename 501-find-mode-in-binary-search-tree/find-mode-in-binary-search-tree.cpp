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
    vector<int> ans;
    int val =INT_MIN , freq = 0 , maxFreq = 0 ;

    void inorder(TreeNode* root){
        if(!root)
            return; 

        inorder(root->left);

        if(val == root->val)
            freq++;
        else{
            freq = 1;
            val = root->val;
        }
        if(freq > maxFreq){
            maxFreq = freq;
            ans= {root->val};
        }
        else if(freq == maxFreq)
            ans.push_back(root->val);

        inorder(root->right);
        
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;

    }
};