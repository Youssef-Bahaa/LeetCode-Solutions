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
    TreeNode* find_parent(TreeNode* cur, int val) {
        if (!cur or cur->val == val)
            return 0;
        if (cur->left)
            if (cur->left->val == val)
                return cur;

        if (cur->right)
            if (cur->right->val == val)
                return cur;

        TreeNode* leftparent = find_parent(cur->left, val);
        ;
        if (leftparent)
            return leftparent;

        return find_parent(cur->right, val);
    }

    int depth(TreeNode* c, int value, int cur = 0) {

        if (!c)
            return 0;
        if (c->val == value)
            return cur;

        int l = depth(c->left, value, cur + 1);
        if (l)
            return l;

        return depth(c->right, value, cur + 1);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        if (depth(root, x) != depth(root, y))
            return false;
        if (find_parent(root, x) == find_parent(root, y))
            return false;
        return true;
    }
};