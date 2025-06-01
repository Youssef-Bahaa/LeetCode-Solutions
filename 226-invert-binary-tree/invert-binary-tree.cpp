class Solution {
public:
    void run(TreeNode* root) {
        if (!root) return;
        swap(root->left, root->right);
        run(root->left);
        run(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        run(root);
        return root;
    }
};
