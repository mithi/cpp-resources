// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // refactored
    bool check_children(TreeNode* x, TreeNode* y) {
        if (x == NULL && y == NULL) { return true; }
        if (x == NULL || y == NULL) { return false; }
        if (x->val == y->val) {
            return check_children(x->left, y->right) && check_children(x->right, y->left);
        }
        return false;
    }

    // initial / deprecated
    bool old_check_children(TreeNode* x, TreeNode* y) {
        if (x == NULL && y == NULL) { return true; }
        if (x != NULL && y == NULL) { return false; }
        if (x == NULL && y != NULL) { return false; }
        if (x->val != y->val) { return false; }

        if (!check_children(x->left, y->right)) {
            return false;
        }

        if(!check_children(x->right, y->left)) {
            return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check_children(root, root);
    }
};
