//Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* _buildtree(vector<int>& ivector, int istart, int iend,
                         vector<int>& pvector, int pstart, int pend) {

        //         (left) (root) (right)
        // iorder [3, 4, 6] 8 [9, 10, 11]
        //        (left)    (right)    (root)
        // porder [3, 6, 4] [9, 11, 10] 8

        // We found nothing
        if (istart>=iend || pstart>=pend) { return NULL; }

        // Make node
        int value = pvector[pend - 1];
        TreeNode* root = new TreeNode(value);

        // Find where value is located in inorder vector
        int i = search(ivector, istart, iend, value);
        // find index separating left and right subtree
        // of postorder vector i.e.
        // m = start + (size of left subtree)
        int m = pstart + (i - istart);

        root->left = _buildtree(ivector, istart, i,
                                pvector, pstart, m);
        root->right = _buildtree(ivector, i + 1, iend,
                                 pvector, m, pend - 1);
        return root;
    }

    // Assumes that value is in v & inbetween start and end
    int search(vector<int>& v, int start, int end, int value) {
        for(int i=start; i<end; i++) {
            if (v[i] == value) { return i; }
        }
        return -1; // did not find anything
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // assert postorder.size() == inorder.size()
        int n = postorder.size();
        return _buildtree(inorder, 0, n, postorder, 0, n);
    }
};
