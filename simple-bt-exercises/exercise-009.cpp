// level order traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result = {};
        vector<int>level = {};

        queue<TreeNode*> currentlevel;
        queue<TreeNode*> nextlevel;

        currentlevel.push(root);

        TreeNode* pointer;

        while (true) {
            while (currentlevel.empty() == false) {
                pointer = currentlevel.front();
                currentlevel.pop();
                if (pointer != NULL) {
                    level.push_back(pointer->val);
                    nextlevel.push(pointer->left);
                    nextlevel.push(pointer->right);
                }
            }
            if (level.empty() == true) { break; }
            result.push_back(level);
            currentlevel = nextlevel;
            nextlevel = {};
            level = {};
        }
        return result;
    }
};
