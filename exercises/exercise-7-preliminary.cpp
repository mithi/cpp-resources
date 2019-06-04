/*
EASY 

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3


*/
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
    void recurse(TreeNode* node, 
                 string s, 
                 vector<string> &v) {

        if (node==NULL) {            
            return;
        }

        string a = s.c_str();
        a.append("->");
        a.append(to_string(node->val));

        recurse(node->left, a, v);
        recurse(node->right, a, v); 
        if (node->left==NULL && node->right==NULL) {
            v.push_back(a);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        
        if(root == NULL) {
            return v;
        }
        
        string s = to_string(root->val);

        if (root->left==NULL && root->right==NULL) {
            v.push_back(s);
            return v;
        }
        
        recurse(root->left, s, v);
        recurse(root->right, s, v);
        return v;
    }
};
