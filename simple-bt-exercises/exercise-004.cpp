// BACKTRACKING
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum
// equals the given sum.
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
    void _rpathsum(TreeNode* root,
                   int sum,
                   vector<int>& path,
                   vector<vector<int>>& allpaths) {

        if (root == NULL) {return;}

        path.push_back(root->val);

        // if node is a leaf, we've completed a path
        // save it path if the sum of the paths is the given sum
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            allpaths.push_back(path);
        }

        _rpathsum(root->left, sum - root->val, path, allpaths);
        _rpathsum(root->right, sum - root->val, path, allpaths);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector<int>> allpaths;
        vector<int> path;

        _rpathsum(root, sum, path, allpaths);
        return allpaths;
    }
};
