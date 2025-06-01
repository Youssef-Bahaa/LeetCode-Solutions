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
    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (q.size()) {
            int sz = q.size();
            vector<TreeNode*> oddlevelnodes;

            while (sz--) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                
                oddlevelnodes.push_back(temp);
            }
            if (level % 2 == 0){level++;
                continue;
            }
            level++;
            
            for(int i = 0 ; i < oddlevelnodes.size() /2; i++)
                swap(oddlevelnodes[i]->val , oddlevelnodes[oddlevelnodes.size() - i -1]->val);
            
            
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        bfs(root);
        return root;
    }
};