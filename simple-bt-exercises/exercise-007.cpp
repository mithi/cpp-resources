/**
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Account for "non-perfect" binary trees.
Initially, all next pointers are set to NULL.

- Make sure the right part of the tree is complete before tackling the left part,
- When middle nodes are missing,
- We need completed next information on the right part of the tree for correctness.

**/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* next(Node* root) {
        if (root == NULL) { return NULL; }
        if (root->left != NULL) {
            return root->left;
        }
        if (root->right != NULL) {
            return root->right;
        }
        return next(root->next);
    }

    Node* connect(Node* root) {
        if (root == NULL) { return root; }
        if (root->left != NULL) {
            if (root->right != NULL) {
                root->left->next = root->right;
            } else {
                root->left->next = next(root->next);
            }
        }
        if (root->right != NULL) {
            root->right->next = next(root->next);
        }

        connect(root->right);
        connect(root->left);
        return root;
    }
};
