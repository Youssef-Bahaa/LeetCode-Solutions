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
    vector<int> m1,m2,ans;
    void dfs(TreeNode* root1,vector<int>& v){
        if(!root1)return;
        dfs(root1->left ,v);
        v.push_back(root1->val);
        dfs(root1->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1,m1);
        dfs(root2,m2);
        
        int i = 0, j = 0;

        while(i < m1.size() and j < m2.size()){
            if(m1[i] <= m2[j] )
                ans.push_back(m1[i++]);
            
            else 
                ans.push_back(m2[j++]);
            
        }

        while(i < m1.size())ans.push_back(m1[i++]);
        while(j < m2.size())ans.push_back(m2[j++]);

        return ans;
    }
};