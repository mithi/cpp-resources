//https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
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
    TreeNode* _buildtree(vector<int>& in_vector,
                    vector<int>& post_vector,
                    int in_start,
                    int in_end,
                    int* post_index) {

        if (in_start > in_end || post_index < 0) { return NULL; }

        // create node
        int value = post_vector[*post_index];
        TreeNode* root = new TreeNode(value);
        // decrement post_index each time a node is created
        (*post_index)--;

        // if node has no children, return it
        if (in_start == in_end) {
            cout << root->val << " ";
            return root;
        }

        // in_index, where in the inorder vector the `value` is
        int i = search(in_vector, in_start, in_end, value);

        root->right = _buildtree(in_vector, post_vector, i + 1, in_end, post_index);
        root->left = _buildtree(in_vector, post_vector, in_start, i - 1, post_index);
        return root;
    }

    // Assumes that value is in v & inbetween start and end
    int search(vector<int>& v, int start, int end, int value) {
        for(int i=start; i<=end; i++) {
            if (v[i] == value) { return i; }
        }
        return -1; // did not find anything
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // assert postorder.size() == inorder.size()
        int n = postorder.size() - 1;
        return _buildtree(inorder, postorder, 0, n, &n);
    }
};
