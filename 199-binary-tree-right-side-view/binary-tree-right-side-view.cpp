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
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            TreeNode* last = nullptr;
            while(sz--){
                last = q.front();
                q.pop();
                if(last->left)q.push(last->left);
                if(last->right)q.push(last->right);
            }
            ans.push_back(last->val);
        }

    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        bfs(root);
        return ans;
    }
};