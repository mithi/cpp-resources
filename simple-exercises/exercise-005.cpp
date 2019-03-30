//Given inorder and preorder traversal of a tree, construct the binary tree.
// You may assume that duplicates do not exist in the tree.
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
    // end index is excluded in search
    TreeNode* _buildtree(unordered_map<int, int>& inordermap, int istart, int iend,
                         vector<int>& pvector, int pstart, int pend) {

        //         (left) (root) (right)
        // iorder [3, 4, 6] 8 [9, 10, 11]
        //       (root) (left)    (right)
        // porder 8 [3, 6, 4] [9, 11, 10]

        if (istart>=iend || pstart>=pend) { return NULL; }

        // Make node
        int value = pvector[pstart];
        TreeNode* root = new TreeNode(value);

        // Find where value is located in inorder vector
        int i = inordermap[value];
        // find index separating left and right subtree
        // of postorder vector i.e.
        // m = start + (size of left subtree)
        int m = pstart + 1 + (i - istart);

        root->left = _buildtree(inordermap, istart, i,
                                pvector, pstart + 1, m);
        root->right = _buildtree(inordermap, i + 1, iend,
                                 pvector, m, pend);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // assert postorder.size() == inorder.size()
        int n = preorder.size();
        // map value to index of inorder vector
        unordered_map<int, int> inordermap;
        for (int i = 0; i < n; i++) {
            inordermap[inorder[i]] = i;
        }
        return _buildtree(inordermap, 0, n, preorder, 0, n);
    }
};
