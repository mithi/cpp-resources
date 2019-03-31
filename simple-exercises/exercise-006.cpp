// You are given a perfect binary tree where all leaves are on the same level,
// and every parent has two children.
// Populate each next pointer to point to its next right node.
// If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

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
    /*

         1 > NULL
      /    \
     a   >   b > NULL
    / \    /  \
   c > d > e > f > NULL

     */
    Node* connect(Node* root) {
        if (root == NULL || root->left == NULL) {
            return root;
        }
        root->left->next = root->right; // c > d
        if (root->next != NULL) {
            root->right->next = root->next->left; // d > e
        }

        connect(root->left);
        connect(root->right);
        return root;
    }
};
