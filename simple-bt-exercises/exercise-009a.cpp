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
    void build(TreeNode *root, int level_id, vector<vector<int>> &result) {

        if (root == NULL) { return; }
        // each vector inside the result vector
        // contains the nodes in a particular level
        // the level of this vector is the index of the result vector
        // IE result[0] = {root->val}
        // result[1] = {root->left->val, root->right->val}
        // and so on

        // if the size of the of the level_id
        // then this is the start of a new level
        // so we have to push a new empty vector where
        // we will push the nodes at that level
        if (result.size() == level_id) {
            result.push_back(vector<int>());
        }

        if (root != NULL) {
            result[level_id].push_back(root->val);
        }

        build(root->left, level_id + 1, result);
        build(root->right, level_id + 1, result);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result = {};
        build(root, 0, result);
        return result;
    }
};
