/*

HARD 

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

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
    void recurse(TreeNode* node, int& current, int& unfinished) {
        
        if (node->left == NULL && node->right == NULL) {
            current = current > node->val ? current : node->val;
            unfinished = node->val;
            return;
        }
        
        int left = INT_MIN;
        int right = INT_MIN;
        int nodeleft = node->val;
        int noderight = node->val;
        int bigpath = node->val;
        
        if (node->left != NULL) {
            recurse(node->left, current, unfinished);
            left = unfinished;
            nodeleft = left + node->val;
        } 
        
        if (node->right != NULL) {
            recurse(node->right, current, unfinished);
            right = unfinished;
            noderight = right + node->val;
        }
        
        if (node->right != NULL && node->left !=NULL) {
            bigpath = node->val + left + right;
        }
        
        current = current > left ? current : left;
        current = current > right ? current : right;
        current = current > nodeleft ? current : nodeleft;
        current = current > noderight ? current : noderight;
        current = current > bigpath ? current : bigpath;
        
        unfinished = node->val > nodeleft ? node->val : nodeleft;
        unfinished = unfinished > noderight ? unfinished : noderight; 
        return;
    }
    
    int maxPathSum(TreeNode* root) {
        
        if (root->left==NULL && root->right==NULL) {
            return root->val;    
        }
        
        int unfinished = 0;
        int current = root->val;
  
        recurse(root, current, unfinished);      
        return current > unfinished ? current : unfinished;
    }
};
