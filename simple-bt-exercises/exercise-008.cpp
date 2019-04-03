/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// we're doing postorder traversal (//left right root)
// bottom's up approach, looking for the answer below first
// bubbling up (propagating the answer up)
class Solution {
public:
    TreeNode* LCA(TreeNode* x, TreeNode* p, TreeNode* q) {
        if(x==NULL || x==p || x==q) { return x; }
        TreeNode *left = LCA(r->left, p, q);
        TreeNode *right = LCA(r->right, p, q);
        if (left && right) { return x; }
        // if left is not null return it
        // if left is null return right it's in it
        // if not return NULL
        return left? left : right;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL || root==p || root==q) { return root; }

        // find if LCA is on the left or right
        TreeNode* left_result = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_result = lowestCommonAncestor(root->right, p, q);

        bool has_left = left_result != NULL;
        bool has_right = right_result != NULL;

        if (has_left && has_right) {
            // if it found the one of the tree nodes in the left
            // and one of the tree nodes in the right
            // then the LCA must be the root
            return root;
        }

        if (has_left) {
            // if both tree nodes are in the root's left
            // then the LCA must be the left's result
            // either p or q whichever is on top
            return left_result;
        }

        if (has_right) {
            // if both tree nodes are in the root's right
            // then the LCA must be the right's result (either p or q)
            // either p or q whichever is on top
            return right_result;
        }

        return NULL;
    }
};
