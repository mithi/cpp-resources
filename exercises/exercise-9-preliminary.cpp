/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.


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
    int recurse(TreeNode* node, 
                 string current,
                 int sum) {
        
        current.append(to_string(node->val)); 
        
        if(node->left==NULL && node->right==NULL) {
            return sum + stoi(current);
        }
        
        int sum_left = 0;
        
        if(node->left!=NULL) {
            sum_left = recurse(node->left, current, sum);
        }
        
        int sum_right = 0;
        
        if(node->right!=NULL) {
            sum_right = recurse(node->right, current, sum);
        }
        
        return sum_left + sum_right; 
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        return recurse(root, "", 0);
    }
};
